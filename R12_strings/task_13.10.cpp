#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define N 250

int split(string s, string delimiter, string a[], int n)
{
    if(s[s.length() - 1] != ' ')
    {
        s += " ";
    }

    size_t k = 0, position = 0;
    //int n=1;

    //for(int i = 0; i < s.length();i++)
    //    if(s[i] == ' ')
    //        n++;

    while ((position = s.find(delimiter)) != string::npos && k<n)
    {
        a[k++] = s.substr(0, position);
        s.erase(0, position + delimiter.length());
    }

    return k;
}

int main()
{

    string s, s1 = " ";
    int n;
    cout << "Input string : ";
    getline(cin, s);
    cout << "n = ";
    cin >>n;
    //l= s.length();
    string a[N];
    int z = split(s, s1, a, n);
    for(int i = 0; i < z; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}
