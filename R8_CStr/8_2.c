#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* inversion(char* a)
{
    int size = strlen(a);
    char* new_a = (char*)malloc(size);
    for (int i = 0; i < size; i++)
    {
        new_a[i] = a[size - i - 1];
    }
    return new_a;
}



int main()
{
    char a[31] = "";
    printf("Enter a string: ");
    scanf("%s", a);

    char* result = inversion(a);
    printf("%s", result);
    if (a == result)
    {
        printf("\nThe string is symmetric");
    }
    else
    {
        printf("\nThe string is not symmetric");
    }
    free(result);

}