#include "reducing.h"
#include "within.h"
#include <cassert>


using namespace std;


Reducing :: Reducing() {}


Reducing :: ~Reducing() {}


void Reducing :: reduce(Matrix * m, MathVector * v) 
{
    assert(m->num_rows == v->len);

    int row_of_leading_one = 0;
    int col_of_leading_one = 0;

    while (row_of_leading_one < m->num_rows && 
           col_of_leading_one < m->num_cols) 
    {
        bool leading_one_exists = this->reduce_column(
            m, v, row_of_leading_one, col_of_leading_one);
        col_of_leading_one += 1;
        if (leading_one_exists) {
            row_of_leading_one += 1;
        }
    }
}


int Reducing :: row_of_first_nonzero_entry(
    Matrix * m, int row, int col) 
{
    int find_nonzero_row = row;
    while (find_nonzero_row < m->num_rows) {
        if (!within(m->get_matrix_entry(find_nonzero_row, col), 0)) {
            return find_nonzero_row;
        }
        find_nonzero_row += 1;
    }
    return -1;
}


void Reducing :: mult_row_by(Matrix * m, MathVector * v, 
                             int row, float factor)
{
    v->vals[row] *= factor;
    for (int col = 0; col < m->num_cols; ++col) {
        m->vals[row * m->num_cols + col] *= factor;
    }
}


void Reducing :: add_factor_of_row_to(Matrix * m, MathVector * v, 
                                      int add_to, 
                                      int added, 
                                      float factor)
{
    v->vals[add_to] += factor * v->vals[added];
    for (int col = 0; col < m->num_cols; ++col) {
        m->vals[add_to * m->num_cols + col] +=
            factor * m->get_matrix_entry(added, col);
    }
}


void Reducing :: swap_rows(Matrix * m, MathVector * v, 
                           int row_1, int row_2) 
{
    float old_row_1 = v->vals[row_1];
    v->vals[row_1] = v->vals[row_2];
    v->vals[row_2] = old_row_1;
    for (int col = 0; col < m->num_cols; ++col) {
        old_row_1 = m->get_matrix_entry(row_1, col);
        m->vals[row_1 * m->num_cols + col] =
            m->get_matrix_entry(row_2, col);
        m->vals[row_2 * m->num_cols + col] = old_row_1;
    }
}


bool Reducing :: reduce_column(Matrix * m, MathVector * v, 
                               int row, int col) 
{
    const int first_nonzero_row = this->row_of_first_nonzero_entry(
        m, row, col);
    if (first_nonzero_row < 0) {
        return false;
    }

    float row_mult_factor =
        1.0 / m->get_matrix_entry(first_nonzero_row, col);
    this->mult_row_by(m, v, first_nonzero_row, row_mult_factor);

    for (int make_zero_row = 0; 
         make_zero_row < m->num_rows; 
         ++make_zero_row) 
    {
        if (make_zero_row == first_nonzero_row) {
            continue;
        }
        if (!within(m->get_matrix_entry(make_zero_row, col), 0)) {
            float add_factor = - m->get_matrix_entry(
                make_zero_row, col);
            this->add_factor_of_row_to(
                m, v, make_zero_row, first_nonzero_row, add_factor);
        }
    }

    this->swap_rows(m, v, row, first_nonzero_row);
    return true;
}
