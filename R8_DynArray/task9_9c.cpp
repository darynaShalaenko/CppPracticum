
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void delete_matrix(int** a, int n) {
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}

int** random_matrix(int m, int n) {
    int **Arr; 
    Arr = new int*[m]; 
    for (int i = 0; i < m; i++)
    {
        Arr[i] = new int[n]; 
        for (int j = 0; j<n; j++) Arr[i][j] = rand()%100;
    }
    return Arr;
}

void print_matrix(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

void find_max(int** a, int n, int m, int& max_row, int& max_column) {
    int max=a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]>max){
                max=a[i][j];
                max_row=i;
                max_column=j;
            }
        }
    }
}



int** delete_column(int** Arr, int k, int n, int m)
{
    int** Arr2;
    Arr2 = new int*[m];
    for (int i = 0; i < n; i++)
    {
        Arr2[i] = new int[n-1]; 
        int pos = 0; 
        for (int j = 0; j < m; j++)
        {
            if (j != k) 
            {
                Arr2[i][pos] = Arr[i][j];
                pos++;
            }	
        }
    }
    return Arr2;
}


int** delete_row(int** a, int k, int n, int m)
{
    for (int i = k; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++) a[i][j] = a[i+1][j];
    }
    return a;
}


int main(void)
{
    int m,n;

    cout<<"Введите размерность 2-мерной матрицы(через пробел) : ";
    cin>> n >> m;
    int** Arr=random_matrix(n,m);
    print_matrix(Arr,n,m);

    int max_row, max_column;
    find_max(Arr,n,m,max_row,max_column);
    cout<< endl << "Полученная матрица : " << endl;

    int** Arr2=delete_column(Arr,max_column,n,m);
    Arr2=delete_row(Arr2,max_row,n, m-1);
    print_matrix(Arr2,n-1,m-1);
    delete_matrix(Arr,n);
    delete_matrix(Arr2,n);
{
   int m,n;
    cout<<"Введите размерность 2-мерной матрицы(через пробел) : ";
    cin>> n >> m;
    int** Arr=random_matrix(n,m);
    print_matrix(Arr,n,m);

    int p,min_abs=find_abs_min(Arr,n,m);

    int* min_row = new int[n];
    find_rows(Arr,n,m,min_abs,min_row,p);


    int k = 0;
    while (k < p)
    {
        Arr=delete_row(Arr, min_row[k] - k, n, m);
        k++;
    }

    cout<< endl << "Полученная матрица : " << endl;
    print_matrix(Arr,n-k,m);


    delete_matrix(Arr,n-k);
}

    return 0;
}
