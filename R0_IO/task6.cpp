#include <iostream>

using namespace std;

int main(){

  long double m1, m2, F, r, gamma = 6.673e-11L; // gamma = 6.673/100000000000000;

 /* m1 = 1000;
  m2 = 1000.23456;
  r = 101.0;

  scanf("%Lf", &m1);
  scanf("%Lf", &m2);
  scanf("%Lf", &r);
*/
  cin>>m1;
  cin>>m2;
  cin>>r; 

  F = gamma * m1 * m2 / (r * r); 
  //printf("F = %Lf", F);
  cout<<"F = " << F;
}
