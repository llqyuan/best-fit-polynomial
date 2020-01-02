#include "linear_algebra_objects.h"
#include "within.h"
#include <new>
#include <cassert>


using namespace std;


Matrix :: Matrix(int rows, int cols) 
{
    float * arr = new float[rows * cols];
    num_rows = rows;
    num_cols = cols;
    vals = arr;
}


Matrix :: ~Matrix() 
{
    delete[] vals;
}


float Matrix :: get_matrix_entry(int row, int col) {
    return this->vals[row * this->num_cols + col];
}


MathVector :: MathVector(int use_len) 
{
    float * arr = new float[use_len];
    len = use_len;
    vals = arr;
}


MathVector :: ~MathVector() 
{
    delete[] vals;
}


LinearAlgebraObject :: LinearAlgebraObject() {}


LinearAlgebraObject :: ~LinearAlgebraObject() {}


MathVector * LinearAlgebraObject :: ith_column_as_vector(
    Matrix * m, int i) 
{
    MathVector * ith_column = new MathVector(m->num_rows);
    for (int row = 0; row < m->num_rows; ++row) {
        *(ith_column->vals + row) = m->get_matrix_entry(row, i);
    }
    return ith_column;
}


void LinearAlgebraObject :: map_vector_to_ith_column(
    Matrix * m, MathVector * v, int i) 
{
    assert(m->num_rows == v->len);
    for (int row = 0; row < m->num_rows; ++row) {
        (m->vals)[row * m->num_cols + i] = (v->vals)[row];
    }
}


Matrix * LinearAlgebraObject :: transpose(Matrix * m) 
{
    Matrix * t = new Matrix(m->num_cols, m->num_rows);
    for (int rownum = 0; rownum < m->num_rows; ++rownum) {
        for (int colnum = 0; colnum < m->num_cols; ++colnum) {
            *(t->vals + colnum * t->num_cols + rownum) =
                m->get_matrix_entry(rownum, colnum);
        }
    }
    return t;
}

MathVector * LinearAlgebraObject :: matrix_vector_multiply(
    Matrix * m, MathVector * v) 
{
    assert(v->len == m->num_cols);
    const int newlen = m->num_rows;
    MathVector * newvec = new MathVector(newlen);

    for (int i = 0; i < newlen; ++i) {
        float ith_entry = 0;
        for (int j = 0; j < m->num_cols; ++j) {
            ith_entry += *(v->vals + j) * m->get_matrix_entry(i, j);
        }
        *(newvec->vals + i) = ith_entry;
    }
    return newvec;
}

Matrix * LinearAlgebraObject :: matrix_matrix_multiply(
    Matrix * m1, Matrix * m2) 
{
    assert(m1->num_cols == m2->num_rows);
    const int new_rowlen = m1->num_rows;
    const int new_collen = m2->num_cols;
    Matrix * newmat = new Matrix(new_rowlen, new_collen);

    for (int col = 0; col < new_collen; ++col) {
        MathVector * m2_column = this->ith_column_as_vector(m2, col);
        MathVector * result_column = this->matrix_vector_multiply(
            m1, m2_column);
        this->map_vector_to_ith_column(newmat, result_column, col);
        delete m2_column;
        delete result_column;
    }
    return newmat;
}
