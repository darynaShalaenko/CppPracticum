#include "Predicat.h"

bool isEqual(float a, float b);
{
    float eps = 0.00001;
    return abs(a-b) < eps;
}

