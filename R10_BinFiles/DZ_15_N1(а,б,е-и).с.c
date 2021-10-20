#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

struct set{
    int arr[100000];
    int n;
};


bool checkIn(int n, struct set* mySet) {
    for( int i = 0; i < mySet->n; ++i) {
        if (mySet->arr[i] == n) {
            return true;
        }
    }
    return false;
}

void addToSet(struct set* mySet, int n) {
    if (!checkIn(n, mySet)) {
        mySet->arr[mySet->n] = n;
        mySet->n++;
    }
}

void printSet(struct set* mySet) {
    for( int i = 0; i < mySet->n; ++i) {
        printf("%d\n", mySet->arr[i]);
    }
}

int findMax(struct set* mySet) {
    int temp = INT32_MIN;
    for( int i = 0; i < mySet->n; ++i) {
        if (mySet->arr[i] > temp) {
            temp = mySet->arr[i];
        }
    }
    return temp;
}

int findMin(struct set* mySet) {
    int temp = INT32_MAX;
    for( int i = 0; i < mySet->n; ++i) {
        if (mySet->arr[i] < temp) {
            temp = mySet->arr[i];
        }
    }
    return temp;
}

struct set* setUnion(struct set* set1, struct set* set2) {
    struct set* res;

    for (int i = 0; i < set1->n; ++i) {
        addToSet(res, set1->arr[i]);
    }
    for (int i = 0; i < set2->n; ++i) {
        addToSet(res, set2->arr[i]);
    }

    return res;
}

struct set* setIntersection(struct set* set1, struct set* set2) {
    struct set* res;

    for (int i = 0; i < set1->n; ++i) {
        if (checkIn(set1->arr[i], set2)) {
            addToSet(res, set1->arr[i]);
        }
    }

    return res;
}

struct set* setDiff(struct set* set1, struct set* set2) {
    struct set* res;

    for (int i = 0; i < set1->n; ++i) {
        if (!checkIn(set1->arr[i], set2)) {
            addToSet(res, set1->arr[i]);
        }
    }

    return res;
}

int transferToList(char* fileName, struct set* mySet) {
    mySet->n = 0;
    char *string = ReadFile(fileName);

    if (string)
    {
        char * token = strtok(string, "\n");
        while( token != NULL ) {
//            printf(token);
            int temp = atoi(token);
            addToSet(mySet, temp);
            token = strtok(NULL, "\n");
        }
        free(token);
        free(string);
    }

}


int main()
{
//    PrintReverse("file.txt", "out.txt");
    struct set test;
    transferToList("file.txt", &test);
    struct set test2;
    transferToList("file2.txt", &test2);
    struct set res;
//    printf("\n");
//    printf("Set1:\n");
//    printSet(&test);
//    printf("Set2:\n");
//    printSet(&test2);
    res = *setUnion(&test, &test2);
    printf("Union fo set1 & set2:\n");
    printSet(&res);
//    printf("Max: %d\n", findMax(&test));
//    printf("Min: %d\n", findMin(&test));

    return 0;
}