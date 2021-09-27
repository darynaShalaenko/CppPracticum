#include<stdio.h> 
#include <string.h>

#include <ctype.h>

int main() { 
 char a[100] = "23ab+cd+5"; // "23ab+cd+5\0" 
 char b[100];
 char buf[100];
 int k =0; 

 // input 
 //scanf("%s", a); 

 // input 2
 fgets(a, 20, stdin);

 for (int i = 0; i < strlen(a); i++) 
 { 
    //if(a[i] >= '0' && a[i]<='9') 
    if(isdigit(a[i]))
    {
       // no action
      continue;
    } 

    b[k] = a[i];
    k++;
   if(a[i]=='-' || a[i]=='+'){
    b[k] = a[i];
    k++;
    } 


 } 

 
for (int i = 0; i < strlen(b); i++) 
 {
  printf("%c", b[i]);
 }

 //printf("\n %s",b);
 puts(b);

}
