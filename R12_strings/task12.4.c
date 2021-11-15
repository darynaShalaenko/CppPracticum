 
/*
 task 14.4, 12.4
 Ввести рядок, що складається з символів латинського алфавіту,слова в якому
  відокремлені пробілами (одним або декількома). Перетворити кожне слово в
  рядку, видаливши з нього всі входження останньої літери цього самого
  слова (кількість пробілів між словами не змінювати).
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int remove_end_word(char* s){
   int start=0;
   int fin=0;
   bool space=true;

   int len_str = strlen(s);
   
   int k=0;

   for(size_t i=0;i<len_str;i++){
       //if(s[i]==' ' || s[i]=='\0') {
       if(isspace(s[i+1]) || s[i+1]=='\0'){ 
           if(!space){
              memmove(&s[i],&s[i+1],len_str-i);
           }
          
          space = true;
       }
       else{
           
          space = false;  
       }   
   }
  return 0;
}


int main(){

  char inp_str[100];
  fgets(stdin,inp_str);

  printf("\ninput=%s",inp_str);
  remove_end_word(inp_str);
  pritf("\n The words without end = %s\n",inp_str);
}
