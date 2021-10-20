#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class doz{
public:
    int len = 0;
    int d[10000];

    void moder(int indx){

    }

    void del(int el){
        for (int i = 0; i < len; i++){
            if (d[i] == el){
                moder(i);
                len--;
            }
        }
    }

    void add(int el){
        if (check(el)){
            d[len] = el;
            len++;
        }
    }

    void print(){
        for (int i = 0; i < len; i++){
            cout << d[i] << " ";
        }
        cout << endl;
    }

private:
    bool check(int el){
        for (int i = 0; i < len; i++){
            if (d[i] == el){
                return false;
            }
        }
        return true;
    }
};


int main() {
    int i;
    int N;
    int k;
    doz d = doz();

    ifstream fin("/Users/semen/CLionProjects/money/input.txt");
    fin >> N;

    for(int i=0; i<N; ++i)
    {
        fin >> k;
        d.add(k);
    }

    d.print();

    d.add(146);

    d.print();

    d.del(146);

    d.print();

    return 0;
}