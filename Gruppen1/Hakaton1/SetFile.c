#include "stdio.h"
#include "SetFile.h"

#include <stdlib.h>


int outputSetFile(const char* fname){

    FILE* f = fopen(fname, "rb");
    unsigned n;
    fread(&n, sizeof(n), 1, f);

    float tmp;
    printf("File %s\n", fname);
    for (int i=0; i<n; i++)
    {
        fread(&tmp, sizeof(tmp), 1, f);
        printf("%f\n", tmp);
    }

    fclose(f);
    return 0;
}

int comp(const void * elem1, const void * elem2){
    float f = *((float*)elem1);
    float s = *((float*)elem2);
    if(isEqual(f,s)) return 0;
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}


int insertIntoSorted(float* arr, int n, float p){

  int* pItem = (int*) bsearch (&p, arr, n, sizeof (int), comp);
  if(pItem){
      return -1;
  }
  arr[n] = p;
  qsort(arr,n+1,sizeof (int), comp);
  return 0;
}

int formSetFile(const char* finput, const char* foutput){
 
  FILE* fp = fopen(finput,"rb"); // open file binary, for reading
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",finput);
     return -1;
  }

 
  FILE* fp1 = fopen(foutput,"wb"); // open file binary, for reading
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",foutput);
     return -1;
  }
  int n;
  fread(&n,1,sizeof(n),fp);
  float a[10000] ={0,};    

  for(int i=0;i<n;++i){
     float tmp;
     fread(&tmp,1,sizeof(tmp),fp); 
     a[i] = tmp; 
  }
  fclose(fp);

  qsort(a,n,sizeof(float), comp);  

  int m=1;
  float prev = a[0];
  float b[10000] ={0,};    
  for(int i=1;i<n;i++){
     if(isEqual(a[i],prev)){
        continue;
     } 
     b[m++]=a[i];
  }

  fwrite(&m,1,sizeof(m),fp1);

  for(int i=0;i<m;++i){
    fwrite(&b[i],1,sizeof(a[i]),fp1);    
  }
  fclose(fp1);
}
