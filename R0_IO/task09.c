#include "stdio.h" 
//#include "iostream" 
//x 15 за п'ять операцій;
// using namespace std;
int main() { 
 float x; scanf("%f", &x); // cin>>x;
 float y = x*x; // x^2
 float z= y*y;  // x^4 

 float x5 = z*x;

 float x15 = x5*x5*x5;

 printf("y=%g %g", z, x15); // cout<<z<<x15;


}
