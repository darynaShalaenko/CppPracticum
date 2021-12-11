
#include <iostream>
#include <list>
#include <cmath>

void addNumb(std::list<double>& l,double a){
    l.push_back(a);
}

void delNumb(std::list<double>& l,double a){
    std::list<double> l1;
    for (auto iter = l.begin(); iter != l.end(); iter++){
        if(*iter!=a){
            l1.push_back(*iter);
        }
    }
    l=l1;
}

double searchNumb(std::list<double> l,double a){
    double b,ep=1000;
    for (auto iter = l.begin(); iter != l.end(); iter++){
        if(abs(*iter-a)<ep){
            ep=abs(*iter-a);
            b=*iter;
        }
    }
    return b;
}

void show(std::list<double> l){
    for (auto iter = l.begin(); iter != l.end(); iter++){
        std::cout << *iter << "\t";
    }
}

int main() {
    std::list<double> numbers = { 1.5, 2.34, 3.14, 4.0, 0.5 };
    addNumb(numbers, 10.0);
    delNumb(numbers, 1.5);
    double n=searchNumb(numbers, 3.0);
    std::cout<<n<<std::endl;
    show(numbers);
    return 0;
}
