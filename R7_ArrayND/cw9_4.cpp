
#include <iostream>
#include <cstdlib>
using namespace std;

int** Create(int n) {
    int** a = (int**) malloc(n * sizeof *a);
    if (a == nullptr)
        exit(1);
    for (int i = 0; i < n; i++) {
        a[i] = (int*) calloc(n, sizeof **a);
        if (a[i] == nullptr)
            exit(1);
    }
    return a;
}

int** Multiply(int** a, int** b, int n) {
    int** c = Create(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    return c;
}

void Out(int** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}

int** Input(int n) {
    int** a = Create(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<"matrix["<<i+1<<"]"<<"["<<j+1<<"] = ";
            cin >> a[i][j];
        }
    }
    return a;
}

int main() {
    int n;
    cout<<"n = ";
    cin >> n;
    cout << "First matrix : " << endl;
    int** a = Input(n);
    cout << "Second matrix : " << endl;
