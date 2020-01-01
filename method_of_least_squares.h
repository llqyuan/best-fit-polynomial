#ifndef METHOD_OF_LEAST_SQUARES_H
#define METHOD_OF_LEAST_SQUARES_H

#include "reducing.h"
#include "matrix_vector_operations.h"


class MethodOfLeastSquares {
    public:
        // Constructor
        MethodOfLeastSquares();

        // Destructor
        ~MethodOfLeastSquares();

        // least_squares_solution(X, y)
        MathVector * least_squares_solution(Matrix * X, Vector * y);
    
    private:
        // verify_identity_matrix(m)
        void verify_identity_matrix(Matrix * m);
}


#endif
