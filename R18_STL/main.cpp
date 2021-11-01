#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;



int main()
{
    setlocale(LC_ALL, "rus");

    set<string> MySet;

    string path1 = "dict.txt";
    string path2 = "redict.txt";
    fstream file, refile;
    file.open(path1, fstream::app|fstream::in|fstream::out);
    refile.open(path2, fstream::app|fstream::in|fstream::out);

    string name = "";

    if (!file.is_open())
    {
        cout<<"File not open!"<<endl;
    }
    else
    {
        cout<<"File open!"<<endl;
        while (!file.eof())
        {
            name="";
            file >> name;
            MySet.insert(name);
        }
    }

    cout<<"Enter your name(Only Eng): "<<endl;
    cin>>name;
    MySet.insert(name);

    if (!refile.is_open())
    {
        cout<<"File dont work!"<<endl;
    }
    else
    {
        for (auto &item : MySet)
        {
            refile<<item<<"\n";
        }
    }

    for (auto &item : MySet)
    {
        cout<<item<<endl;
    }
    file.close();
    refile.close();
    remove("dict.txt");
    rename("redict.txt", "dict.txt");
    return 0;
}
