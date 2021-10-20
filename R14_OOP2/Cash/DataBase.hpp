#ifndef DATABASE_HPP_INCLUDED
#define DATABASE_HPP_INCLUDED

#include "CashBox.hpp"

class DataBase : public CashBox
{
private:
    CashBox CB[52];
    int i;
public:
    DataBase(void);
    ~DataBase(void);
    void add();
    void del(int);
    void show();
    void edit(int);
    void Find(string);
    void Find(int);
};

#endif // DATABASE_HPP_INCLUDED
