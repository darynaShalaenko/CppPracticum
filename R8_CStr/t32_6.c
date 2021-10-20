#include<stdio.h> 
#include<string.h> 
#include <ctype.h>
#include <stdlib.h>

 int main() { 
  char a[100] = "23+5-32="; 
  char b[100]; 
  int k = 0; 
  int i = 0;
  fgets(a,20,stdin);

  int state = 1; //0 outside , 1 -inside

  int sum=0;
  int num=0;
 for(i=0;i<strlen(a);++i) {

    if(isdigit(a[i])){
       
       num*=10;
       //num += (a[i]-'0'); 
       char buf[2];
       buf[0]=a[i];
       buf[1]='\0';
       num += atoi(buf);
       
    }
    else if(a[i]=='+'){
        if (state==1) { 
           sum += num;
           num=0;
           state = 1; 
        }
        if (state==2) { 
           sum -= num;
           num=0;
           state = 1; 
        }

      }
     else if(a[i]=='-'){
         if (state==1) { 
           sum += num;
           num=0;
           state = 2; 
        }
        if (state==2) { 
           sum -= num;
           num=0;
           state = 2; 
        }
      }
    else if (a[i]=='='){

          if (state==1) { 
           sum += num;
           num=0;
       
        }
        if (state==2) { 
           sum -= num;
           num=0;
       
        }
        break; 
    }
    else{
     printf("wrong");
   }
   //printf("%d %d; ",num,sum);
  }

  printf("%d",sum);
 getchar(); 
} 
