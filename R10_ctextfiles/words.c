#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//maximum number of words and rows
#define N 20

int main(){

   FILE* fp;
   fp = fopen("1.txt","rt");

   char str[N]; // string of N symbols
   char* words[N]; // N strings(words) of ? symbols
   int i,j;
   int len; // length of the word
   int wcount=0; // counter for words
 
   while(fgets(str,N, fp)!=NULL){ // read the lines
      //printf("%s",str); // doubug output of words
      j=-1;
      len=0; // length is zero at the start 
      for(i=0;i<strlen(str);i++){ // iterates on the line
	if(isalpha(str[i])){ // if symbols is letter
           if(len==0){  // start new word
              j=i;
           }   
           len++;  // or increase the length of the word
        }
       else{
           if(len!=0){ // if the word is ended
              words[wcount] = malloc(len+1); // allocate memory for word and END_of string symbol
              memmove(words[wcount],&str[j],len); // copy word from str to words[wcount]
              words[wcount][len] ='\0'; // set end of string as the last symbol
              len=0; // length of new word is zero
              j=-1;
              wcount++; // counter of words increment            
           }
       } 
      // printf("%d %d %d",j,len,i); //debug
      }

   }

   for(i=wcount-1;i>=0;i--){ // output in inverse order
     printf("%s, ",words[i]);
   }

  
   for(i=0;i<wcount;i++){ // free memory
     free(words[i]);
   }

 fclose(fp); // close file
}
