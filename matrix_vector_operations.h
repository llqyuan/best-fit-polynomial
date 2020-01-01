#ifndef MATRIX_VECTOR_OPERATIONS_H
#define MATRIX_VECTOR_OPERATIONS_H


class Matrix;
class Vector;


class LinearAlgebraObject {
    public:
        LinearAlgebraObject();
        ~LinearAlgebraObject();

        Matrix * transpose(Matrix * m);
        Vector * matrix_vector_multiply(Matrix * m, Vector * v);
        Matrix * matrix_matrix_multiply(Matrix * m1, Matrix * m2);

    private:
        Vector * ith_column_as_vector(Matrix * m, int i);
        void map_vector_to_ith_column(Matrix * m, Vector * v, int i);
};



class Matrix : public LinearAlgebraObject {
    public:
        float * vals;
        int num_rows;
        int num_cols;

        Matrix(int rows, int cols);
        ~Matrix();
        float get_matrix_entry(int row, int col);
};


class Vector : public LinearAlgebraObject {
    public:
        float * vals;
        int len;

        Vector(int use_len);
        ~Vector();
};

#endif
