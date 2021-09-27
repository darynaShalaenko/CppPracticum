#include <iostream>
#include <math.h>
using namespace std;

template <class T> class Mediana
{
    int n = 100;
    T* arr = new T[n];
    int count = 0;
public:
    Mediana() {};
    Mediana(T j)
    {
        arr[count - 1] = j;
        count++;
    };
    void out() {
        for (int i = 0; i < count;i++)
        {
            cerr << arr[i] << endl;
        }
    }
    void push(T i)
    {
        arr[count] = i;
        count++;
    }
    T pop(int k)
    {
        try
        {
            if (k >= count)
            {
                throw  "Out of range";
            }
            T res = arr[k];
            for (int i = k; i < count; i++)
            {
                arr[i] = arr[i + 1];
            }
            count--;

            return res;
        }
        catch (string error)
        {
            cerr << "error: " << error << endl;
        }
    }
    T mediana()
    {
        int j = (count - 1) / 2;
        return arr[j];
    }
    

};
int main()
{
    Mediana<int> k;
    k.push(2);
    k.push(3);
    k.push(4);
    int p = k.mediana();
    k.out();
    cout << p;

}

