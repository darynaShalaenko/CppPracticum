#include <stdio.h>
// #include <string.h>
#include <conio.h>
#include <stdlib.h>
#define INC_INPUT 10



/* Example cmd command:
C:\Users\Nikita\Desktop\KR>KR2 0 4 8 5 0 0 0 0 1 0 2      */
void main(int argc, char **argv)
{

if (argc  < 12) {
        printf("Incorrect inputs! Input exactly 11-digits with spaces UPC (example: >KR2 0 4 8 5 0 0 0 0 1 0 2 )! Current digits: %d/11", argc - 1);
        exit(INC_INPUT);
        getch();
    }


    char *upc = argv[argc - 1];
    int sumEven = 0; // сумма чётных
    int sumOdd = 0; // сумма нечётных

    //цикл для чётных
    for (int i = 1; i < argc; i=i+2)
    {
        int digit = argv[i][0] - '0'; ////преобразуем char в int
        sumEven +=  digit;
        // printf("%c ", argv[i][0]);
    }
    
    //цикл для нечётных
    for (int i = 2; i < argc - 1; i=i+2)

    {
        int digit = argv[i][0] - '0'; //преобразуем char в int
        sumOdd += digit;
        // printf("%c ", argv[i][0]);
    }

    sumEven *= 3;
    // printf("%s",upc);
    // printf("\n%d",sumEven);
    // printf("\n%d",sumOdd);
    int sum = sumEven + sumOdd; 
    // printf("\n%d",sum);    
    int d1 = abs(sum % 10 - 10); // находим наш х
    printf("UPC digit: %d\n",d1); // число искомое
    printf("UPC full num: "); // полное число

    for (int i =1; i < argc; i= i+1)
        printf("%c",argv[i][0]);
    printf("%i",d1);



}
