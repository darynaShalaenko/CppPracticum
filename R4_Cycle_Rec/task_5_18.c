#include <stdio.h>
#include <math.h>
float y_from_x(float x){
    float result = x*x*x + 4*x*x + x - 6;
    return result;
}
float find_u(int n){
    float result;
    if(n == 0){
        result = 1;
    }
    else{
        result = find_u(n - 1) - (y_from_x(find_u(n - 1)) * (find_u(n - 1) - find_u(0))) / (y_from_x(find_u(n - 1) - y_from_x(find_u(0))));
    }
    return result;
}
int main()
{   
    int n = 0;
    float eps = 0.001, next_res = 1;
    while(next_res > eps){
        n += 1;
        next_res = fabs(find_u(n) - find_u(n - 1));
    }
    printf("n = %d\nx(n) = %f", n, y_from_x(n));

}
