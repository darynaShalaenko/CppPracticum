#include <iostream>
#include <math.h>


using namespace std;

int poz_pt = 0;
int poz_sg = 0;

class Point
{
public:
    int poz;
    int x;
    int y;

    void print()
    {
        cout << "ÒÎ×ÊÀ *" << poz << "* Ç ÊÎÎÐÄÈÍÀÒÀÌÈ  õ = " << x << ", y = " << y << endl;
    }
};

class Segment
{
public:
    int poz;
    int x1;
    int x2;
    int y1;
    int y2;
    double dov;

    void print()
    {
        cout << "ÂIÄÐIÇÎÊ *" << poz << "* Ç ÊÎÎÐÄÈÍÀÒÀÌÈ  õ1 = " << x1 << ", y1 = " << y1 << ", x2 = " << x2 << ", y2 = " << y2 << endl;
    }
    void dovg()
    {
        double xx = pow((x2-x1),2);
        double yy = pow((y2-y1),2);
        dov =  sqrt(xx + yy);
        cout << " Äîâæèíà âiäðiçêà *" << poz << "* = " << dov << endl;
    }
};

void push_back_P(Point *&pt)
{
    Point *newpt = new Point[poz_pt + 1];
    for(int i = 0; i < poz_pt; i++)
    {
        newpt[i] = pt[i];
    }
    delete[] pt;
    pt = newpt;
}

void push_back_S(Segment *&sg)
{
    Segment *newsg = new Segment[poz_sg + 1];
    for(int i = 0; i < poz_sg; i++)
    {
        newsg[i] = sg[i];
    }
    delete[] sg;
    sg = newsg;
}

int main()
{
    Point *pt = new Point[0];
    Segment *sg = new Segment[0];
    setlocale(LC_CTYPE, "rus");
    while(true)
    {
        //system("cls");
        cout << "Âèáåðiòü ïóíêò" << endl;
        cout << " 1. Ñòâîðèòè òî÷êó" << endl;
        cout << " 2. Ñòâîðèòè âiäðiçîê" << endl;
        cout << " 3. Ïðîðàõóâàòè ñóìó óñiõ âåêòîðiâ" << endl;
        cout << " 4. Äâi òî÷êè ç íàéìåíøîþ âûäñòàííþ îäíà âiä îäíî¿ (ÍÅ ÇÀÂÅÐØÅÍÀ ÔÓÍÊÖ²ß)" << endl;
        cout << " 0. Çàêií÷èòè ðîáîòó" << endl;
        int x;
        cin >> x;
        if(x == 1)
        {
            push_back_P(pt);
            cout << "Ââåäiòü êîîðäèíàòó *õ* òî÷êè - ";
            cin >> pt[poz_pt].x;
            cout << "Ââåäiòü êîîðäèíàòó *y* òî÷êè - ";
            cin >> pt[poz_pt].y;
            pt[poz_pt].poz = poz_pt +1;
            pt[poz_pt].print();
            poz_pt ++;
        }
        if(x == 2)
        {
            push_back_S(sg);
            cout << "Ââåäiòü êîîðäèíàòó ïåðøî¿ òî÷êè  âiäðiçêó  *õ1* - ";
            cin >> sg[poz_sg].x1;
            cout << "Ââåäiòü êîîðäèíàòó ïåðøî¿ òî÷êè  âiäðiçêó  *y1* - ";
            cin >> sg[poz_sg].y1;
            cout << "Ââåäiòü êîîðäèíàòó äðóãî¿ òî÷êè  âiäðiçêó  *õ2* - ";
            cin >> sg[poz_sg].x2;
            cout << "Ââåäiòü êîîðäèíàòó äðóãî¿ òî÷êè  âiäðiçêó  *y2* - ";
            cin >> sg[poz_sg].y2;
            sg[poz_sg].poz = poz_sg +1;
            sg[poz_sg].print();
            poz_sg++;
        }
        if(x == 3)
        {
            double dovguna = 0;
            for(int i = 0; i < poz_sg; i++)
            {
                sg[i].dovg();
                dovguna = dovguna + sg[i].dov;
            }
            cout << "ÑÓÌÀÐÍÀ ÄÎÂÆÈÍÀ ÂIÄÐIÇÊIÂ - " << dovguna << endl;
        }
        if(x == 4)
        {
            if(poz_pt == 1)
            {
                cout << "ª ëèøå 1 òî÷êà, îáðàõóâàòè â³äñòàíü ì³æ òî÷êàìè íåìîæëèâî" << endl;
            }
            if(poz_pt == 0)
            {
                cout << "ÍÅ ìàº òî÷îê" << endl;
            }
            else
            {
                for(int i = 0; i < poz_pt; i++)
                {
                    for(int j = 1; j < i+2; j++)
                    {

                    }
                }
            }
        }
        if(x == 0)
        {
            delete [] pt;
            delete [] sg;
            break;
        }
        if(x < 0 && x > 4)
        {
            cout << "ÍÅÂ²ÄÎÌÈÉ ÏÓÍÊÒ" << endl;
        }
        //system("PAUSE");
    }
}
