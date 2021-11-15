#include <iostream>
using namespace std; //9.9f

float** input_matrix(int n, int m)
{
    float **Mas = new float *[n];
    for (int i = 0; i < n; ++i)
        Mas[i] = new float [m];


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Mas[i][j];
        }
    }            
    return Mas;
}

float** empty_matrix(int n, int m)
{
    float **Mas = new float *[n];
    for (int i = 0; i < n ; ++i)
        Mas[i] = new float [m];


    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Mas[i][j] = 0;
        }
    }            
    return Mas;
}

void print_matrix(float** Mas, int n, int m) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("\n");
        for (int j = 0; j < m; j++) 
            cout << Mas[i][j] << " ";

    }

}

void del_matrix(float** Mas, int n)
{
    for (int i = 0; i < n; i++)
        delete[] Mas[i];
    delete [] Mas;
}

int main()
{
    int n, m, c, k, b;
    printf("Enter the size of matrix ");
    scanf("%d %d", &n, &m);
    printf("Enter the count of rows you want to add  ");
    scanf("%d",&b);

    while(true)
    {
        printf("Enter the postiton, you want to begin adding to  ");
        scanf("%d",&k);

        if(k <= n)
            break;

    }

    k -= 1;
    c = n + b;

    float** Mas = input_matrix(n, m);
    float** Mas_2 = empty_matrix(c, m);

    for(int i = 0; i < k  ; i++)
        for(int j = 0; j < m; j++)
            Mas_2[i][j] = Mas[i][j];

    for (int i = 0; i < n - k ; i++)
            for (int j = 0; j < m; j++)
                Mas_2[i + k + b][j] = Mas[i + k][j];

    for(int i = k; i <= k + b - 1; i++)
    {
        printf("Enter the row, you want to add ");
        for(int j = 0; j < m; j++)
         cin >> Mas_2[i][j];
    }   

     print_matrix(Mas_2, c, m);

     del_matrix(Mas, n);
     del_matrix(Mas_2, n);

int n, m, c, k;
    printf("Enter the size of matrix ");
    scanf("%d %d",&n,&m);
    while(true)
    {
        printf("Enter the postiton, you want to add ");
        scanf("%d",&k);

        if(k <= n)
            break;

    }
    k = k - 1;
    c = n + 1;

    float** Mas = input_matrix(n, m);
    float** Mas_2 = empty_matrix(c, m);

    for(int i = 0; i < k  ; i++)
        for(int j = 0; j < m; j++)
            Mas_2[i][j] = Mas[i][j];


   for (int i = 0; i < n - k; i++)
            for (int j = 0; j < m; j++)
                Mas_2[i + k + 1][j] = Mas[i + k][j];

    for(int i = k; i <= k; i++)
    {
        printf("Enter the row, you want to add ");
        for(int j = 0; j < m; j++)
         cin >> Mas_2[i][j];
    }   

    print_matrix(Mas_2, c, m);


}



