#include<stdio.h>
#include<stdlib.h>
 

void EnterArray(double *mas, int n) { 
  for (int i = 0; i < n; i++) { 
   printf( "mas[%d] = ",i); 
   scanf("%lf",&mas[i]); 
 } 

} 
void PrintArray(const double *mas, int n) { 
  for (int i = 0; i < n; i++) 
  printf("%lf ", mas[i]); 
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
 printf("Enter n = "); 
 scanf("%d",&n); 

 double *mas = malloc(n*sizeof(double)); // = calloc(n,sizeof(double));
 
 EnterArray(mas, n); 
 PrintArray(mas, n); 
 double s =PowArray(mas, n); 
 printf("s=%lf",s);
 free(mas); 
} 



