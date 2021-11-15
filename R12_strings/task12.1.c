
/*
Передумова:
В даній групі задач потрібно реалізувати функції та в тих функціях де
потрібно виводити рядок зробіть 2 варіанти: 
результат записати в новий рядок; 
результат замінює рядок, що є аргументом функції. 
В даному рядку знайти підядок який знаходиться між першою 
двокрапкою та наступню за нею комою. 
*/

#include <cstdio>
#include <cstring>

int semicolumn(const char* s, char* out){
   
   size_t n = strlen(s);
   size_t first_coma = -1;
   for(size_t i=0;i<n;i++){
       if(s[i]==':') {
            first_coma = i;

	    break;	
       }
   }
   if(first_coma==-1) {
      out[0] ='\0';
      return -1;
   }
   size_t result_size = 0;
   for(size_t i=first_coma+1;i<n;i++){
            out[result_size++] = s[i];
       if(s[i]==',') {
            out[result_size] ='\0';
	    return result_size;	
       }
   }
   out[result_size] ='\0';  
   return result_size;
}



int semicolumn_inplace(char* s){

  size_t n = strlen(s);
   size_t first_coma = -1;
   for(size_t i=0;i<n;i++){
       if(s[i]==':') {
            first_coma = i;
	    break;	
       }
   }

   if(first_coma==-1) {
     s[0] ='\0';
     return -1;
   }
   size_t result_size = 0;
   for(size_t i=first_coma+1;i<n;i++){
            s[result_size++] = s[i];
       if(s[i]==',') {
            s[result_size] = '\0'; 
	    return result_size;	
       }
   }
   s[result_size] = '\0';   
   return result_size;
}

int main(){


   char test[][100] ={"fgdsf:fsdgdsafgd,sdgdsg",
                      "dsfg,sd:gdsfg",
                      "fdgdsf,g"};
 
   for(int i=0;i<3;++i){
       char s1[100];
       semicolumn(test[i],s1);
       printf("%s\n", s1);
   }


   char s[100];
   scanf("%s\n",s);  

   char s1[100];
   semicolumn(s,s1);
   printf("%s\n", s1);

   semicolumn_inplace(s); 
   printf("%s", s);
}
