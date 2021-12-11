

#include <iostream>
#include <cstdlib>
#include <time.h>

template <class T>
class BlackBox{
private:
    int n;
    T *mas;
public:
    BlackBox(){}
    BlackBox(int n_){
        n=n_;
        mas= new T[n];
    }
    ~BlackBox(){
        delete [] mas;
    }

    void input();
    void show();
    void push(T a);
    T pop();
    T xpop();
};

template <typename T>
void BlackBox<T>::input(){
    for(int i=0;i<n;i++){
        std::cout<<"mas["<<i<<"]=";
        std::cin>>mas[i];
    }
}

template <typename T>
void BlackBox<T>::show(){
    for(int i=0;i<n;i++){
        std::cout<<mas[i]<<",";
    }
}

template <typename T>
void BlackBox<T>::push(T a){
    mas[n++]=a;
}

template <typename T>
T BlackBox<T>::pop(){
    srand(time(0));
    int q=0;
    q=rand()%n;
    int j=0;
    T t=mas[q];
    T *mas1=new T[n-1];
    for(int i=0;i<n;i++){
        if(i!=q){
            mas1[j]=mas[i];
            j++;
        }
    }
    mas=mas1;
    n--;
    return t;
}

template <typename T>
T BlackBox<T>::xpop(){
    srand(time(0));
    int q=0;
    q=rand()%n;
    return mas[q];
}

int main() {
    BlackBox<int> mas(4);
    mas.input();
    mas.show();
    mas.push(10);
    int a=mas.pop();
    std::cout<<a<<std::endl;
    mas.show();
    return 0;
}
