#include "matrix_vector_operations.h"
#include "within.h"
#include <new>
#include <iostream>
#include <cassert>


using namespace std;


Matrix :: Matrix(int rows, int cols) {
    float * arr = new float[rows * cols];
    num_rows = rows;
    num_cols = cols;
    vals = arr;
}


Matrix :: ~Matrix() {
    delete[] vals;
}


Vector * Matrix :: ith_column_as_vector(int i) {
    Vector * ith_column = new Vector(this->num_rows);
    for (int row = 0; row < this->num_rows; ++row) {
        *(ith_column->vals + row) = this->get_matrix_entry(row, i);
    }
    return ith_column;
}


void Matrix :: map_vector_to_ith_column(Vector * v, int i) {
    assert(this->num_rows == v->len);
    for (int row = 0; row < this->num_rows; ++row) {
        (this->vals)[row * this->num_cols + i] = (v->vals)[row];
    }
}


Vector :: Vector(int use_len) {
    float * arr = new float[use_len];
    len = use_len;
    vals = arr;
}


Vector :: ~Vector() {
    delete[] vals;
}


LinearAlgebraObject :: LinearAlgebraObject() {}


LinearAlgebraObject :: ~LinearAlgebraObject() {}


float Matrix :: get_matrix_entry(int row, int col) {
    return this->vals[row * this->num_cols + col];
}


Matrix * LinearAlgebraObject :: transpose(Matrix * m) {
    Matrix * t = new Matrix(m->num_cols, m->num_rows);
    for (int rownum = 0; rownum < m->num_rows; ++rownum) {
        for (int colnum = 0; colnum < m->num_cols; ++colnum) {
            *(t->vals + colnum * t->num_cols + rownum) =
                m->get_matrix_entry(rownum, colnum);
        }
    }
    return t;
}

Vector * LinearAlgebraObject :: matrix_vector_multiply(Matrix * m, Vector * v) {
    assert(v->len == m->num_cols);
    const int newlen = m->num_rows;
    Vector * newvec = new Vector(newlen);

    for (int i = 0; i < newlen; ++i) {
        float ith_entry = 0;
        for (int j = 0; j < m->num_cols; ++j) {
            ith_entry += *(v->vals + j) * m->get_matrix_entry(i, j);
        }
        *(newvec->vals + i) = ith_entry;
    }
    return newvec;
}

Matrix * LinearAlgebraObject :: matrix_matrix_multiply(Matrix * m1, Matrix * m2) {
    return nullptr;
}
