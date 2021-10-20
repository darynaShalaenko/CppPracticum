#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* ReadFile(char *file)
{
    char *buf = NULL;
    int string_size, read_size;
    FILE *h = fopen(file, "r");

    if (h)
    {
        fseek(h, 0, SEEK_END);
        string_size = ftell(h);
        rewind(h);

        buf = (char*) malloc(sizeof(char) * (string_size + 1) );

        read_size = fread(buf, sizeof(char), string_size, h);

        buf[string_size] = '\0';

        if (string_size != read_size)
        {
            free(buf);
            buf = NULL;
        }

        fclose(h);
    }

    return buf;
}

struct set
{
    int arr[100000];
    int n;
};


bool checkIn(int n, struct set* mySet)
{
    for( int i = 0; i < mySet->n; ++i)
    {
        if (mySet->arr[i] == n)
        {
            return true;
        }
    }
    return false;
}

void addToSet(struct set* mySet, int n)
{
    if (!checkIn(n, mySet))
    {
        mySet->arr[mySet->n] = n;
        mySet->n++;
    }
}

void printSet(struct set* mySet)
{
    for( int i = 0; i < mySet->n; ++i)
    {
        printf("%d\n", mySet->arr[i]);
    }
}

int findMax(struct set* mySet)
{
    int temp = INT32_MIN;
    for( int i = 0; i < mySet->n; ++i)
    {
        if (mySet->arr[i] > temp)
        {
            temp = mySet->arr[i];
        }
    }
    return temp;
}

int findMin(struct set* mySet)
{
    int temp = INT32_MAX;
    for( int i = 0; i < mySet->n; ++i)
    {
        if (mySet->arr[i] < temp)
        {
            temp = mySet->arr[i];
        }
    }
    return temp;
}

struct set* setUnion(struct set* set1, struct set* set2)
{
    struct set* res;

    for (int i = 0; i < set1->n; ++i)
    {
        addToSet(res, set1->arr[i]);
    }
    for (int i = 0; i < set2->n; ++i)
    {
        addToSet(res, set2->arr[i]);
    }

    return res;
}

struct set* setIntersection(struct set* set1, struct set* set2)
{
    struct set* res;

    for (int i = 0; i < set1->n; ++i)
    {
        if (checkIn(set1->arr[i], set2))
        {
            addToSet(res, set1->arr[i]);
        }
    }

    return res;
}

struct set* setDiff(struct set* set1, struct set* set2)
{
    struct set* res;

    for (int i = 0; i < set1->n; ++i)
    {
        if (!checkIn(set1->arr[i], set2))
        {
            addToSet(res, set1->arr[i]);
        }
    }

    return res;
}

int transferToList(char* fileName, struct set* mySet)
{
    mySet->n = 0;
    char *string = ReadFile(fileName);

    if (string)
    {
        char * token = strtok(string, "\n");
        while( token != NULL ) 
        {
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
    struct set test;
    transferToList("file.txt", &test);
    struct set test2;
    transferToList("file2.txt", &test2);
    struct set res;
    res = *setUnion(&test, &test2);
    printf("Union fo set1 & set2:\n");
    printSet(&res);

    return 0;
}