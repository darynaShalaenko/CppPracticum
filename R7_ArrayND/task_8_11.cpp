

#include <iostream>

using namespace std;
#define N 20
#define M 20

void inp(double arr[N][M],int n, int m)
{
    int array[n][m];
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ",i);
        for (int j = 0; j < m; j++) {
            scanf("%lf",&arr[i][j]);
        }
    }
}

void print(double arr[N][M],int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transp(double arr[N][M], int n, int m)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < m; j++) {
            double x = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = x;
        }
    }
}

int sum(double arr[N][M], int n, int m, int k)
{
    int summa = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i-j==k)
            {
                summa += arr[i][j];
            }
        }
    }
    return summa;
}

void changecol(double arr[N][M], int n, int m, int n1, int n2)
{
    double x[N];
    for (int i = 0; i < n; i++) {
        x[i] = arr[i][n1];
    }
    for (int i = 0; i < n; i++) {
        arr[i][n1] = arr[i][n2];
        arr[i][n2] = x[i]; 
    }
}

void mintomaxcol(double arr[N][M], int n, int m)
{
    double max = 0;
    double min = 10000000;
    int maxk,mink;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                maxk = j;
            }
            if(arr[i][j] < min)
            {
                min = arr[i][j];
                mink = j;
            }

        }
        printf("maxel = %lf minel = %lf\n",max,min);

    }
    changecol(arr, n, m, maxk, mink);
}

int main()
{
    int n,m;
    printf("N = ");
    scanf("%d",&n);
    printf("M = ");
    scanf("%d",&m);
    double arr[N][M];
    inp(arr,n,m);
    print(arr,n,m);
    mintomaxcol(arr,n,m);
    print(arr,n,m);
    printf("%d",sum(arr,n,m,1));
}
