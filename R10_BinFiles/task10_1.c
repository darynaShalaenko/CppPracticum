
// task 11.1 - binary file work
// input array
// write array to file 
//read array form file
#include <stdio.h>
#include <stdlib.h>

void input(double* ar, int n){
   for(int i=0;i<n;++i){
      printf("a[%d]=",i);
      scanf("%lf",&ar[i]);
   }

}

int writeFile(const char* fname, double* ar, int n){

    FILE* fp = fopen(fname, "wb"); // open bin file for write
    int res = fwrite(ar, sizeof(*ar), n, fp); // write n*8 bytes from ar into fp
    fclose(fp); // close file
    printf("re=%d",res); 
    return res;
}

int readFile(const char* fname, double* ar){

    FILE* fp = fopen(fname, "rb"); // open bin file for reading
    double item;
    int k = 0;
    while(!feof(fp)){ // until we can read file
       int res = fread(&item,sizeof(item), 1, fp); // read 1 double from fp
       //printf("re=%d a[%d]= %lf",res,k,item);
       if(res!=1) break; 
       ar[k++] = item;         
    }

    fclose(fp); // close file
    return k;
}


int main(){
   int n;
   printf("n=");
   scanf("%d",&n);
   double* mas = (double*) malloc(n*sizeof(double));
   input(mas,n);

   char fname[20];
   printf("file name:");
   scanf("%s",fname);

   int res = writeFile(fname,mas,n);
   if(res !=n){
      printf("Not all data were written");
   }
   else{
      double* mas2 = (double*) malloc(n*sizeof(double));

      int m = readFile(fname, mas2);
      printf("\n");
      for(int i=0;i<m-1;++i){
         printf("%lf, ",mas2[i]);
      } 
      printf("%lf",mas2[m-1]); 
      free(mas2);
   }
   

   free(mas);
}
