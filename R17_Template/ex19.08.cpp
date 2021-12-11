//19.08

#include <iostream>
#include <list>
using namespace std;

class SaveNumbers {

public:
    list<double> save_numbers;
    SaveNumbers() {};
    
    void add_num(double num) {
        save_numbers.push_back(num);
    }
    void delete_num(double num) {
        if (save_numbers.size()==0) {
            throw logic_error("List is empty!");
        }
        save_numbers.remove(num);
    }
    double find_closest_num(double num) {
        if (save_numbers.size()==0) {
            throw logic_error("List is empty!");
        }
        list<double>::iterator it=save_numbers.begin();
        double closest_num;
        closest_num=*it;
        while (it!=save_numbers.end()) {
            if (abs(num-*it)<abs(num-closest_num)) {
                closest_num=*it;
            }
            it++;
        }
        return closest_num;
    }
    void print() {
        if (save_numbers.size()==0) {
            throw logic_error("List is empty!");
        }
        list<double>::iterator it=save_numbers.begin();
        while (it!=save_numbers.end()) {
            cout<<*it<<" ";
            it++;
        }
        cout<<endl;
    }
    
};


int main() {
    SaveNumbers one;
    /*cout<<"Num of elements -> ";
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        double a;
        cin>>a;
        one.add_num(a);
    }*/
    for (int i=0; i<10; i++) {
        one.add_num(i);
    }
    one.print();
    cout<<"a -> ";
    double a;
    cin>>a;
    cout<<one.find_closest_num(a);
    return 0;
}

