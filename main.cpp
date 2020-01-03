#include <iostream>
#include <cmath>
#include <vector>
 #include "method_of_least_squares.h"
 #include "linear_algebra_objects.h"


using namespace std;


struct posn {
    float x;
    float y;
};


// entry_exists(plist, x) returns true if x exists as an
//   x coordinate in plist and false otherwise
bool entry_exists(vector<posn> * plist, float x) 
{
    for (vector<posn> :: iterator it = plist->begin();
         it != plist->end();
         ++it)
    {
        if (within(x, (*it).x)) 
        {
            return true;
        }
    }
    return false;
}


Matrix * least_squares_matrix(vector<posn> * plist, const int degree)
{
    Matrix * m = new Matrix(plist.size(), degree + 1);
    // todo I wanna iterate on the row number here, and get the row-th 
    //   element of the vector
    int row = 0;
    for (vector<posn> :: iterator it = plist->begin();
         it != plist->end();
         ++it)
    {
        float x = it->x;
        for (int col = 0; col < m->num_cols; ++col)
        {
            m->vals[row * m->num_cols + col] = pow(x, col);
        }
        row += 1;
    }
    return m;
}


MathVector * least_squares_vector(vector<posn> * plist)
{
    MathVector * v = new Vector(plist.size());
    // todo ditto
    int i = 0;
    for (vector<posn> :: iterator it = plist->begin();
         it != plist->end();
         ++it)
    {
        float y = it->y;
        v->vals[i] = y;
        i += 1;
    }
    return v;
}


void pretty_print_polynomial(vector<posn> * plist);


int main(void) 
{
    vector<posn> posn_list;
    
}
