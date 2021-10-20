#include <stdio.h> 
#include <stdbool.h>

typedef 
struct Field{

  char col; // cols
  int row; // row

}Field;


int input(Field* x){
  Field res;   
  int t;
  printf("col=");
  scanf(" %c",&res.col);
  //printf("%i",g);
  //printf("kop=");
  scanf(" %d",&t);
  res.row = t;
  *x =res;
 return 0;
}


void vyvod(const Field x){
  printf("%C:%u ",x.col,x.row);
}


bool check(Field x, Field y){

  if(x.col == y.col) return true;
  if(x.row == y.row) return true;
  if(x.col - y.col == x.row - y.row) return true;

  return false;
}

int main(){

  //struct Money x;
  Field x,y;
  //x = vvod();
  input(&x); 
  vyvod(x);
  input(&y); 
  vyvod(y);

  if(check(x,y)){
    printf("correct");
  }
  else{
       printf("uncorrect");
   }

}

