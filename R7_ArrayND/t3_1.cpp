#include<iostream> 
using namespace std; 

double * ReserveArray(int n) { 
  double *mas = new double [n]; 
  return mas; 
}
 
void FreeArray(double *mas) { 
  delete[] mas; 
} 

void EnterArray(double *mas, int n) { 
  for (int i = 0; i < n; i++) { 
   cout << "mas[" << i << "] = "; 
   cin >> mas[i]; 
 } 

} 
void PrintArray(const double *mas, int n) { 
  for (int i = 0; i < n; i++) 
   cout << "\t" << mas[i]; cout << endl; 
}
 
double PowArray(const double *mas, int n) { 
  double sum =0;
  for (int i = 0; i < n; i++) {
     sum += mas[i]*mas[i];
  }
  //cout << "\t" << mas[i]*mas[i]; 
  //cout << endl; 
 return sum;
} 

int main() { 
 int n; 
 cout << "Enter n = "; cin >> n; 

 double *mas = ReserveArray(n);
 
 EnterArray(mas, n); 
 PrintArray(mas, n); 
 double s =PowArray(mas, n); 
 cout<<"s="<<s;
 FreeArray(mas); 
} 



