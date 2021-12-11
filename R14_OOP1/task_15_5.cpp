
#include <iostream>
#include <cmath>
using namespace std;

class Circle{
    double x,y,r;

    public:
    Circle(){}
    Circle(int x_, int y_, int r_):x(x_),y(y_),r(r_){}
    void input(){
        cout<<"x,y,r"<<endl;
        cin>>x>>y>>r;
    }
    friend double getx(Circle p){
        return p.x;
    }
    friend double gety(Circle p){
        return p.y;
    }

    friend double dist(Circle& p1, Circle& p2);
    friend double plosha(Circle& p1);
    friend double diametr(Circle& p1);
    friend double permetr(Circle& p1);
    friend double* peretn(Circle& p1, Circle& p2);
};

double dist(Circle& p1, Circle& p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double diametr(Circle& p1){
    return 2*p1.r;
}

double permetr(Circle& p1){
    return 2*p1.r*M_PI;
}

double plosha(Circle& p1){
    return p1.r*p1.r*M_PI;
}


double* peretn(Circle& p1, Circle& p2){ {
    double mas[4];
    double d, a, h;
    d = dist(p1, p2);
    a = (p1.r*p1.r - p2.r*p2.r + d*d)/(2*d);
    h = sqrt(p1.r*p1.r - a*a);
    double xn=a*p1.x/d+(d-a)*p1.x/d;
    double yn=a*p1.y/d+(d-a)*p1.y/d;
    mas[0] = xn + h*(p2.y - p1.y)/d;
    mas[1]= yn - h*(p2.x - p1.x)/d;
    mas[2] = xn - h*(p2.y - p1.y)/d;
    mas[3] = yn + h*(p2.x - p1.x)/d;

    return mas;
}

};

int main(){
    int answer;
    Circle p0(0,0,0);
    Circle mas[100];
    double d1=0;
    int c;
    do{
        cout<<"1-додати коло,2-видалити попередне коло,3-визначити центр мас веденних кіл,4-зкінчити роботу";
        cin>>answer;
        if(answer==1){
            Circle p;
            p.input();
            mas[c]=p;
            c++;
        }
        if(answer==2){
            mas[c]=p0;
            c--;
        }
        if(answer==3){
            double ax=0,b=0,ay=0;
            for(int i=0;i<c;++i){
                ax=ax+getx(mas[i])*plosha(mas[i]);
                b=b+plosha(mas[i]);
                ay=ay+gety(mas[i])*plosha(mas[i]);
            }
            cout<<"xc="<<ax/b<<" ,yc="<<ay/b<<endl;
        }
        if(answer==4){
            break;;
        }

    } while (true);
}
