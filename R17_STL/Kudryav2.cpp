#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

/*
    Білет № 9
    Цілі типи даних на Сі. Логічні операції. Бітові операції. Булевий тип на Сі. Напишить програму, що вводить числа
    5 різних цілих типів та коректно рахує їх загальне середнє (як дійсний тип) та побітову суму їх модулів.

    Дано відсортований за алфавітом файл прізвищ. Додайте туди нове прізвище з консолі, не порушивши його впорядкованість.
*/

/*
    Теорія:
    Цілі типи данних: unsigned, short, int, long, long long, char (0..255);
    Логічні операції: !(операція "не"), && - логічне і, || - логічне або, != - не рівно, == - рівно,
    <= - менше рівно, >= - більше рівно, > - більше,  < - менше;
    Бітові операції: & - побітове і(добуток), | - побітове або(сума), ~ - побітове заперечення(інверсія бітів),
    ^ - побітове виключення або  ( приклад: 00001110 і 01010101 = 01011011 ) , >> - побітовий зсув вправо, << - побітовий зсув вліво;
    Булевий тип: <stdbool.h> - бібліотека, bool = true, false - присвоєння значення булевого типу;
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
        cout<<"Файл не работает!"<<endl;
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

    cout<<"Запишiть нове iм'я(Only Eng): "<<endl;
    cin>>name;
    MySet.insert(name);

    if (!refile.is_open())
    {
        cout<<"Файл не работает!"<<endl;
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
