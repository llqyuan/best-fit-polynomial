#ifndef LINEAR_ALGEBRA_OBJECTS_H
#define LINEAR_ALGEBRA_OBJECTS_H


class Matrix;
class MathVector;


class LinearAlgebraObject {
    public:
        // Class constructor
        LinearAlgebraObject();

        // Class destructor
        ~LinearAlgebraObject();

        // transpose(m) returns the transpose of m
        // effects: allocates memory (must call destructor on 
        //   returned pointer)
        Matrix * transpose(Matrix * m);

        // matrix_vector_multiply(m, v) returns the vector 
        //   resulting from multiplying m with v
        // effects: allocates memory (must call destructor on
        //   returned pointer)
        // requires: the length of v is equal to the number of
        //   columns in m
        MathVector * matrix_vector_multiply(Matrix * m, MathVector * v);

        // matrix_matrix_multiply(m1, m2) returns the matrix
        //   resulting from multiplying m1 with m2 (m1 * m2)
        // effects: allocates memory (must call destructor on 
        //   returned pointer)
        // requires: the number of columns in m1 is equal to the
        //   number of rows in m2
        Matrix * matrix_matrix_multiply(Matrix * m1, Matrix * m2);

    private:
        // ith_column_as_ector(m, i) returns the ith column of m 
        //   as a vector
        // effects: allocates memory (must call destructor on 
        //   the returned pointer)
        MathVector * ith_column_as_vector(Matrix * m, int i);

        // map_vector_to_ith_column(m, v, i) maps the values of v
        //   to the ith column of m
        // effects: modifies m
        // requires: the length of v is equal to the number of rows
        //   in m
        void map_vector_to_ith_column(Matrix * m, MathVector * v, int i);
};



class Matrix : public LinearAlgebraObject {
    public:
        float * vals;
        int num_rows;
        int num_cols;

        // Class constructor. Sets num_rows to rows and num_cols 
        //   to cols.
        Matrix(int rows, int cols);
    
        // Class destructor
        ~Matrix();

        // get_matrix_entry(row, col) returns the value of the entry
        //   in the m-th row and n-th column, where m and n are row 
        //   and col respectively.
        float get_matrix_entry(int row, int col);
};


class MathVector : public LinearAlgebraObject {
    public:
        float * vals;
        int len;

        // Class constructor. Sets len to use_len
        MathVector(int use_len);

        // Class destructor
        ~MathVector();
};

#endif
