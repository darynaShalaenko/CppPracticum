#include <stdio.h>
#include <stdlib.h>

int vvod(const int* arr, size_t n, const char* fname){

  FILE* fp = fopen(fname, "wb");

  if(fp==NULL) {
     printf("problem with file write");
     return -1;
  }

  for(size_t i=0; i<n;i++){
     fwrite(&arr[i], 1, sizeof(arr[i]), fp);
  }
  
  //fwrite(arr, n, sizeof(arr[0]),fp);

  fclose(fp);

  return EXIT_SUCCESS;
}

int vyvod(const char* fname){

  FILE* fp = fopen(fname, "rb");
   
  int res; 
  if(fp==NULL) {
     printf("problem with file read");
     return -1;
  }


  while(!feof(fp)){
     int item;
    res = fread(&item, 1, sizeof(item), fp); 
    if(res<sizeof(item)){break;} 

    printf("%d, ",item); 
   }
  

  fclose(fp);

  return EXIT_SUCCESS;
}

int append(const int* arr, size_t n, const char* fname){

  FILE* fp = fopen(fname, "ab");

  if(fp==NULL) {
     printf("problem with file write");
     return -1;
  }

  for(size_t i=0; i<n;i++){
     fwrite(&arr[i], 1, sizeof(arr[i]), fp);
  }
  
  //fwrite(arr, n, sizeof(arr[0]),fp);

  fclose(fp);

  return EXIT_SUCCESS;

}


int even(const char* fname){

  FILE* fp = fopen(fname, "rb");
   
  int res;
  int ev =0; 
  if(fp==NULL) {
     printf("problem with file read");
     return -1;
  }


  while(!feof(fp)){
     int item;
    res = fread(&item, 1, sizeof(item), fp); 
    if(res<sizeof(item)){break;} 

    //printf("%d, ",item); 
    if(item%2==0){ev++;}
   }
  

  fclose(fp);
  return ev;
}

int main(){

  char fname[10] = "set1.dat";
  int ar[10];

  int n;
  printf("n=");
  scanf("%d", &n);  

  for(int i=0;i<n;++i){
    scanf("%d",&ar[i]);
  }

  vvod(ar,n,fname);


  for(int i=0;i<2;++i){
    scanf("%d",&ar[i]);
  }

  append(ar,2,fname);
  vyvod(fname);

  int m= even(fname);
  printf("Even numbers are %d",m);

}

