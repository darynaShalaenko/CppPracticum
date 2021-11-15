#include <iostream>

using namespace std;

const int n = 3;

void printMatrix(int A[][n], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << A[i][j] << "  ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    int A[n][n] = {{1,2,3},{4,5,6},{7,8,9}};
    printMatrix(A, n);
    int B[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[j][n-i-1] = A[i][j];
    printMatrix(B, n);
    return 0;
}
