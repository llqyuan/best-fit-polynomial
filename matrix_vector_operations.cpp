#include "matrix_vector_operations.h"
#include <new>
#include <iostream>

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


Matrix * LinearAlgebraObject :: transpose(Matrix * m) {
    return nullptr;
}

Vector * LinearAlgebraObject :: matrix_vector_multiply(Matrix * m, Vector * v) {
    return nullptr;
}

Matrix * LinearAlgebraObject :: matrix_matrix_multiply(Matrix * m1, Matrix * m2) {
    return nullptr;
}
