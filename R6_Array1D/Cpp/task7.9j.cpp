#include <iostream>

float minimum(int n, float* arr){
    double m = arr[0];
    for (int i = 0; i < n; i++){
        if ( m >= arr[i]){
            m = arr[i];
        }
    }
    return m;
}

int main(){
    unsigned n;
    std :: cout << "Input the amount of numbers: ";
    std :: cin >> n;
    const size_t size = n;
    float arr1[size];
    float arr2[size];
    for (int i = 0; i < size; i++){
        float elem;
        std :: cout  << "Enter your number. Left: " << size - i - 1 << " Number: ";
        std :: cin >> elem;
        arr1[i] = elem;
        arr2[i] = elem * elem;
    }
    float a = (minimum(size,arr1) * minimum(size,arr1)), b = minimum(size, arr2);
    std :: cout << a - b << std :: endl;
}

