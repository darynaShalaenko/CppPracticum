#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
class Complex{
        // Поліморфізм це використання однієї назви для виконання кількох методів. Він проявляється за допомогою вказівника.
    public:
        double real, imaginary, modul, argument;
        Complex(){}
        virtual void show(){                              // Це віртуальний метод, в класах наслідниках він перерозподіляється
            cout << "Створення базового класу" << endl; 
        }
        virtual void display() = 0;  // Це абстрактний клас, поскільки в ньому є хоча б 1 чисто віртуальна функція.
        // Не можна створити об'єкти абстрактного класу

        void argumentz(){ // невіртуальний метод
            if(real>0 && imaginary>=0){
                argument = atan(imaginary/real);
            }
            else if(real<0 && imaginary>=0){
                argument = M_PI - atan(std::abs(imaginary/real));
            }
            else if(real<0 && imaginary<0){
                argument = M_PI + atan(std::abs(imaginary/real));
            }
            else if(real>0 && imaginary<0){
                argument = 2*M_PI - atan(std::abs(imaginary/real));
            }
            else if(real==0 && imaginary>0){
                argument = M_PI_2;
            }
            else if(real==0 && imaginary<0){
                argument = 3*M_PI_2;
            }
            modul = sqrt(real*real + imaginary*imaginary);
        }
};

class C_derived : public Complex{
        
    public:
        //double ;
        C_derived(){};
        C_derived(double mod, double arg) {
            modul = mod;
            argument = arg;
        }
        void show(){
            cout << "Створення 1-го дочірнього класу" << endl;
        }
        void display(){
            cout << "Полярна форма запису через тригонометрію: " << modul << "*cos(" << argument << ") + i*sin(" << argument << ")" << endl; 
        }
        C_derived operator+(C_derived op2);
        C_derived operator*(C_derived op2);
        C_derived operator/(C_derived op2);
        C_derived operator-(C_derived op2);
        C_derived operator=(C_derived op2);
        C_derived operator-() const;

        friend std::ostream& operator<< (std::ostream &out, const C_derived &complex);
        friend std::istream& operator>> (std::istream &in, C_derived &complex);
};

C_derived C_derived::operator-() const{
    C_derived temp;
    temp.imaginary = -imaginary;
    temp.real = -real;
    return temp;
}

C_derived C_derived::operator+(C_derived op2){
    C_derived temp;

    temp.real = op2.real + real;
    temp.imaginary = op2.imaginary + imaginary;

    return temp;
}

C_derived C_derived::operator*(C_derived op2){
    C_derived temp;

    temp.real = op2.real * real - op2.imaginary * imaginary;
    temp.imaginary = op2.imaginary * real + imaginary* op2.real;

    return temp;
}

C_derived C_derived::operator/(C_derived op2){
    C_derived temp;

    temp.real = (op2.real * real + op2.imaginary * imaginary)/(op2.real * op2.real + op2.imaginary * op2.imaginary);
    temp.imaginary = (op2.imaginary * real - imaginary * op2.real)/(op2.real * op2.real + op2.imaginary * op2.imaginary);

    return temp;
}

C_derived C_derived::operator-(C_derived op2){
    C_derived temp;
    temp.real = real - op2.real;
    temp.imaginary = imaginary - op2.imaginary;
    
    return temp;
}

C_derived C_derived::operator=(C_derived op2){

    real = op2.real;
    imaginary = op2.imaginary;
    
    return *this;
}

std::ostream& operator<< (std::ostream &out, const C_derived &C_derived){
    out << C_derived.real;
    if(C_derived.imaginary > 0){
        out << " + i" << C_derived.imaginary << std::endl;
    } else if(C_derived.imaginary < 0){
        out << " - i" << -C_derived.imaginary << std::endl;
    }
    return out;
}

std::istream& operator>> (std::istream &in, C_derived &C_derived){
    std::cout << "Введіть дійсну частину: " << std::endl;
    in >> C_derived.real;
    std::cout << "Введіть уявну частину: " << std::endl;
    in >> C_derived.imaginary;

    return in;
}

class C_C_derived : public C_derived{
    public:
        C_C_derived(double re, double im){
            real = re;
            imaginary = im;
        }
        void display(){
            cout << "Звичайна форма запису: " << real << " + " << imaginary << "i " << endl;
        }
};

int main(){
    Complex *p;  // Потрібно зробити вказівник на базовий клас
    C_derived ob2(2, 2);
    C_C_derived ob3(3, 3);
    p = &ob2;
    p->show();
    p->display();
    p = &ob3;
    p->show(); // Поскільки в с_с_derived не прописана функція show(), компілятор візьме її від c_derived
    p->display();
    cout << ob2; // перевантаження тільки для C_derived прописав
}
