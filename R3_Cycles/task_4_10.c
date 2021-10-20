#include <iostream>
#include <cmath>
using namespace std;

float sum(int n){
  float a1 = 1, a2 = 1, a, b = 1, S = 0, k=1;

  for (k = 1; (k <= 2 && k <=n); k++){
    b = b * 3;
    S = S + float(b)/1;
  }

  for (k = 3; k <= n; k++){
    b = b * 3;
    a = a2/k + a1;
    S = S + float(b) / float(a);
    a2 = a1;
    a1 = a;
  } 

  return S;
}

int main() {
    cout <<"Result = "<< sum(3) << endl;
    return 0;
} 
