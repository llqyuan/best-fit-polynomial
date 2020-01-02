#include "method_of_least_squares.h"
#include "linear_algebra_objects.h"
#include "reducing.h"
#include <cassert>


using namespace std;


MethodOfLeastSquares :: MethodOfLeastSquares() {}


MethodOfLeastSquares :: ~MethodOfLeastSquares() {}


MathVector * MethodOfLeastSquares :: least_squares_solution(Matrix * X,
                                                            MathVector * y)
{
    Reducing * r = Reducing();
    Matrix * X_transpose = X->transpose(X);
    Matrix * X_transpose_times_X = X->matrix_matrix_multiply(
        X_transpose, X);
    MathVector * X_transpose_times_y = X->matrix_vector_multiply(
        X_transpose, y);
    r->reduce(X_transpose_times_X, X_transpose_times_y);
    verify_identity_matrix(X_transpose_times_X);
    delete r;
    delete X_transpose;
    delete X_transpose_times_X;
    return X_transpose_times_y;
}


void MethodOfLeastSquares :: verify_identity_matrix(Matrix * m)
{
    assert(m->num_cols == m->num_rows);
    const int dim = m->num_cols;
    for (int i = 0; i < dim * dim; ++i) {
        if (i / dim == i % dim) {
            assert(within(m->get_matrix_entry(i / dim, i % dim), 1));
        } else {
            assert(within(m->get_matrix_entry(i / dim, i % dim), 0));
        }
    }
}
