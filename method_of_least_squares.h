#ifndef METHOD_OF_LEAST_SQUARES_H
#define METHOD_OF_LEAST_SQUARES_H

#include "reducing.h"
#include "linear_algebra_objects.h"


// Provides logic for using the method of least squares to find a 
//   polynomial of best fit.
class MethodOfLeastSquares {
    public:
        // Constructor
        MethodOfLeastSquares();

        // Destructor
        ~MethodOfLeastSquares();

        // least_squares_solution(X, y) returns the solution vector
        //   representing the polnomial of best fit. X and y are
        //   intermediate mathematical objects in the calculation
        //   of the solution (specifically, they represent X and y
        //   in the normal system (X^T)*X*a = (X^T)*y)
        // effects: allocates memory (must call destructor on 
        //   returned pointer)
        MathVector * least_squares_solution(Matrix * X, Vector * y);
    
    private:
        // verify_identity_matrix(m) performs assertions that verify 
        //   that m is an identity matrix.
        void verify_identity_matrix(Matrix * m);
}


#endif
