
#include <stdio.h>
#include <math.h>


typedef struct {
    double x,y;
    char type;
} Point;


Point inputPoint(){
    Point p;
    printf("Type(p - polar, d - Decart): ");
    scanf("%s", &p.type);
    printf("x/r = ");
    scanf("%lf", &p.x);
    printf("y/angle = ");
    scanf("%lf", &p.y);
    return p;
}


Point pol2dec(Point p) {
    if (p.type == "d") return p;
    double r = p.x;
    p.x = r * cos(p.y);
    p.y = r * sin(p.y);
    return p;
}


double triangleArea(Point A, Point B, Point C) {
    if (A.type == "p") A = pol2dec(A);
    if (B.type == "p") B = pol2dec(B);
    if (C.type == "p") C = pol2dec(C);
    double a, b, c;
    a = sqrt(pow(A.x-B.x, 2) + pow(A.y-B.y, 2));
    b = sqrt(pow(A.x-C.x, 2) + pow(A.y-C.y, 2));
    c = sqrt(pow(C.x-B.x, 2) + pow(C.y-B.y, 2));
    double p = (a+b+c)/2;
    double area = sqrt(p*(p-a)*(p-b)*(p-c));
    return area;
}


int main() {
    Point p1 = inputPoint(), p2 = inputPoint(), p3 = inputPoint();
    printf("Area of this triangle is %g", triangleArea(p1, p2, p3));
}
