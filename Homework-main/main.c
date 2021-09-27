// Project_Classdouble complex.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <tgmath.h>


#define INITIAL_CAPACITY 3
#define N 200
#define pi 3.14

int charToInt(char c) {
    return c - '0';
}


double x(int n)
{
    return n;
}

double complex* fur(double complex x[N])
{
    double M = N;
    M = M * M;
    double complex* X = malloc(16000*16);
    int n, k = 0;

    // Прямое преобразование Фурье
    for (k = 0; k < N; k++)
    {
        X[k] = 0 + 0 * I;
        for (n = 0; n < N; n++)
        {

            double complex temp;
            temp= (cos(((-2 * pi * k * n) / M) * pi / 180))+ I*(-sin(((-2 * pi * k * n) / M) * pi / 180));
            X[k] = X[k] + (x[k] * temp);


        }
    }

    return X;
}

double complex* ifur(double complex X[N])
{
    double M = N;
    M = M * M;
    double complex* x = malloc(16000*16);;
    int n, k =0;
    for (k = 0; k < N; k++)
    {
        x[k] = 0 + 0 * I;
        for (n = 0; n < N; n++)
        {

            double complex temp;
            temp= (cos(((-2 * pi * k * n) / M) )) + I*(sin(((-2 * pi * k * n) / M) ));
            x[k] = x[k] + (X[k] * temp);
        }

        x[k] = x[k] * (1 / (M));


    }
    return x;
}

int main()
{
    int i = 0;
    int count = 0;
    double complex* A = malloc(16000*16);;
    double complex* B = malloc(16000*16);;
    double complex* C = malloc(16000*16);;
    FILE* fp;
    char name[] = "T.txt";
    fp = fopen(name, "w");
    if (fp == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    for ( i = 0; i < N; i++)
    {
        int k = rand();
        fprintf(fp, "%d\n", k);
    }
    fclose(fp);
    fp = fopen(name, "r");
    if (fp == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    char a[80];
    int j = 0, k = 0;
    for (i = 0;i < N;i++)
    {
        char* pr = "1234567890";
        fgets(a,80, fp);
        int sum = 0;
        int c = 0;
        for (k = 0; k < 8; k++)
        {
            for (j = 0; j < 10; j++)
            {
                if (a[k] == pr[j])
                {
                    //printf("%d\n", charToInt(a[i]));
                    sum = sum*10 + charToInt(a[i]) ;
                    //printf("%d\n", sum );
                    c++;
                }

            }
        }
        double sum1 = (double) sum;
        B[i]= sum1 + I*0;


    }
    for (i = N-1;i >= 0;i--)
    {
        A[count] = B[i];
        count++;
        printf("%d\n", i );
    }
    A = ifur(A);
    for (i = 0; i < N; i++)
    {
        double complex c= A[i] * B[i];
        C[i] = c;
    }
    C = fur(C);

    for ( i = 0; i < 10; i++)
    {
        printf("%f + %f * i\n", creal(C[i]) , creal(C[i]));
    }
    fclose(fp);


}
