#include <stdio.h>

int fib_b(int M){
 int k=0; 
 int f0=0,f1=1,fk; 
 
 for(;f1<M;){  // while(f1<M)
    k++;
                   // f0,f1,fk  
    fk = f0 + f1; // 2,3,5
    f0 = f1;       //3,3,5 
    f1 = fk;       //3,5,5
 }                 //  

  return k;
}


int fib_a(int k){
 int n=0; 
 int f0=0,f1=1,fk; 
 
 while(n<k){
    n++;
                   // f0,f1,fk  
    fk = f0 + f1; // 2,3,5
    f0 = f1;       //3,3,5 
    f1 = fk;       //3,5,5
 }                 //  

  return f0;
}


int fib_v(int M){

 int f0=0,f1=1,fk; 
 int k=1;
 
 while(f1<M){
    k++;               // f0,f1,fk  
    fk = f0 + f1; // 0,1,1
    f0 = f1;       //1,1,2 
    f1 = fk;       //1,2,3
 }                 //2,3,5  

  return k;
}

int fib_g(int M){

 int f0=0,f1=1,fk; 
 int k=1;
 int sum_fib = f0; 
 
 while(f1<M){
    k++;               // f0,f1,fk  
    fk = f0 + f1; // 0,1,1   
    sum_fib += f1;
    f0 = f1;       //1,1,2 
    f1 = fk;  
 }                 

   return sum_fib;
}


int main(){

  int k=19;
  printf("F(%d)<%d, F(%d)>%d \n",k,fib_a(k),fib_b(k),k);

  scanf("%d",&k);
  printf("F(%d)<%d, F(%d)>%d \n",fib_a(k),k, fib_b(k),k);

  printf("Sum =%d", fib_g(1000));
}
