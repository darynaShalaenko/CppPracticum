#include "Predicat.h"
#include <math.h>

bool isEqual(float a, float b){
    float eps = 0.00001;
    return fabs(a-b) < eps;
}

