#include<stdio.h> 
#include<string.h> 
 int main() { 
  char a[100] = "23ph+cd+5"; 
  char b[100]; 
  int k = 0; 
  int i = 0;
 while( i < strlen(a)) {
  
      if (a[i] == 'p' && (i+1<strlen(a) && a[i + 1] == 'h')) { 
           b[k] = 'f'; 
          k++; i+=2; 
      } 
      else { 

        b[k] = a[i]; k++; 
        i++;
      } 
   } 
 b[k+1] ='\0';
 // for (int i = 0; i < strlen(b); i++) { printf("%c", b[i]); } 
 puts(b);
 getchar(); 
} 
