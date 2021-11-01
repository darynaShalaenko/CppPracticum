#include <iostream>

#include "DataBase.hpp"

using namespace std;

DataBase::DataBase(void) : i(0)
{

}

DataBase::~DataBase(void)
{

}

void DataBase::add()
{
    CB[i++].get();
}

void DataBase::del(int number)
{
    for(int j = number - 1; j < CashBox::getCount() - 1; j++)
    {
        CB[j] = CB[j + 1];
        CB[j].setNumber(j + 1);
    }
    CashBox::setCount(CashBox::getCount() - 1);
}

void DataBase::show()
{
    if (CashBox::getCount() == 0)
        cout << "CashBox empty!";
    else
        for (int j = 0; j < CashBox::getCount(); j++)
            CB[j].show();
}

void DataBase::edit(int n)
{
    CB[n - 1].get();
    CB[n - 1].setNumber(n);
    CashBox::setCount(CashBox::getCount() - 1);
}

void DataBase::Find(string s)
{
    int cnt = CashBox::getCount();
    bool fl;
        for (int i = 0; i < cnt; i++)
        {
            if (CB[i].getName() == s)
            {
                CB[i].show();
                fl = true;
            }

            if (CB[i].getArrival() == s)
            {
                CB[i].show();
                fl = true;
            }

            if (CB[i].getDeparture() == s)
            {
                CB[i].show();
                fl = true;
            }
        }
    if (!fl)
        cout<<"Search result is empty!";

}

void DataBase::Find(int n)
{
    int cnt = CashBox::getCount();
    bool fl;
    for (int i = 0; i < cnt; i++)
    {
        if (CB[i].getNumber() == n)
        {
            CB[i].show();
            fl = true;
        }

        if (CB[i].getPlace() == n)
        {
            CB[i].show();
            fl = true;
        }
    }
    if (!fl)
        cout<<"Search result is empty!";
}
