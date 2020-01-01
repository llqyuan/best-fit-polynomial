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


void LinearAlgebraObject :: test_will_remove(void) {
    cout << "Called test" << endl;
}


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
    return nullptr;
}

Matrix * LinearAlgebraObject :: matrix_matrix_multiply(Matrix * m1, Matrix * m2) {
    return nullptr;
}
