/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 100
int main()
{
char s[maxsize],slovo[maxsize], *word; //s-iskomaya stroka; *word-slovo.
int i, len, stringlen, maxlen; //len-dlina slova; stringlen-dlina stroki; maxlen- maximalnaya dlina slova;
FILE *f1, *f2;
f1=fopen("1.txt", "r+t");
fgets(s,256,f1);
fclose(f1);
//printf("Text:%s\n",s);
stringlen=strlen(s);
word=strtok(s," ,.!?/");
char* longest_word = NULL;
while(word!=NULL)
{
len=strlen(word);
if(len>maxlen)
{
   maxlen=len;
   if (longest_word)
   {
      free(longest_word);
   }
   longest_word = malloc(sizeof(char) * (len + 1));
   strncpy(longest_word, word, len + 1);
}
word=strtok(NULL," ,.!?");
}
//printf("Lenth of the longest word:%i\n",maxlen);
//printf("Longest word is:%s\n", longest_word);
f2=fopen("2.txt", "w+t");
fprintf(f2, "%s", longest_word);
fclose(f2);
free(longest_word);
}

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 100
int main()
{
char s[maxsize],slovo[maxsize], *word; //s-iskomaya stroka; *word-slovo.
int i, len, stringlen, maxlen; //len-dlina slova; stringlen-dlina stroki; maxlen- maximalnaya dlina slova;
FILE *f1, *f2;
f1=fopen("1.txt", "r+t");
fgets(s,256,f1);
fclose(f1);
//printf("Text:%s\n",s);
stringlen=strlen(s);
word=strtok(s," ,.!?/");
char* longest_word = NULL;
while(word!=NULL)
{
len=strlen(word);
if(len>maxlen)
{
   maxlen=len;
   if (longest_word)
   {
      free(longest_word);
   }
   longest_word = malloc(sizeof(char) * (len + 1));
   strncpy(longest_word, word, len + 1);
}
word=strtok(NULL," ,.!?");
}
//printf("Lenth of the longest word:%i\n",maxlen);
//printf("Longest word is:%s\n", longest_word);
f2=fopen("2.txt", "w+t");
fprintf(f2, "%s", longest_word);
fclose(f2);
free(longest_word);
}

