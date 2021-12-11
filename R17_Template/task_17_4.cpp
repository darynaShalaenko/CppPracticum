
#include <iostream>
#include <exception>\
#include <string>

#define N 100

using namespace std;


class OutOfRangeException: public exception {
    public:
    const char* what() const throw() {
        return "You tried to get element with wrong index";
    }
};


class TooManyElementsException: public exception {
public:
    const char* what() const throw() {
        return "You tried to add too many elements";
    }
};


template <class U>
class Mediana {
    U arr[N];
    int n;
    public:

    Mediana(){n=0;};

    template <class T>
    Mediana(T* arr1, int n) {
        for (int i=0; i<n; i++) {
            if (i >= N) throw TooManyElementsException();
            arr[i] = arr1[i];
        }
        this->n=n;
    }

    template <class T>
    void push(T element) {
        if (n >= N) throw TooManyElementsException();
        arr[n++] = element;
    }

    template <class T>
    T pop(int n) {
        if (n >= N) throw OutOfRangeException();
        T res = arr[n];
        T* tmp = (T*)malloc(sizeof(arr[0])*n);
        for (int i=0; i<this->n; i++) {
            tmp[i] = arr[i];
        }
        for (int i=0; i<this->n; i++) {
            if (i==n) i++;
            arr[i] = tmp[i];
        }
        arr[this->n-1] = 0;
        this->n--;
        free(tmp);
        return res;
    }

    friend bool &operator<(const Mediana &m1, const Mediana &m2) {
        for (int i=0; i < min(m1.n, m2.n); i++) {
            if (m1.arr[i] != m2.arr[i]) return m1.arr[i] < m2.arr[i];
        }
    }

    friend bool &operator>(const Mediana &m1, const Mediana &m2) {
        for (int i=0; i < min(m1.n, m2.n); i++) {
            if (m1.arr[i] != m2.arr[i]) return m1.arr[i] > m2.arr[i];
        }
    }

    template <class T>
    T mediana() {
        T elems[N];
        int counters[N], k=0, flag = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<k; j++) {
                if (elems[j] == arr[i]) {
                    counters[j]++;
                    flag = 1;
                }
            }
            if (!flag) {
                elems[k] = arr[i];
                counters[k++] = 1;
            } else flag = 0;
        }

        int max_counter = 0;
        for (int i=0; i<k; i++) {
            if (counters[i]>max_counter) max_counter = counters[i];
        }

        for (int i=0; i<k; i++) {
            if (counters[i] == max_counter) return elems[i];
        }
    }
};



int main() {
    Mediana<string> med;
    string item;
    try {
        for (int i=0; i>5; i++) {
            cout << "Item: ";
            cin >> item;
            med.push(item);
        }
        // doesn't want to call fuctions
        cout << "Mediana: " << med.mediana();
        cout << "Element with index 3: " << med.pop(3);
    } catch (exception &e) {
        cerr << e.what();
    }
}
