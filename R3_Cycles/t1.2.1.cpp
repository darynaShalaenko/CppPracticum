// task 1.2.1

#include<iostream> 
#include <cmath>

using namespace std; 

int main() { 
 double x; int n; 
cout << "Enter x = "; 
 cin >> x; 
cout << "Enter n = "; 
cin >> n; 
 for (int i = 0; i < n; i++) { 
       x = sin(x); 
  } 
 cout << "x = " << x << endl; 
 cin.get();

}
