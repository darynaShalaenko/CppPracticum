#include <stdio.h>
#include <math.h>

int test_abc(float a, float b, float c)
{
    int answer = 0;
    if (a + b > c){
        answer = 1;
    }
    return answer;
}
int main()
{
    float a, b, c, a_a, a_b, a_c;
    float eps = 0.0001;
    printf("Enter a, b, c\n");
    scanf("%f %f %f", &a, &b, &c);
    if (a > 0 && b > 0 && c > 0){
        if (test_abc(a, b, c) == 1 && test_abc(c, b, a) == 1 && test_abc(a, c, b) == 1){
            a_c = acos((a * a + b * b - c * c)/(2 * a * b)) * 180/3.14159;
            a_b = acos((a * a - b * b + c * c)/(2 * a * c)) * 180/3.14159;
            a_a = acos((b * b - a * a + c * c)/(2 * b * c)) * 180/3.14159;
            printf("angles: %f, %f, %f\n", a_c, a_b, a_a);
            if(fabs(a_c - 90) < eps || fabs(a_b - 90) < eps || fabs(a_a - 90) < eps){
                printf("Right triangle");
            }
            else if(a_c - 90 > eps || a_b - 90 > eps || a_a - 90 > eps){
                printf("Obtuse triangle");
            }
            else{
                printf("Acute triangle");
            }
        }
        else{
            printf("Triangle does not exist.");
        }
    }
    else{
        printf("Triangle does not exist.");
    }
}
