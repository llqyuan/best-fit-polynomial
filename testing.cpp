#include "within.h"
#include "matrix_vector_operations.h"
#include "reducing.h"
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


void print_vector(MathVector * v) {
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
    MathVector * v = new MathVector(4);
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
    MathVector * res = m->matrix_vector_multiply(m, v);
    cout << "Result: " << endl;
    print_vector(res);
    delete m;
    delete v;
    delete res;

    // map column to vector and vector to column -- uncomment 
    //   only when the respective methods are temporarily made 
    //   public instead of private
    /*
    cout << "\nith_column_as_vector and map_vector_to_ith_column: "
        << endl;
    m = new Matrix(3,4);
    for (int i = 0; i < 12; ++i) {
        (m->vals)[i] = 1.0 + i;
    }
    cout << "Matrix: "  << endl;
    print_matrix(m);
    MathVector * zeroth_col = m->ith_column_as_vector(0);
    MathVector * third_col = m->ith_column_as_vector(3);
    cout << "0th col: " << endl;
    print_vector(zeroth_col);
    cout << "3rd col: " << endl;
    print_vector(third_col);
    m->map_vector_to_ith_column(zeroth_col, 1);
    cout << "Matrix after mapping 0th col to 1st col: " << endl;
    print_matrix(m);
    delete m;
    delete zeroth_col;
    delete third_col;
    */

    // matrix-matrix multiplication: 
    //   expect ( (-1, -4, -1, -4), (8, 14, 8, 14))
    cout << "\nmatrix_matrix_multiply: " << endl;
    Matrix * m1 = new Matrix(2, 3);
    Matrix * m2 = new Matrix(3, 4);
    for (int i = 0; i < 12; ++i) {
        *(m2->vals + i) = i % 2 + i / 4;
        if (i < 6) {
            *(m1->vals + i) = i - 2;
        }
    }
    cout << "Matrix m1: " << endl;
    print_matrix(m1);
    cout << "Matrix m2: " << endl;
    print_matrix(m2);
    cout << "Result: " << endl;
    Matrix * result = m1->matrix_matrix_multiply(m1, m2);
    print_matrix(result);
    delete m1;
    delete m2;
    delete result;

    // reduce
    Reducing * r = new Reducing();
    MathVector * v3 = new MathVector(3);
    MathVector * v4 = new MathVector(4);
    for (int i = 0; i < 3; ++i) {
        *(v3->vals + i) = i;
        *(v4->vals + i) = i;
        *(v4->vals + i + 1) = i;
    }
    cout << "\nReducing invertible matrix:" << endl;
    Matrix * m_inv = new Matrix(3, 3);
    for (int i = 0; i < 9; ++i) {
        float a[9] = {1,0,0, 1,2,0, 1,1,2};
        *(m_inv->vals + i) = a[i];
    }
    cout << "Original matrix:" << endl;
    print_matrix(m_inv);
    cout << "Original vector:" << endl;
    print_vector(v3);
    r->reduce(m_inv, v3);
    cout << "Result:" << endl;
    print_matrix(m_inv);
    print_vector(v3);
    delete m_inv;

    cout << "\nReducing 4x3 matrix:" << endl;
    Matrix * m_4_3 = new Matrix(4,3);
    for (int i = 0; i < 12; ++i) {
        float a[12] = {1,0,0, 2,1,2, 2,0,2, 0,1,0};
        *(m_4_3->vals + i) = a[i];
    }
    cout << "Original matrix:" << endl;
    print_matrix(m_4_3);
    cout << "Original vector:" << endl;
    print_vector(v4);
    r->reduce(m_4_3, v4);
    cout << "Result:" << endl;
    print_matrix(m_4_3);
    print_vector(v4);
    delete m_4_3;

    cout << "\nReducing a matrix where a leading one "
         << "doesn't exist in one of the columns:" << endl;
    Matrix * ml = new Matrix(3, 4);
    for (int i = 0; i < 12; ++i) {
        float a[12] = {-2,0,-2,0, 0,0,0,3, 0,0,12,0};
        *(ml->vals + i) = a[i];
    }
    cout << "Original matrix:" << endl;
    print_matrix(ml);
    cout << "Original vector:" << endl;
    print_vector(v3);
    r->reduce(ml, v3);
    cout << "Result:" << endl;
    print_matrix(ml);
    print_vector(v3);
    delete ml;
    delete v3;
    delete v4;
    delete r;
}
