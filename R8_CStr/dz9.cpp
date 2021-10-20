#include <stdio.h>
#include <string.h>

int symmetry(char *word)
{
    int size = strlen(word);
    for(int i = 0;i < size/2; i++)
    {
        if(word[i] != word[size-i-1])
        {
            printf("Not");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}


void inversion(char *word)
{
    int size = strlen(word);
    char *iword[size];
    for(int i = 0; i < size; i++)
    {
        strcpy(iword, word);
        word = word[size-i];
        word[size-i] = iword;
    }
    printf("%s", iword);
}

int main()
{
    char *a[10];
    printf("word ");
    scanf("%s", &a);
    inversion(a);
    symmetry(a);
}

#define N 5

void delete(char word[], int b, int c)
{
    int i, j;
    for(i=j=0;word[i]!='/0';i++)
    {
        if(word[i]!=c)
        {
            if(word[i+1]!=b)
            {
                word[j++] = word[i]; word[j]='/0';
            }
        }
    }
}

int main()
{
    int c, b;
    char array[N];
    int i;
    for (i=0; i<N; i++)
    {
        printf("a[%d]= ",i);
        scanf("%d", &array[i]);
    }
    delete(array, b, c);
}