#include <iostream>
#include <cstdint>
using namespace std;

struct Array8 {
    unsigned length;
    uint8_t *numbers;
};

struct Array64 {
    unsigned length;
    uint64_t *numbers;
};

Array64 in();
unsigned getK(const Array64 &arr64);
Array8 Array64ToArray8(const Array64 &arr64, unsigned k);
Array64 Array8ToArray64(const Array8 &arr8, unsigned k);
void out(const Array8 &arr8, const Array64 &arr64);

int main() {
    Array64 arr64 = in();
    unsigned k = getK(arr64);
    Array8 arr8 = Array64ToArray8(arr64, k);
    arr64 = Array8ToArray64(arr8, k);
    out(arr8, arr64);
    delete[] arr64.numbers;
    delete[] arr8.numbers;
    return 0;
}

Array64 in() {
    Array64 arr {};
    cout << "Enter array length: ";
    cin >> arr.length;
    cout << "Enter " << arr.length << " numbers: ";
    arr.numbers = new uint64_t[arr.length];
    for(unsigned i = 0; i < arr.length; i++)
        cin >> arr.numbers[i];
    return arr;
}

unsigned getK(const Array64 &arr64) {
    uint64_t max = arr64.numbers[0];
    for(unsigned i = 1; i < arr64.length; i++)
        if(arr64.numbers[i] > max)
            max = arr64.numbers[i];
    unsigned k = 0;
    while(max >= (1 << k))
        k++;
    return k;
}

Array8 Array64ToArray8(const Array64 &arr64, unsigned k) {
    unsigned bits = k * arr64.length;
    Array8 arr8 {};
    arr8.length = bits/8;
    if(bits % 8 != 0)
        arr8.length++;
    arr8.numbers = new uint8_t[arr8.length];
    unsigned bitIndex = 0;
    for(unsigned i = 0; i < arr64.length; i++) {
        for(unsigned j = k; j != 0; j--) {
            if((arr64.numbers[i] >> (j-1)) & 1)
                arr8.numbers[bitIndex/8] |= (1 << (8-(bitIndex % 8)-1));
            bitIndex++;
        }
    }
    return arr8;
}

Array64 Array8ToArray64(const Array8 &arr8, unsigned k) {
    Array64 arr64 {};
    arr64.length = (arr8.length * 8)/k;
    unsigned nulls, last = arr8.numbers[arr8.length-1];
    if(last != 0)
        for(nulls = 0; last % 2 == 0; nulls++)
            last /= 2;
    else
        nulls = 8;
    arr64.length -= nulls/k;
    arr64.numbers = new uint64_t[arr64.length];
    unsigned bitIndex = 0;
    for(unsigned i = 0; i < arr64.length; i++) {
        for(unsigned j = k; j != 0; j--) {
            if((arr8.numbers[bitIndex/8] >> (8-(bitIndex % 8)-1)) & 1)
                arr64.numbers[i] |= (1 << (j-1));
            bitIndex++;
        }
    }
    return arr64;
}

void out(const Array8 &arr8, const Array64 &arr64) {
    cout << "Minimal array: [";
    for(unsigned i = 0; i < arr8.length; i++) {
        cout << uint16_t(arr8.numbers[i]);
        if(i+1 != arr8.length)
            cout << ", ";
    }
    cout << "]" << endl;
    cout << "Original array: [";
    for(unsigned i = 0; i < arr64.length; i++) {
        cout << arr64.numbers[i];
        if(i+1 != arr64.length)
            cout << ", ";
    }
    cout << "]" << endl;
}