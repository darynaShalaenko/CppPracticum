#include <iostream>

using namespace std;

void swap_two(int *A, int i, int j){ //просто м≥н€Їмо м≥сц€ми два елементи
    int s = A[i];
    A[i] = A[j];
    A[j] = s;
}

bool next_exist(int *A, int N){ //чи Ї наступна перестановка (€кщо н≥ то нема сенсу продовжувати)
    int j = N - 2;
    while (j != -1 && A[j] >= A[j + 1]) j--;
    if (j == -1)
        return false;
    int k = N - 1;
    while (A[j] >= A[k]) k--;
        swap_two(A, j, k);
    int l = j + 1, r = N - 1;
    while (l<r)
        swap_two(A, l++, r--);
    return true;
}

int main(){
    int N, *A;
    cout << "N = ";
    cin >> N;
    A = new int[N];
    for (int i = 1; i<=N; i++){
        A[i-1] = i;
        cout << A[i-1] << " ";
    }
    cout << endl;
    while (next_exist(A, N)){
        for (int i=0; i<N; i++){
            cout << A[i] << " ";
        }
        cout << endl;
    }
}
