#include <stdio.h>
#include <stdlib.h>

typedef int* VECTOR;


VECTOR allocate_matrix(int n){
   VECTOR matr = (int*) calloc(n*n, sizeof(int));

   return matr;
}



int input_matrix(VECTOR matr, int n){
    
   for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
          printf("a[%d, %d]=",i,j);
          scanf("%d",&matr[i*n+j]);
      }
  }
   
  return 1;
}

int output_matrix(VECTOR matr, int n){
   printf("\n"); 
   for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
          printf("%d ",matr[i*n+j]); 
      }
   printf("\n");
  }
   
  return 1;
}


void deallocate_matrix(VECTOR matr, int n){

   free(matr);
}

int mult_matrix(VECTOR matr1, int n1, VECTOR matr2, int n2, VECTOR matr3, int* n3){

   if(n1!=n2){
     *n3=n1;
     // matr3 = allocate_matrix(*n3);
      return -1;
   }

   *n3 = n1;
   //matr3 = allocate_matrix(n1);
   for(int i=0;i<n1;i++){
     for(int j=0;j<n1;j++){
       for(int k=0;k<n1;k++){
                  matr3[i*n1+j] += matr1[i*n1+k] * matr2[k*n1+j]; 
         }
      }
   }
   return 0;   
}

int main(){
  int n;
  scanf("%d",&n);

  VECTOR a1 = allocate_matrix(n);
  VECTOR a2 = allocate_matrix(n);
  VECTOR a3 = allocate_matrix(n);

  input_matrix(a1,n);
  input_matrix(a2,n);
  int m;
  mult_matrix(a1,n,a2,n,a3,&m); 

  output_matrix(a3,m);

  deallocate_matrix(a1,n);
  deallocate_matrix(a2,n);

  deallocate_matrix(a3,m);
}

