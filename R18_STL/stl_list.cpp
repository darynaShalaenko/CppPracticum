#include <iostream>
#include <list>
#include <fstream> 
#include <cstring> 

using namespace std;

list<int> read() {
    list<int> temp;
	ifstream fin("input.txt");
    cout << "Input data is:" << endl;
    while (!fin.eof())
    {
        int a;
        fin >> a;
        cout << a << " ";
        temp.push_back(a);
    }
    fin.close();
    return temp;
}

void convert(list<int> &a, list<int> &b, list<int> from) {
    bool flag = true;
    for(auto var : from)
    {
        if (var < 0) {
            flag = false;
            continue;
        }

        if (flag)
            a.push_back(var);
        else
            b.push_back(var);
    }
}

void output(list<int> out, string name) {
    cout << endl << "List " + name + " is:" << endl;
    for (auto var : out) {
        cout << var << " ";
    }
}

int main()
{
    list<int> C1, C2;

    convert(C1, C2, read());

    C1.sort();
    output(C1, "C1");
    C2.sort();
    output(C2, "C2");
    C1.insert(C1.cend(), C2.begin(), C2.end());
    C1.sort();
    output(C1, "result");
}