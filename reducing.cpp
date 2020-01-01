#include "reducing.h"
#include <cassert>
#include <new>


using namespace std;


void Reducing :: reduce(Matrix * m, Vector * v) 
{
    
}


int Reducing :: row_of_first_nonzero_entry(Matrix * m, Vector * v) 
{

}


void Reducing :: mult_row_by(Matrix * m, Vector * v, 
                             int row, float factor)
{

}


void Reducing :: add_factor_of_row_to(Matrix * m, Vector * v, 
                                      int add_to, 
                                      int added, 
                                      float factor)
{

}


void Reducing :: swap_rows(Matrix * m, Vector * v, 
                           int row_1, int row_2) 
{

}


bool Reducing :: reduce_column(Matrix * m, Vector * v, 
                               int row, int col) 
{
    return false;
}
