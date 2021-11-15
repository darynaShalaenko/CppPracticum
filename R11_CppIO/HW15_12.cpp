
//
//  main.cpp
//  HW15_12.05
//
//  Created by Air on 13.11.2021.
//

#include <iostream>
#include <cmath>
#include <fstream>
#define N 100

using namespace std;

int main() {
    unsigned long long *arr=new unsigned long long[N];
    const char* finput="file_input12_5.txt";
    ifstream file_1(finput);
    int n=0;
    while (!file_1.eof()) {
        file_1>>arr[n];
        n++;
    }
    file_1.close();
    for (int i=0; i<n; i++) {
        cout<<fixed<<setprecision(3)<<sqrt(arr[n-i-1])<<endl;
    }

    return 0;
}
