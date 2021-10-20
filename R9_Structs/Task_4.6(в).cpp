// Task_4.6(в).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

struct Date
{
    string day;
    string month;
    string year;
    string hour;
    string minute;
};

Date EnterDate(Date dt)
{
    cout << "Enter day: ";
    cin >> dt.day;
    cout << "Enter month: ";
    cin >> dt.month;
    cout << "Enter year: ";
    cin >> dt.year;
    cout << "Enter hour ";
    cin >> dt.hour;
    cout << "Enter minute ";
    cin >> dt.minute;
    return dt;
}

void PrintDate(Date dt)
{
    cout << dt.day << "." << dt.month << "." << dt.year << "   " << dt.hour << ":" << dt.minute;
}

int main()
{
    Date dt;
    dt.day = "0";
    dt = EnterDate(dt);
    PrintDate(dt);
}


