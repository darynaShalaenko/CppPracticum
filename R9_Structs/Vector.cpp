#include <iostream>
using namespace std;

struct Vector
{
    int n;
    float* el = new float[n];
};


Vector vect_input(Vector v)
{
    printf("Enter the size of vector ");\
    cin >> v.n;

    for(int i = 0; i < v.n; i++)
    {
        cin >> v.el[i];
    }

    return v;
}

void vect_print(Vector v)
{

    for(int i = 0; i < v.n; i++)
    {

        cout << v.el[i] << " ";
    }

}

int main()
{
    Vector vec;
    Vector v;
    vec = vect_input(v);
    vect_print(vec);
}



