#ifndef REDUCING_H
#define REDUCING_H

#include "matrix_vector_operations.h"


class Reducing {
    public:
        // Class constructor
        Reducing();

        // Class destructor
        ~Reducing();

        // reduce(m, v)
        void reduce(Matrix * m, Vector * v);

    private:
        // row_of_first_nonzero_entry(m, v, col)
        int row_of_first_nonzero_entry(Matrix * m, Vector * v);

        // mult_row_by(m, v, row, factor)
        void mult_row_by(
            Matrix * m, Vector * v, int row, float factor);

        // add_factor_of_row_to(m, v, add_to, added, factor)
        void add_factor_of_row_to(
            Matrix * m, Vector * v, 
            int add_to, int added, float factor);

        // swap_rows(m, v, row_1, row_2)
        void swap_rows(Matrix * m, Vector * v, int row_1, int row_2);

        // reduce_column(m, v, row, col)
        bool reduce_column(Matrix * m, Vector * v, int row, int col);
};

#endif
