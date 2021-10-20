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


void PrintReverse(char *fileName, char *toFile) {
    char *string = ReadFile(fileName);
    FILE *fp;
    fp=fopen(toFile, "w");
    if(fp == NULL)
        exit(-1);


    if (string)
    {
        char * token = strtok(string, "\n");
        while( token != NULL ) {
            int temp = strlen(token);
            for(int i = temp -1; i >=0; --i) {
                fprintf(fp, "%c", token[i]);
            }
            fprintf(fp, "\n");

            token = strtok(NULL, "\n");
        }
        free(token);
        free(string);
    }
}

void PrintZeroToOne(char *fileName, char *toFile) {
    FILE *fp;
    fp=fopen(toFile, "w");
    if(fp == NULL)
        exit(-1);


    char *string = ReadFile(fileName);
    if (string)
    {
        for(int i = 0; i < strlen(string); ++i) {
            if (string[i] == '0') {
                fprintf(fp,"%c", '1');
            } else if(string[i] == '1') {
                fprintf(fp,"%c", '0');
            } else {
                fprintf(fp, "%c", string[i]);
            }
        }
        free(string);
        fclose(fp);
    }
}

int main()
{
//    PrintReverse("file.txt", "out.txt");
    PrintZeroToOne("file.txt", "out.txt");
    return 0;
}