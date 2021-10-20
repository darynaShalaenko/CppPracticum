#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

/*
    ����� � 9
    ֳ� ���� ����� �� ѳ. ����� ��������. ����� ��������. ������� ��� �� ѳ. �������� ��������, �� ������� �����
    5 ����� ����� ���� �� �������� ���� �� �������� ������ (�� ������ ���) �� ������� ���� �� ������.

    ���� ������������ �� �������� ���� ������. ������� ���� ���� ������� � ������, �� ��������� ���� ��������������.
*/

/*
    �����:
    ֳ� ���� ������: unsigned, short, int, long, long long, char (0..255);
    ����� ��������: !(�������� "��"), && - ������ �, || - ������ ���, != - �� ����, == - ����,
    <= - ����� ����, >= - ����� ����, > - �����,  < - �����;
    ����� ��������: & - ������� �(�������), | - ������� ���(����), ~ - ������� �����������(������� ���),
    ^ - ������� ���������� ���  ( �������: 00001110 � 01010101 = 01011011 ) , >> - �������� ���� ������, << - �������� ���� ����;
    ������� ���: <stdbool.h> - ��������, bool = true, false - ��������� �������� �������� ����;
*/

/*
    double res;
    char res_bit;
    short b;
    int a;
    long c;
    unsigned d;
    unsigned char e;
    printf("Enter 5 different int type: ");

    scanf("%d", &b);
    scanf("%d", &a);
    scanf("%d", &c);
    scanf("%d", &e);
    scanf("%d", &d);

    res = ((double)a+ (double)b+ (double)c + (double)d +(double)e )/5;
    printf("%f", res);

    res_bit = (char)a | (char)b;
    res_bit = res_bit | (char)c;
    res_bit = res_bit | (char)d;
    res_bit = res_bit | (char)e;

    printf("\n");
    printf("%d", res_bit);

*/

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
        cout<<"���� �� ��������!"<<endl;
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

    cout<<"�����i�� ���� i�'�(Only Eng): "<<endl;
    cin>>name;
    MySet.insert(name);

    if (!refile.is_open())
    {
        cout<<"���� �� ��������!"<<endl;
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
