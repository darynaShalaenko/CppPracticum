#include<stdio.h> 
 
#define SIZE 5

 int main() { 
 
 int arr[] = {1,2,3,4,5};
 
 // for (int i = 0; i < size; i++) { arr[i] = i * 3; cout << arr[i] << " "; } 
  
 double number; 
 printf("Enter number = "); 
 scanf("%d",&number); 
 int cnt = 0; 
 for (int i = 0; i < size; i++) { 
    if (arr[i] < number) cnt++; 
 } 
 printf("Elements < number: %d \n", cnt); 
 } 
