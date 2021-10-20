
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int high;
  char name[20];
} Mountain;

#define N 10

int vvod(Mountain* mt){
  printf("Mountain(name, high):"); 
  scanf("%s",mt->name);
  scanf("%d",&(mt->high));
}

int print(Mountain mnt){
  printf("Mnt(%s, %d):",mnt.name,mnt.high); 
}

void highest(const Mountain* mnts, int n){
  int max = mnts[0].high;
  int ind =0;
  for(int i=1;i<n;++i){
       if(max<mnts[i].high){
           max = mnts[i].high;
           ind = i;
       }
  }
  printf("\nName of highest mountain is %s\n", mnts[ind].name);
}

void heighName(const Mountain* mnts, int n, const char * mname){
  
  for(int i=0;i<n;++i){
       if(strcmp(mname, mnts[i].name)==0){
           printf("\nHeight of %s is %d\n",mname, mnts[i].high);
           return;
       }
  }
  printf("\nNo mountain %s\n", mname);
}

int main(){

  int n;
  printf("N=");
  scanf("%d",&n);
  
  //Mountain* arr = malloc(n*sizeof(Mountain));

  Mountain arr_test[] ={ {8849,"Everest"}, {8611,"K2"}, {4207,"Mauna-Kea"}};
  
  highest(arr_test,3); 
  heighName(arr_test,3, "K2");
  heighName(arr_test,3, "K3");

  Mountain arr[N];
  for(int i=0;i<n;++i){
    vvod(&arr[i]);
  }

  highest(arr,n);
  printf("Name of the mountain:"); 
  char name[20]; 
  scanf("%s", name); 
  heighName(arr, n, name);
  
  //free(arr);
}

