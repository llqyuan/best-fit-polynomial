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


int main(void) {
    vector<posn> posn_list;
    struct posn p;
    p.x = 1;
    p.y = 2;
    struct posn q;
    q.x = 3;
    q.y = 4;
    posn_list.push_back(p);
    posn_list.push_back(q);
    for (vector<posn>::iterator it = posn_list.begin();
        it != posn_list.end();
        ++it)
    {
        cout << (*it).x << ", " << (*it).y << endl;
    }
}