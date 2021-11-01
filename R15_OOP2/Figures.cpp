#include <iostream>
#include <cmath>
using namespace std;

class Figure{
public:
    virtual double Area(){
        return 0;
    }
};

class Circle : public Figure{
private:
    double rad;
public:
    explicit Circle(double r){
        if(r > 0){
            this->rad = r;
        }
        else{
            throw "radius is < 0. enter radius > 0 : ";
        }
    }

    double Area() override{
        double pi = 2 * acos(0.0);
        return (pi * pow(rad,2) );
    };


};

class Rectangle : public Figure{
private:
    double width;
    double height;
public:
    Rectangle(double w, double h){
        if(w > 0 && h > 0){
            this->width = w;
            this->height = h;
        }
        else{
            throw "Sides are < 0. enter sides > 0";
        }
    }

    double Area() override{
        return width * height;
    }

};

int main() {
    cout << "Circle radius: ";
    double r1;
    cin >> r1;
    cout << endl;
    Circle c1 = Circle(r1);
    cout << "Circle radius: ";
    double r2;
    cin >> r2;
    cout << endl;
    Circle c2 = Circle(r2);
    cout << "Circle radius: ";
    double r3;
    cin >> r3;
    cout << endl;
    Circle c3 = Circle(r3);
    cout << "Circle radius: ";
    double r4;
    cin >> r4;
    cout << endl;
    Circle c4 = Circle(r4);
    cout << "Rectangle width and height: ";
    double w;
    double h;
    cin >> w >> h;
    cout << endl;
    Rectangle r = Rectangle(w, h);
    double a1 = c1.Area();
    double a2 = c2.Area();
    double a3 = c3.Area();
    double a4 = c4.Area();
    double a5 = r.Area();
    cout << "Summary area of 4 circles and 1 rectangle : " << a1 + a2 + a3 + a4 + a5 << endl;
    return 0;
}
