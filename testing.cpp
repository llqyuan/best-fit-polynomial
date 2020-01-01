#include "within.h"
#include "matrix_vector_operations.h"
#include <iostream>


using namespace std;


void print_matrix(Matrix * m) {
    for (int row = 0; row < m->num_rows; ++row) {
        for (int col = 0; col < m->num_cols; ++col) {
            cout << " " << m->vals[row * m->num_cols + col];
        }
        cout << endl;
    }
}


void print_vector(Vector * v) {
    for (int i = 0; i < v->len; ++i) {
        cout << " " << v->vals[i] << endl;
    }
}



int main(void) {
    // transpose
    cout << "\ntranspose: " << endl;
    Matrix * m = new Matrix(2, 3);
    for (int i = 0; i < 6; ++i) {
        (*(m)).vals[i] = i + 1;
    }
    cout << "Original: " << endl;
    print_matrix(m);
    Matrix * t = m->transpose(m);
    cout << "Transpose: " << endl;
    print_matrix(t);
    delete m;
    delete t;

    // matrix-vector multiplication: expect (30, 70, 110)
    cout << "\nmatrix_vector_multiply: " << endl;
    m = new Matrix(3,4);
    Vector * v = new Vector(4);
    for (int i = 0; i < 12; ++i) {
        (m->vals)[i] = 1.0 + i;
        if (i < 4) {
            (v->vals)[i] = 1.0 + i;
        }
    }
    cout << "Matrix: " << endl;
    print_matrix(m);
    cout << "Vector: " << endl;
    print_vector(v);
    Vector * res = m->matrix_vector_multiply(m, v);
    cout << "Result: " << endl;
    print_vector(res);
    delete m;
    delete v;
    delete res;
}
