// homework 12: 7a)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long len;
    long max_len;
    char max_word[32];
    char * word;
    char * text;
    char delim[] = " \n";
    FILE * f = fopen("cw12-F.txt","r");
    fseek(f,0,SEEK_END);
    len = ftell(f);
    fseek(f,0,SEEK_SET);
    text = (char *)malloc((1 + len)*sizeof(char));
    fread(text, 1, len, f);
    text[len] = '\0';
    fclose(f);
    if(text)
    {
        max_len = (len = 0);
        word = strtok(text, delim);
        while(word)
        {
            printf("%s ",word);
            len = strlen(word);
            if(max_len < len)
            {
                strcpy(max_word, word);
                max_len = len;
            }
            word = strtok(NULL, delim);
        }
        printf("\nThe longest word: %s\n",max_word);

    }
}
