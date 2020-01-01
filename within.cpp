#include "within.h"
#include <cmath>

using namespace std;


bool within(float a, float b) {
    float diff = fabs(a - b);
    return diff < 0.0001;
}
