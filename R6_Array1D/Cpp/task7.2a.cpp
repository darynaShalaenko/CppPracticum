//6) 
#include <iostream> 
using namespace std; 
int main() { 
  int i = 0; 
  int sum = 0; 
  do {   
    int el; 
    cout << "a[" << i << "]="; 
    cin >> el; 
    sum += el; 
    //if (el == 0) { break; } 
   i++; 
   } 
  while (el!=0); 
  cout << "Sum = " << sum; 
} 
