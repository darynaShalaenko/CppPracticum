7 @@
#include<iostream>

using namespace std;
class ExceptionArr : public exception
{
private:
    char* message;
public:
    ExceptionArr(char* message) : exception(), message(message) {}

    virtual const char* what() const throw()
    {
        return message;
    }
};
template<class BB>
class BlackBox
{
private:
    BB* arr;
    int l;

public:
    BlackBox()
    {
        arr = new BB[0];
        l = 0;
    }

    BlackBox(BB* array, int n) : arr(array)
    {
        l = n;
    }


    void push(BB new_el)
    {
        int x = l - 1;
        l++;
        int el = rand() % x;
        arr[l-1] = new_el;
    }

    BB xpop()
    {
        int n = rand() % (l - 1);
        return arr[n];
    }

    void print()
    {
        for (int i = 0; i < l; i++)
        {
            cout << arr[i] << "; ";
        }
        cout << endl;
    }
};

int main()
{

    int l;
    cin >> l;
    int* arr = new int[l];
    if (arr)
    {
        for (int j = 0; j < l; j++)
            arr[j] = rand() % 100;
    }

    BlackBox<int> Arr(arr, l);
    Arr.print();

    int val; cin >> val;
    int x;
    for (int i = 0; i < val; i++)
    {
        cin >> x;
        Arr.push(x);
    }
    Arr.print();

    cout << "Random element: " <<Arr.xpop() << endl;

    return 0;
}
