// Task_4.1.2(б).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
FILE* fout;


int charToInt(char c) {
    return c - '0';
}

int main()
{
    ifstream fin("f.txt");
    if (!fin.is_open())
    {
        cout << "Error";
        return -1;
    }

    string s;
    int count = 0;
    int* a = new int;
    while (getline(fin, s))
    {
        string sp = "";
        string c1 = " ";
        for (int i = 0; i < s.length();i++)
        {
            
            if (s[i] == c1[0])
            {
                for (int i = 0; i < sp.length();i++)
                {
                    a[count] = a[count] + charToInt(sp[i]);
                }
                count++;
                sp = "";
                continue;
            }
            sp = sp + s[i];
            cout << s[i];
        }

    }
    fout = fopen("f2.txt", "w");
    const char* b;
    for (int i = 0; i < count + 1;i++)
    {
        if (a[i] % 3 == 0 and a[i] % 5 == 0)
        {
            b = (const char*)a[i];
            fputs(b, fout);
        }
    }
    fclose(fout);
}


