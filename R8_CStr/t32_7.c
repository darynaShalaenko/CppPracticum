#include <stdio.h>
#include <stdlib.h>

int toSystem(unsigned n, unsigned b, char* word){

  char digit[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
  int i=0;
  unsigned m=n;
  while(m){
     int d = m % b;
     
     word[i]= digit[d];
     //printf("(%d)%c,%s ",i,digit[i],word);
     m /= b;
     i++; 
  }
  word[i]='\0';
  //printf("s=%s",word);

  for(int j=0;j<(i+1)/2;j++){
    char tmp = word[j]; 
    word[j] = word[i-j-1];
    word[i-j-1] = tmp;

  }
  //printf("T=%s",word);
  //getchar();
 

return 0;
}


int main(){

 unsigned n,m,i,b;
 char word[100]; 

 scanf("%u", &n);
 scanf("%u", &b);

 if(b<=1 || b>16){
    printf("%d is forbidden base radix",b);
    return 1;
 }

 for(i=1;i<n;++i){
    toSystem(i,b,word);

    printf("w= %s\n",word);
 }
 
 

}
