#include<iostream> 
//#include<cstdio> 
using namespace std; 
 int main() { 
 const size_t size = 5;
 
 int arr[size] = {1,2,3,4,5};
 
 // for (int i = 0; i < size; i++) { arr[i] = i * 3; cout << arr[i] << " "; } 
 cout << endl; 
 double number; 
 cout << "Enter number = "; 
  cin >> number; 
 int cnt = 0; 
 for (int i = 0; i < size; i++) { 
    if (arr[i] < number) cnt++; 
 } 
 cout << "Elements < number: " << cnt << endl; 
 } 
