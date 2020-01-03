#include <iostream>
#include <cmath>
#include <vector>
 #include "method_of_least_squares.h"
 #include "linear_algebra_objects.h"
 #include "within.h"


using namespace std;


struct posn {
    float x;
    float y;
};


// entry_exists(plist, x) returns true if x exists as an
//   x coordinate in plist and false otherwise
bool entry_exists(vector<posn> * plist, float x) 
{
    for (int i = 0; i < plist->size(); ++i)
    {
        if (within(x, (plist->at(i)).x)) 
        {
            return true;
        }
    }
    return false;
}


Matrix * least_squares_matrix(vector<posn> * plist, const int degree)
{
    Matrix * m = new Matrix(plist.size(), degree + 1);
    for (int row = 0; row < plist->size(); ++row)
    {
        float x = (plist->at(row))->x;
        for (int col = 0; col < m->num_cols; ++col)
        {
            m->vals[row * m->num_cols + col] = pow(x, col);
        }
    }
    return m;
}


MathVector * least_squares_vector(vector<posn> * plist)
{
    MathVector * v = new Vector(plist.size());
    for (int i = 0; i < plist->size(); ++i)
    {
        float y = (plist->at(i)).y;
        v->vals[i] = y;
    }
    return v;
}


void pretty_print_polynomial(MathVector * v)
{
    if (v->len) {
        cout << "f(x) = ";
        bool print_plus = false;
        for (int i = 0; i < v->len; ++i) {
            if (within(v->vals[i], 0)) {
                continue;
            }

            if (print_plus && v->vals[i] > 0) {
                cout << " + ";
            } else if (print_plus && v->vals[i] < 0) {
                cout << " - ";
            }
            print_plus = true;

            if (i == 0) {
                cout << v->vals[0];

            } else if (i == 1 && within(fabs(v->vals[i]), 1)) {
                cout << "x";

            } else if (i == 1) {
                cout << fabs(v->vals[i]) << "x";

            } else if (within(fabs(v->vals[i]), 1)) {
                cout << "x^" << i;

            } else {
                cout << v->vals[i] << "x^" << i;
            }
        }
    } else {
        cout << "f(x) = 0";
    }
    cout << endl;
}


int main(void) 
{
    vector<posn> posn_list;
    
}
