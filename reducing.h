#ifndef REDUCING_H
#define REDUCING_H

#include "matrix_vector_operations.h"


// Provides logic for reducing an augmented matrix to reduced row
//   echelon form.
class Reducing {
    public:
        // Class constructor
        Reducing();

        // Class destructor
        ~Reducing();

        // reduce(m, v) reduces the augmented matrix [m | v] to reduced
        //   row echelon form.
        // effects: modifies m, v
        // requires: the number of rows in m is equal to the length of 
        //   v
        void reduce(Matrix * m, MathVector * v);

    private:
        // row_of_first_nonzero_entry(m, row, col) returns the row 
        //   number in m of the first nonzero entry in the column
        //   col, starting from the row number row.
        
        int row_of_first_nonzero_entry(Matrix * m, int row, int col);

        // mult_row_by(m, v, row, factor) performs the elementary 
        //   row operation  << factor * R_i >> on the augmented matrix
        //   [m | v], where i is the row number given by the 
        //   parameter row (row = 0 corresponds to i = 1)
        // effects: modifies m and v
        // requires: the number of rows in m is equal to the length of 
        //   v
        void mult_row_by(
            Matrix * m, MathVector * v, int row, float factor);

        // add_factor_of_row_to(m, v, add_to, added, factor) performs
        //   the elementary row operation << R_i + factor * R_j >> on
        //   the augmented matrix [m | v], where i and j are the row 
        //   numbers given by add_to and added respectively
        // effects: modifies m and v
        // requires: the number of rows in m is equal to the length of 
        //   v
        void add_factor_of_row_to(
            Matrix * m, MathVector * v, 
            int add_to, int added, float factor);

        // swap_rows(m, v, row_1, row_2) performs the elementary row
        //   operation << R_i <-> R_j >> on the augmented matrix [m | v],
        //   where i and j are the row numbers given by row_1 and 
        //   row_2 respectively
        // effects: modifies m and v
        // requires: the number of rows in m is equal to the length of 
        //   v
        void swap_rows(Matrix * m, MathVector * v, int row_1, int row_2);

        // reduce_column(m, v, row, col) performs the necessary row 
        //   operations to get a leading one in the entry at the 
        //   row and column given by row and col respectively, if
        //   possible. Returns true if there exist nonzero entries
        //   in the given column (meaning the above is possible),
        //   and false otherwise.
        // effects: modifies m and v
        // requires: 
        //   * all rows and columns to the left of and above
        //     row and col are reduced
        //   * the number of rows in m is equal to the length of v
        bool reduce_column(Matrix * m, MathVector * v, int row, int col);
};

#endif
