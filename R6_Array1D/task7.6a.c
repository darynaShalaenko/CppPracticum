 
#include<stdio.h> 


void enter_arr(int n, double* arr) {  
  for (int i = 0; i < n; i++) { 
    printf("arr[%d] = ",i); 
    scanf("%lf",&arr[i]); 
 } 
} 

void print_arr(int n, const double * arr) { 
   for (int i = 0; i < n; i++) { 
     printf("arr[%d] = %lf" , i, arr[i] ); 
   } 
 printf("\n"); 
} 

void sum_arr(int n, const double* arr1, const double* arr2, double* a) { 
  
  for (int i = 0; i < n; i++) { 
   a[i] = arr1[i] + arr2[i]; 
  } 
  
} 

double dob_arr(int n, const double arr1[], const double arr2[]) { 
  double dob = 0; 
  for (int i = 0; i < n; i++) { 
    dob += arr1[i] * arr2[i]; 
  } 
 return dob; 
} 

int main() { 

 const size_t size = 4; 
 double arr1[size]; 
 enter_arr(size, arr1); 
 print_arr(size, arr1); 
 double arr2[size]; 
 enter_arr(size, arr2); 
 print_arr(size, arr2); 
 double arr3[size]; 
 sum_arr(size, arr1, arr2,arr3); 
 print_arr(size, arr3); 
 printf("Dob:%lf \n", dob_arr(size, arr1, arr2)); 

  
 }

