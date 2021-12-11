#include<iostream>
#include<cstdlib>
using namespace std;

int** Make(int N, int M)
{
    int** a;
    a = new int * [N];
    for (int i = 0; i < N; i++)
    {
        a[i] = new int[M];
    }
    return a;
}

void Randomfill(int** a, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            a[i][j] = rand() % 10;
        }
    }
}

void Output(int** arr, int N, int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void Del(int** a, int row)
{
    for (int i = 0; i < row; i++)
    {
        delete[]a[i];
    }
    delete[]a;
}

int** Removestrings(int** a, int**b , int N, int& M){
    for (int i = 0; i < N/2; i++ ){
        for (int j = 0; j < M; j++){
            b[i][j]=a[2*i+1][j];
        }
    }
    return b;
}


int main()
{
    int N, M, k;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter M: ";
    cin >> M;
    k = N/2;
    cout << "k = "<< k << endl;
    int** a, **b;
    a = Make(N, M);
    b  = Make(k, M);
    Randomfill(a, N, M);
    cout << "Matrix : " << endl;
    Output(a, N, M);
    cout << "New matrix : " << endl;
    Removestrings(a,b,N,M);
    Output(b, k, M);

    Del(a, N);

}
