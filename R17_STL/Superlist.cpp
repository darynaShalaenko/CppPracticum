

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class SuperList
{
private:
    list <double> ls ;
    int count = 0;
public:
    SuperList() {};
    SuperList(list <double> l, int n)
    {
        ls = l;
        count = n;
    };
    void append(double x)
    {
        ls.push_front(x);
        count++;
    }
    void del(double x)
    {
        list <double> nlist;
        nlist = ls;
        list<double>::iterator start = ls.begin();
        list<double>::iterator end = ls.begin();
        bool t = false;
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                double k = nlist.front();
                if (k == x)
                {
                    t = true;
                    end++;
                    break;
                }
                nlist.pop_front();
                start++;
                end++;


            }
            if (t)
            {
                ls.erase(start, end);
                count--;
            }
            
        }
        else
        {
            cout << "No elements" << endl;
        }
    }
    double av(double x)
    {
        list <double> nlist;
        nlist = ls;
        double dif = 10000000;
        double answ;
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                double k = nlist.front();
                if (abs(k - x) < dif)
                {
                    dif = abs(k - x);
                    answ = k;
                }
                nlist.pop_front();

            }
            return answ;

        }
        else
        {
            cout << "No elements" << endl;
            return 0;
        }
    }
    void output()
    {
        list <double> nlist;
        nlist = ls;
        for (int i = 0; i < count; i++)
        {
            double k = nlist.front();
            cout << k << " ";
            nlist.pop_front();

        }
        cout << endl;
    }
};

int main()
{
    list <double> l = { 1,2,3,4 };
    SuperList sl = SuperList(l, 4);
    sl.del(3);
    cout << sl.av(2.3) << endl;
    sl.output();
}

