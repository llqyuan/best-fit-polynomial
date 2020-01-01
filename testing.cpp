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



int main(void) {
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
}
