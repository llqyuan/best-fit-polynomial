#include <iostream>
#include <cmath>
#include <vector>
// #include "method_of_least_squares.h"
// #include "linear_algebra_objects.h"


using namespace std;


struct posn {
    float x;
    float y;
};


// entry_exists(plist, x) returns true if x exists as an
//   x coordinate in plist and false otherwise
bool entry_exists(vector<posn> * plist, float x) 
{
    for (vector<posn> :: iterator it = plist.begin();
         it != plist.end();
         ++it)
    {
        if (within(x, (*it).x)) 
        {
            return true;
        }
    }
    return false;
}


Matrix * least_squares_matrix(vector<posn> * plist, const int degree);


MathVector * least_squares_vector(vector<posn> * plist);


void pretty_print_polynomial(vector<posn> * plist);


int main(void) 
{
    vector<posn> posn_list;
    
}
