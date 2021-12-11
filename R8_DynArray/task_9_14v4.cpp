#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
using namespace std;


unsigned *allocate_memory(int n) {
    auto *arr = (unsigned *) malloc(n * sizeof(unsigned *));
    return arr;
}

uint8_t *alloc_memory8_t(int n) {
    uint8_t *newarr = (uint8_t *) malloc(n * sizeof(uint8_t *));
    return newarr;
}


unsigned *fillArr(unsigned *arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 64;
    }
    return arr;
}



unsigned  *fillnewArr(unsigned *c,const unsigned *arr, int n) {
    string tmp = "";
    for (int i = 0; i < n; ++i) {
        bitset<6> b (arr[i]);
        tmp.append(b.to_string());
    }
    c[(int)ceil(((double)sizeof(arr) * 3/4))];
    for(int i = 0; i < tmp.length()/8; i++){
        bitset<8> b (tmp.substr(8*i, 8));
        c[i] = (int)b.to_ulong();
        //cout << c[i] << " ";
    }
    return c;
}

void printArr(unsigned *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i]<<" ";
    }
}


void printnewArr(uint8_t *newarr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << newarr[i] << endl;
    }
}


int main() {
    int n;
    cout<<"n = ";
    cin>>n;

    unsigned *array, *newarray;
    array = allocate_memory(n);
    array = fillArr(array, n);
    cout << "Original array: " << endl;
    printArr(array, n);
    cout<<"\n";
    cout << "New array: " << endl;
    //fillnewArr(newarray, array, n);
    newarray=fillnewArr(newarray, array, n);
    printArr(newarray, ceil(n*3/4));
    free(array);


