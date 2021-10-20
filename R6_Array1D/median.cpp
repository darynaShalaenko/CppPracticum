#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int median(int n, int *a) {
    int max = a[0];
    int min = a[0];
    for (int i = 0; i < n; i++){
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    double midle = (max + min) / 2.0;
    int median = a[0];

    for (int i = 0; i < n; i++) {
        if (fabs(midle - median) > fabs(a[i] - median)){
            median = a[i];
        }
    }
    return median;
}

int main(){
    int n;
    cout << "enter length\n";
    cin >> n;
    int a[n];
    cout << "now elements\n";

    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << median(n, &a[0]);
}