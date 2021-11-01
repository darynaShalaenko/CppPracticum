#include <iostream>

#include "CashBox.hpp"

CashBox::CashBox(void)
{

}

CashBox::~CashBox(void)
{

}

int CashBox::Count = 0;

int CashBox::getCount()
{
    return CashBox::Count;
}

void CashBox::setCount(int c)
{
CashBox::Count = c;
}

int CashBox::getNumber()
{
    return number;
}

void CashBox::setNumber(int n)
{
    number = n;
}

string CashBox::getName()
{
    return name;
}

string CashBox::getDeparture()
{
    return Departure;
}

string CashBox::getArrival()
{
    return Arrival;
}

int CashBox::getPlace()
{
    return place;
}

void CashBox::get()
{
    number = CashBox::getCount() + 1;
    CashBox::setCount(number);
    cout << "Input name: ";
    getline(cin, name);
    cout << "Departure: ";
    getline(cin, Departure);
    cout << "Arrival: ";
    getline(cin, Arrival);
    cout << "Input place: ";
    cin >> place;
}

void CashBox::show()
{
    cout << "Name: " << name << endl << "Departure: " << Departure << endl << "Arrival: " << Arrival << endl << "Place: " << place << endl;
}
