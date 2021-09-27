#include <stdio.h>
#include <stdlib.h>

typedef struct MyStack{

   int data;
   struct MyStack* ptr; 
} MyStack;

int main(){

  int x;
  MyStack* p = NULL;
  MyStack* z;

 do {
   scanf("%d",&x);
   if(x==0) break;
   z = (MyStack*) malloc(sizeof(MyStack));
   z->data = x; // (*z).data = x 
   z->ptr = p;
   p = z;
 }while(z!=NULL);

 while(p){
   z = p;  
   printf("%d",p->data);
   int x = p->data;
   // TODO
   
   p = p->ptr;
   free(z);
 }

}


/*

  int a[100];
  scanf("%d",&x);
  a[i++] = x


  
  n=i;
  tmp = (int*) malloc(n*sizeof(a[0]));

  return tmp;

*/
