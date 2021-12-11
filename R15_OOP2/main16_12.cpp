r on 07.12.2021.
//

#include <iostream>
#include <float.h>
#include <cmath>

class Equality{
protected:
    double fir;
    double las; //інтервал [fir,las]
public:
    int input(){
        std::cout<<"intrval [n m]: ";
        std::cin>>fir>>las;
        return 0;
    }
    double root(){
        return (las+fir)/2;
    }
    void show(){
        return;;
    }
};

class Lin_Equality:public Equality{
protected:
    double a;
    double b; //a*x+b=0
public:
    int input(){
        Equality::input();
        std::cout<<"a b: ";
        std::cin>>a>>b;
        return 0;
    }
    double root(){
        if(-(b/a)>fir and -(b/a)<las){
            return -(b/a);
        }
        return DBL_MAX;
    }
    void show(){
        std::cout<<a<<"*x+"<<b<<"=0\n";
    }
};

class Sq_Equality:public Equality{
protected:
    double a;
    double b;
    double c;//a*x^2+b*x+c=0
public:
    int input(){
        Equality::input();
        std::cout<<"a b c: ";
        std::cin>>a>>b>>c;
        return 0;
    }
    double* root(){
        double* mas=new double[2];
        double d=b*b-4*a*c;
        if(d<0){
            mas[0]=DBL_MAX;
            mas[1]=DBL_MAX;
        }
        else{
            if((-b+sqrt(d))/(2*a)>fir and (-b+sqrt(d))/(2*a)<las){
                mas[0]=(-b+sqrt(d))/(2*a);
            }
            else mas[0]=DBL_MAX;
            if((-b-sqrt(d))/(2*a)>fir and (-b-sqrt(d))/(2*a)<las){
                mas[1]=(-b+sqrt(d))/(2*a);
            }
            else mas[1]=DBL_MAX;
        }
        return mas;
    }
    void show(){
        std::cout<<a<<"*x^2+"<<b<<"*x"<<a<<"=0\n";
    }
};

class Sin_Equality:public Equality{
protected:
    double a;
    double b;
    double c;//a*sin(b*x)+c=0
public:
    int input(){
        Equality::input();
        std::cout<<"a b c: ";
        std::cin>>a>>b>>c;
        return 0;
    }
    double root(){
        if(abs(-c/a)>=1){
            return DBL_MAX;
        }
        else{
            if((asin(-c/a))/b>fir and (asin(-c/a))/b<las){
                return (asin(-c/a))/b;
            }
            return DBL_MAX;
        }
    }
    void show(){
        std::cout<<a<<"*sin("<<b<<"*x)"<<"+"<<c<<"=0\n";
    }
};

class Ep_Equality:public Equality{
protected:
    double a;
    double b;
    double c;//a*e^(b*x)+c=0
public:
    int input(){
        Equality::input();
        std::cout<<"a b c: ";
        std::cin>>a>>b;
        return 0;
    }
    double root(){
        if(-c/a<=0){
            return DBL_MAX;
        }
        else{
            if((log(-c/a))/b>fir and (log(-c/a))/b<las){
                return (log(-c/a))/b;
            }
            return DBL_MAX;
        }
    }
    void show(){
        std::cout<<a<<"*e^("<<b<<"*x)"<<"+"<<c<<"=0\n";
    }
};

int main() {
    Equality*mas[4];
    //int n;
    //std::cout<<"N=";
    //std::cin>>n;
    for (int i=0;i<4; i++){
        std::cout<<"Input Equality(Lin,Sq,Sin,Ep):";
        std::string tmp;
        std::cin>>tmp;
        if(tmp.length()>0){
            if(tmp[0]=='l'){
                Lin_Equality l;
                l.input();
                mas[i]= new Lin_Equality(l);
            }
            else if(tmp[0]=='s' and tmp[1]=='q'){
                Sq_Equality sq;
                sq.input();
                mas[i]= new Sq_Equality(sq);
            }
            else if(tmp[0]=='s' and tmp[1]=='i'){
                Sin_Equality si;
                si.input();
                mas[i]= new Sin_Equality(si);
            }
            else if(tmp[0]=='e'){
                Ep_Equality e;
                e.input();
                mas[i]= new Ep_Equality(e);
            }
        }
        for (int i=0;i<4; i++){
            if(mas[i]->root()!=DBL_MAX){
                mas[i]->show();
            }
        }
        double m=-10000,a, s=0;
        for (int i=0;i<4; i++){
            if(mas[i]->root()!=DBL_MAX){
                a=mas[i]->root();
                s=s+a;
                if(a>m){
                    m=a;
                }
            }

        }
        std::cout<<"найбільший розвязок"<<m;
        std::cout<<"сума всіх дійсних розвязків"<<s;
    }
    return 0;
}
