#ifndef CASHBOX_HPP_INCLUDED
#define CASHBOX_HPP_INCLUDED

#include <string>

#include "Passenger.hpp"

using namespace std;

class CashBox : protected Passenger
{
private:
    static int Count;
    int number;
public:
    CashBox(void);
    ~CashBox(void);
    static int getCount();
    static void setCount(int c);
    int getNumber();
    void setNumber(int n);
    string getName();
    string getDeparture();
    string getArrival();
    int getPlace();
    void get();
    void show();
};

#endif // CASHBOX_HPP_INCLUDED
