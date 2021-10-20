#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100

int main(){

   char mas[N]; 
   char* fname = "t401.txt";
   FILE *fp;
   char c;
   int k =0;

   fp = fopen(fname, "rt");
   while(!feof(fp)){
      //if() break;
      c=fgetc(fp);
      mas[k++] = (char) c;            
  }

  for(int i=0;i<k;++i){
     printf("%c,",mas[i]);
  }

  fclose(fp);

  FILE* fp1;

  char fname2[20];

  strcpy(fname2,fname);
  strcat(fname2,(char*)"_upper.txt");   
  printf("f=%s",fname2);
 
  fp1 = fopen(fname2,"wt");
  for(int i=0;i<k;++i){
     if(isupper(mas[i])){
        fputc(tolower(mas[i]),fp1);     } 
     else{
      fprintf(fp,"%c,",mas[i]);
     }
  }

  fclose(fp1);

}
