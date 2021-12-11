#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int a, b, c;
    cout << "triangle's sides: ";
    cin >> a >> b >> c;
    float m1, m2, m3;
    m1 = 0.5*sqrtf(2*a*a + 2*b*b - c*c);
    m2 = 0.5*sqrtf(2*a*a + 2*c*c - b*b);
    m3 = 0.5*sqrtf(2*c*c + 2*b*b - a*a);
    cout << "m1 = " << m1 << "; m2 = " << m2 << "; m3 = " << m3 << ";";
    cout << endl;
    float l1, l2, l3;
    l1 = sqrtf(a*b*(a+b+c)*(a+b-c)/(a+b));
    l2 = sqrtf(a*c*(a+b+c)*(a+c-b)/(a+c));
    l1 = sqrtf(c*b*(a+b+c)*(c+b-a)/(c+b));
    cout << "l1 = " << l1 << "; l2 = " << l2 << "; l3 = " << l3 << ";";
    cout << endl;
    float p, S;
    float h1, h2, h3;
    p = (a+b+c)/2;
    S = sqrtf(p*(p-a)*(p-b)*(p-c));
    h1 = 2*S/a;
    h2 = 2*S/b;
    h3 = 2*S/c;
    cout << "h1 = " << h1 << "; h2 = " << h2 << "; h3 = " << h3 << ".";
}
