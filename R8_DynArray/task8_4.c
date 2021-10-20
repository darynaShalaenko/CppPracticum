#include <stdio.h>
#include <stdlib.h>


int** allocate_matrix(int n){
   int ** matr = (int**) calloc(n, sizeof(int*));

   for(int i=0;i<n;++i){
      matr[i] = (int*) calloc(n, sizeof(int)); 
   } 
   return matr;
}



int input_matrix(int** matr, int n){
    
   for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
          printf("a[%d, %d]=",i,j);
          scanf("%d",&matr[i][j]);
      }
  }
   
  return 1;
}

int output_matrix(int** matr, int n){
   printf("\n"); 
   for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
          printf("%d ",matr[i][j]); 
      }
   printf("\n");
  }
   
  return 1;
}


void deallocate_matrix(int** matr, int n){

   for(int i=0;i<n;++i){
      free(matr[i]); 
   }

   free(matr);
}

int mult_matrix(int** matr1, int n1, int** matr2, int n2, int** matr3, int* n3){

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
                  matr3[i][j] += matr1[i][k] * matr2[k][j]; 
         }
      }
   }
   return 0;   
}

int main(){
  int n;
  scanf("%d",&n);

  int ** a1 = allocate_matrix(n);
  int ** a2 = allocate_matrix(n);
  int ** a3 = allocate_matrix(n);

  input_matrix(a1,n);
  input_matrix(a2,n);
  int m;
  mult_matrix(a1,n,a2,n,a3,&m); 

  output_matrix(a3,m);

  deallocate_matrix(a1,n);
  deallocate_matrix(a2,n);

  deallocate_matrix(a3,m);
}

