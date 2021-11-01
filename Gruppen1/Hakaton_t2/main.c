#include <stdio.h>

#include "SetFile.h"
#include "PolyFile.h"
#include "Predicat.c"
int create0(const char* fname, int n, int m){

  FILE* fp = fopen(fname,"wb"); // open file binary, for reading
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }

  fwrite(&n,1,sizeof(n),fp);
  for(int i=0;i<n;++i){
     float tmp=(i % m)*10.23f; 
     fwrite(&tmp,1,sizeof(tmp),fp);
  }
  fclose(fp);
}


int create1(const char* fname, int n, int m){

  FILE* fp = fopen(fname,"wb"); // open file binary, for reading
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }

  fwrite(&n,1,sizeof(n),fp);
  for(int i=0;i<n;++i){
     float tmp= ((5*i+7) % m)*1.33f; 
     fwrite(&tmp,1,sizeof(tmp),fp);
  }
  fclose(fp);
}

char test_files1[][40] = {
  "test0_7_7.dat",
  "test0_9_7.dat",
  "test0_1999_1999.dat",
  "test0_2008_1999.dat",
  "test0_7_7.dat", 
  "test0_9_7.dat",
  "test0_1999_1999.dat",
  "test0_2008_1999.dat",
};

char res_files1[][40] = {
  "rtest0_7_7.dat",
  "rtest0_9_7.dat",
  "rtest0_1999_1999.dat",
  "rtest0_2008_1999.dat",
  "rtest0_7_7.dat", 
  "rtest0_9_7.dat",
  "rtest0_1999_1999.dat",
  "rtest0_2008_1999.dat",
};

char res_files2[][40] = {
  "r2test0_7_7.dat",
  "r2test0_9_7.dat",
  "r2test0_1999_1999.dat",
  "r2test0_2008_1999.dat",
  "r2test0_7_7.dat", 
  "r2test0_9_7.dat",
  "r2test0_1999_1999.dat",
  "r2test0_2008_1999.dat",
};


int formSetFileTest(const char* finput, const char* foutput){
 
  FILE* fp = fopen(finput,"rb"); // open file binary, for reading
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",finput);
     return -1;
  }

 
 
  int n;
  fread(&n,1,sizeof(n),fp);
  float a[10000] ={0.f,0.f,} ;   
  int m = 0;
  for(int i=0;i<n;++i){
     float tmp;
     fread(&tmp,1,sizeof(tmp),fp); 
     float t1 = 100000*tmp;  
     unsigned tmp_int = (unsigned)(t1*1395471891L + 132129) %10000;    
     if(a[tmp_int]<0.0000001){
        m++;
     }
     else{
       printf("aaaa %d", tmp_int);
     }
     a[tmp_int] = tmp!=0?tmp:111111.f;
     //printf("%d, %f , %d", tmp_int, tmp, m); 
     
  }
  fclose(fp);

  FILE* fp1 = fopen(foutput,"wb"); // open file binary, for reading
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",foutput);
     return -1;
  }
  fwrite(&m,1,sizeof(m),fp1);

  for(int i=0;i<10000;++i){
     if(a[i]>0.0000001){
       if(fabs(a[i]-111111.f)<0.00001) {
          a[i]=0;  
       }
       fwrite(&a[i],1,sizeof(a[i]),fp1);
    }
  }
  fclose(fp1);
}


void showFile(const char* finput){
   FILE* fp = fopen(finput,"rb"); // open file binary, for reading
   if(fp==NULL) {
     fprintf(stderr, "Error open file %s",finput);
  }
  int n;
  fread(&n,1,sizeof(n),fp);
  printf("n=%d\n",n);
  for(int i=0;i<n;++i){
     float tmp;
     fread(&tmp,1,sizeof(tmp),fp); 
     printf("%f, ", tmp);
  }

  fclose(fp);
}

bool isEqualSetFileTest(const char* A, const char* B){
   
  FILE* fp = fopen(A,"rb"); // open file binary, for reading
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",A);
     return -1;
  }

 
  FILE* fp1 = fopen(B,"rb"); // open file binary, for reading
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",B);
     return -1;
  }
  int n;
  fread(&n,1,sizeof(n),fp);
  float a[10000] ={0,}  ;
  int m = 0;
  for(int i=0;i<n;++i){
     float tmp;
     fread(&tmp,1,sizeof(tmp),fp); 
     unsigned tmp_int = (unsigned)(tmp *12357) %10000;    
     if(a[tmp_int]<0.0000001){
        m++;
     }
     a[tmp_int] = tmp; 
     
  }
  fclose(fp);

  if(m!=n) {
   printf("A is not set"); 
   fclose(fp1);
   return false; 
  } 
   

  int n1;
  fread(&n1,1,sizeof(n),fp);
  if(n1!=n) printf("A size <> B size");
  float b[10000] ={0,} ;
  int m1 = 0;
  for(int i=0;i<n1;++i){
     float tmp;
     fread(&tmp,1,sizeof(tmp),fp); 
     unsigned tmp_int = (unsigned)(tmp *12357000) %10000;   
     if(b[tmp_int]<0.0000001){
        m1++;
     }
     b[tmp_int] = tmp; 
     
  }
  fclose(fp);
  
  if(m1!=n1){
     printf("B is not set");
     fclose(fp1);
     return false; 
  } 
     
  int k=0;
  bool res =true; 
  for(int i=0;i<10000;++i){
     if(a[i]>0.000001) {k++;}
     if(a[i]!=b[i]){
        printf("A & B differs in %d-th index element for elements(%d) %f %f ", k,i,a[i],b[i]);
        res = false;
        break; 
    }
    
  }
  fclose(fp1);  
  return res;
}



int main(){
  printf("start test data:\n");
  create0("test0_7_7.dat", 7,7);
  create0("test0_9_7.dat", 9,7);
  create0("test0_1999_1999.dat", 1999,1999);
  create0("test0_2008_1999.dat", 2008,1999);
/*
  create1("test0_7_7.dat", 7,7);
  create1("test0_9_7.dat", 9,7);
  create1("test0_1999_1999.dat", 1999,1999);
  create1("test0_2008_1999.dat", 2008,1999);*/

  for(int i=0;i<4;++i){
    printf("\n input:");
    //showFile(test_files1[i]); 
    formSetFileTest(test_files1[i],res_files1[i]);
    printf("\n result:");
    //showFile(res_files1[i]); 
  }

  for(int i=0;i<2;++i){
    formSetFile(test_files1[i],res_files2[i]);
    //isEqualSetFileTest(res_files2[i],res_files1[i]);
    showFile(res_files2[i]); 
  }

/*
  printf("\n\nPolynome tests\n");
  PolyFile t;
  inputPolyFile(&t);
  maxIndexPolyFile(&t,predicatDouble1);*/

}
