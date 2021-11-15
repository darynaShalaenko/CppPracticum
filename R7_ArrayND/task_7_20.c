
#include <iostream>
using namespace std;
const int N = 100;

void input(int a[N][N], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        printf("\n");
        for(int j = 0; j < m; j++)
        {
            printf("Enter a[%d][%d] -- > ",i + 1, j + 1);
            cin >> a[i][j];
        }
    }
}

void print(int a[N][N], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for(int j = 0; j < m; j++)
            cout << a[i][j] << " ";
    }
}


int main()
{
    int n, m, k;
    int a[N][N],a1[N][N];

    printf("Enter the size of matrix ");
    scanf("%d %d",&n,&m);

    printf("Enter k = ");
    scanf("%d",&k);

    for(int i = 0; i < n; i++)
    {
        printf("\n");
        for(int j = 0; j < m; j++)
        {
            a1[i][j] = 0;
            cout << a1[i][j] << " ";
        }
    }

    input(a, n, m);
    print(a, n, m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            int c = j - k;
            if(c < 0)
                c += m;
            a1[i][c] = a[i][j];
        }

    printf("\n");

    print(a1, n, m);





}
