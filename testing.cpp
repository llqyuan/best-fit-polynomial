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
    Vector * zeroth_col = m->ith_column_as_vector(0);
    Vector * third_col = m->ith_column_as_vector(3);
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
}
