//18.03

#include <iostream>
#include <stack>
#include <ctime>
#define N 100
using namespace std;


template<class T>
class BlackBox {
    
public:
    T arr[N];
    int size;
    
    void initialize(int size) {
        if (size>100) {
            throw logic_error("Item limit exceeded!");
        }
        this->size=size;
    }
    
    BlackBox(int size){ 
        initialize(size);
    }
    
    BlackBox(): BlackBox(0) {}
    BlackBox(const BlackBox& a): BlackBox(a.size) {}
    
    void push(T item) {
        if (size+1>100) {
            throw logic_error("Item limit exceeded!");
        }
        arr[size]=item;
        size+=1;
    }
    void pop() {
        if (size==0) {
            throw logic_error("BlackBox is empty!");
        }
        srand(time(NULL));
        int i=rand()%size;
        if (i!=size-1) {
            size-=1;
            for (int j=i+1; j<size+1; j++) {
                arr[i]=arr[j];
                i++;
            }
        }
        else {
            size-=1;
        }
        
    }
    T xpop() {
        if (size==0) {
            throw logic_error("BlackBox is empty!");
        }
        srand(time(NULL));
        int i=rand()%size;
        return arr[i];
    }
    void print(ostream& out=cout) {
        if (size==0) {
            throw logic_error("BlackBox is empty!");
        }
        for (int i=0; i<size; i++) {
            out<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};

int main() {
    BlackBox<int> black_box;
    /*cout<<"Num of elements -> ";
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int a;
        cin>>a;
        black_box.push(a);
    }*/
    for (int i=0; i<10; i++) {
        black_box.push(i);
    }
    
    cout<<endl;
    black_box.print();
    black_box.pop();
    black_box.print();
    cout<<black_box.xpop();
    
    return 0;
}
