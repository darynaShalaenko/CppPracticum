#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ReadFile(char *filename)
{
   char *buffer = NULL;
   int string_size, read_size;
   FILE *handler = fopen(filename, "r");

   if (handler)
   {
       // Seek the last byte of the file
       fseek(handler, 0, SEEK_END);
       // Offset from the first to the last byte, or in other words, filesize
       string_size = ftell(handler);
       // go back to the start of the file
       rewind(handler);

       // Allocate a string that can hold it all
       buffer = (char*) malloc(sizeof(char) * (string_size + 1) );

       // Read it all in one operation
       read_size = fread(buffer, sizeof(char), string_size, handler);

       // fread doesn't set it so put a \0 in the last position
       // and buffer is now officially a string
       buffer[string_size] = '\0';

       if (string_size != read_size)
       {
           // Something went wrong, throw away the memory and set
           // the buffer to NULL
           free(buffer);
           buffer = NULL;
       }

       // Always remember to close the file.
       fclose(handler);
    }

    return buffer;
}


void PrintFile(char *fileName) {
    char *string = ReadFile(fileName);
    if (string)
    {
        puts(string);
        free(string);
    }
}

void cntEmpty(char *fileName) {
    int counter = 0;
    int counter1 = 0;
    char *string = ReadFile(fileName);
    for(int i = 0; i < strlen(string); ++i) {
        if (string[i] == '\n') {
            counter1++;
        }
    }
    if (string)
    {
        char * token = strtok(string, "\n");
        while( token != NULL ) {
            counter++;
//            printf("%d", strlen(token));
//            printf( " %s\n", token ); //printing each token
            token = strtok(NULL, "\n");
        }
        free(string);
    }
    printf("%d\n", counter1 - counter + 1);
}



void cntMaxLen(char *fileName) {
    int counter = 0;
    char *string = ReadFile(fileName);
    if (string)
    {
        char * token = strtok(string, "\n");
        while( token != NULL ) {
            int temp = strlen(token);
            if (temp > counter) {
                counter = temp;
            }

            token = strtok(NULL, "\n");
        }
        free(string);
    }
    printf("%d\n", counter);
}

void PrintLong(char *fileName) {
    char *string = ReadFile(fileName);
    if (string)
    {
        char * token = strtok(string, "\n");
        while( token != NULL ) {
            int temp = strlen(token);
            if (temp > 60) {
                puts(token);
            }

            token = strtok(NULL, "\n");
        }
        free(token);
        free(string);
    }
    printf("\n");
}

int main()
{
    PrintFile("file.txt");
    cntEmpty("file.txt");
    cntMaxLen("file.txt");
    PrintLong("file.txt");
    return 0;
}