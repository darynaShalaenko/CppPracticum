//16.06

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#define N 20
#define _USE_MATH_DEFINES
using namespace std;

class Figure {

public:
    double x;
    double y;
    double a;
    Figure(double _x, double _y, double _a): x(_x), y(_y), a(_a) {}
    
    void area() {}
    void length() {}
    virtual double center_of_mass_X() {return 0;}
    virtual double center_of_mass_Y() {return 0;}
    void perimeter() {}
    void print_figure() {}
};

class Rectangle: public Figure {

public:
    double b;
    Rectangle(double _x, double _y, double _a, double _b): 
        Figure(_x, _y, _a), b(_b) {}

    double get_a() {
        return a;
    }
    double get_b() {
        return b;
    }
    double area() {
        return a*b;
    }
    double perimiter() {
        return 2*(a+b);
    }
    bool intersect(const Rectangle& other) {
        if ((x+b)<other.x || x>(other.x+other.b) || (y-a)>other.y || y<(other.y-other.a)) {
            return false;
        }
        else {
            return true;
        }
    }
    virtual double center_of_mass_X() {
        return x+b/2;
    }
    virtual double center_of_mass_Y() {
        return y-a/2;
    }
    
};

class Triangle: public Figure {

public:
    double angle1;
    double angle2;
    Triangle(double _x, double _y, double _a, double _angle1, double _angle2):
        Figure(_x, _y, _a), angle1(_angle1), angle2(_angle2) {}
        
    double get_a() {
        return a;
    }
    double get_b() {
        return (a*sin(angle2))/(sin(M_PI-angle1-angle2));
    }
    double get_c() {
        return (a*sin(angle1))/(sin(M_PI-angle1-angle2));
    }
    double area() {
        return (0.5*a*get_b()*sin(angle1));
    }
    double perimiter() {
        return (a+get_b()+get_c());
    }
    virtual double center_of_mass_X() {
        return get_b()*cos(angle1)+x;
    }
    virtual double center_of_mass_Y() {
        return get_b()*sin(angle1)+y;
    }
};

class Ellipse: public Figure {

public:
    double x1;
    double y1;
    double b;
    Ellipse(double _x, double _y, double _x1, double _y1, double _a, double _b):
        Figure(_x, _y, _a), b(_b), x1(_x1), y1(_y1) {}
        
    double get_a() {
        return a;
    }
    double get_b() {
        return b;
    }
    void get_F() {
        cout<<"("<<x<<","<<y<<")";
    }
    void get_F1() {
        cout<<"("<<x1<<","<<y1<<")";
    }
    double area() {
        return M_PI*a*b;
    }
    double perimiter() {
        return M_PI*(a+b);
    }
    virtual double center_of_mass_X() {
        return (x+x1)/2;
    }
    virtual double center_of_mass_Y() {
        return (y+y1)/2;
    }
};

int main() {
    /*
    cout<<"Rectangle"<<endl<<endl;
    
    Rectangle one {0,2,2,2};
    Rectangle two {3,2,2,4};
    
    cout<<"a: "<<one.get_a()<<"; "<<"b: "<<one.get_b()<<endl;
    cout<<"Area: "<<one.area()<<endl;
    cout<<"Perimiter: "<<one.perimiter()<<endl;
    cout<<"Intersect? ";
    if (one.intersect(two)) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
    cout<<"Center of mass: ";
    cout<<one.center_of_mass_X()<<" ";
    cout<<one.center_of_mass_Y();
    
    cout<<endl<<endl<<"Triangle"<<endl<<endl;
    
    Triangle abc {1,1,5,M_PI/6,M_PI/3};
    
    cout<<"a: "<<abc.get_a()<<"; "<<"b: "<<abc.get_b()<<"; "<<"c: "<<abc.get_c()<<endl;
    cout<<"Area: "<<abc.area()<<endl;
    cout<<"Perimiter: "<<abc.perimiter()<<endl;
    cout<<"Center of mass: ";
    cout<<abc.center_of_mass_X()<<" ";
    cout<<abc.center_of_mass_Y();
    
    cout<<endl<<endl<<"Ellipse"<<endl<<endl;
    
    Ellipse ell {0,0,6,0,4,3};
    
    cout<<"a: "<<ell.get_a()<<"; "<<"b: "<<ell.get_b()<<endl;
    cout<<"F1: ";
    ell.get_F();
    cout<<"; "<<"F1: ";
    ell.get_F1();
    cout<<endl;
    cout<<"Area: "<<ell.area()<<endl;
    cout<<"Perimiter: "<<ell.perimiter()<<endl;
    cout<<"Center of mass: ";
    cout<<ell.center_of_mass_X()<<" ";
    cout<<ell.center_of_mass_Y();
    cout<<endl<<endl;
    */ 
    
    int n1,n2,n3;
    cout<<"Num of Rectangles: ";
    cin>>n1;
    cout<<"Num of Triangles: ";
    cin>>n2;
    cout<<"Num of Ellipses: ";
    cin>>n3;
    
    int n=n1+n2+n3;
    
    /*
    Figure* arr[N]={
        new Rectangle(0,2,2,2),
        new Triangle(1,1,5,M_PI/6,M_PI/3),
        new Ellipse(0,0,6,0,4,3)
    };
    */
    
    Figure* arr[N];
    for (int i=0; i<n1; i++) {
        cout<<"Rectangle №"<<i+1<<endl;
        double x,y,a,b;
        cout<<"x: ";
        cin>>x;
        cout<<"y: ";
        cin>>y;
        cout<<"a: ";
        cin>>a;
        cout<<"b: ";
        cin>>b;
        arr[i]=new Rectangle(x,y,a,b);
    }
    for (int i=n1; i<n1+n2; i++) {
        cout<<"Triangle №"<<i-n1+1<<endl;
        double x,y,a,angle1,angle2;
        cout<<"x: ";
        cin>>x;
        cout<<"y: ";
        cin>>y;
        cout<<"a: ";
        cin>>a;
        cout<<"angle1: ";
        cin>>angle1;
        cout<<"angle2: ";
        cin>>angle2;
        arr[i]=new Triangle(x,y,a,angle1,angle2);
    }
    for (int i=n1+n2; i<n1+n2+n3; i++) {
        cout<<"Ellipse №"<<i-(n1+n2)+1<<endl;
        double x,y,x1,y1,a,b;
        cout<<"x: ";
        cin>>x;
        cout<<"y: ";
        cin>>y;
        cout<<"x1: ";
        cin>>x;
        cout<<"y1: ";
        cin>>y;
        cout<<"a: ";
        cin>>a;
        cout<<"b: ";
        cin>>b;
        arr[i]=new Ellipse(x,y,x1,y1,a,b);
    }
    
    double sumX=0;
    double sumY=0;
    double averageX;
    double averageY;
    for (int i=0; i<n; i++) {
        sumX+=arr[i]->center_of_mass_X();
        sumY+=arr[i]->center_of_mass_Y();
    }
    averageX=sumX/n;
    averageY=sumY/n;
    
    cout<<"The center of mass of all figures: ("<<averageX<<", "<<averageY<<")"<<endl;
    
    return 0;
}

