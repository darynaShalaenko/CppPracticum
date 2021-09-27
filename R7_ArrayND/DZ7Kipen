//peremnozhyty 2 matr. mxn i nxk
#include <stdio.h>
#define N 10
#define m 2
#define n 3
#define k 5
void inpmatr1(int A[N][N], int m, int n);
void inpmatr2(int B[N][N], int n, int k);
void multmatr(int A[N][N], int B[N][N], int C[N][N], int m, int n, int k);
void outmatr(int C[N][N], int m, int k);
int main()
{
    int a[N][N], b[N][N], c[N][N];
    void inpmatr1(a, m, n); void inpmatr2(b, n, k);
    void multmatr(a, b, c, m, n, k);
    void outmatr(c, m, k);
}
void inpmatr1(int A[N][N], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &A[m][n]);
        }
           
}
void inpmatr2(int B[N][N], int n, int k)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
        {
            printf("b[%d][%d] = ", i, j);
            scanf("%d", &B[n][k]);
        }

}
void multmatr(int A[N][N], int B[N][N], int C[N][N], int m, int n, int k)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += (A[i][k] * B[k][j]);
        }
        
}
void outmatr(int C[N][N], int m, int k)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            printf("%d", C[m][k]);
}
