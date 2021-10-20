
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TDATA {
int Key;
char Data[10];
} TDATA;

int input(TDATA* t) {
  printf("input key data");
  scanf("%d", &(t->Key));
   scanf("%s", t->Data);

  return 0;
}

int add_t(const char* filename) {
TDATA t;
int n;
FILE* f1 = fopen(filename, "wb");
 scanf("%d",&n);
for (unsigned i = 0; i <n; i++) {
 input(&t);
 //printf("%s",t.Data);
 fwrite(&t, 1, sizeof(t), f1); 
}
fclose(f1);
}


TDATA find(int x, char* fname){
   TDATA res;
   char str[10];
   FILE* f = fopen(fname, "rb");

   while(!feof(f)){
    int r =fread(&res, 1, sizeof(res), f);
    printf(", %d %s; ", res.Key, res.Data);
    if(res.Key==x){
        
     
     return res;
 }
    if(r<sizeof(res)) break;
   }
   strcpy(res.Data,"NoData");
   return res;
} 

int main() {
add_t("4_2_8_file.bin");

 TDATA r = find(2, "4_2_8_file.bin");

 printf("s= %s", r.Data); 

}

