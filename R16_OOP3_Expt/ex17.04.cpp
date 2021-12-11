//17.04

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <exception>
using namespace std;

class ComplexError: public logic_error {

public:
    ComplexError(string message): logic_error(message) {}
};

class ZeroDivisorError: public ComplexError {

public:
    ZeroDivisorError(): ComplexError("Division by zero!") {}
};

class NegativeEpsilonError: public ComplexError {

public:
    NegativeEpsilonError(double eps):
        ComplexError("Negative epsilon! "+to_string(eps)) {}
};

class ComplexIsBiggerThanOneError: public ComplexError {

public:
    ComplexIsBiggerThanOneError(double mz):
        ComplexError("The modulus of the complex number is not less than 1! "+to_string(mz)) {}
};

class Complex {
    
private:
    double real;    
    double image;
    
    
    void initialize(double real, double image, double eps) {
        double mz=sqrt(real*real+image*image);
        if (mz>=1)
            throw ComplexIsBiggerThanOneError(mz);
        if (eps<0)
            throw NegativeEpsilonError(eps);
        this->real=real;
        this->image=image;
        this->eps=eps;
    }
    
public:
    double eps;
    Complex(double real, double image, double eps){ 
        initialize(real, image, eps);
    }
    
    Complex(): Complex(0, 0, 0) {}
    Complex(double real): Complex(real, 0, 0) {}
    Complex(const Complex& a): Complex(a.real, a.image, a.eps) {}
    
    double module() {
        return sqrt(real*real+image*image);
    }
    void addC(const Complex& other) {
        real=real+other.real;
        image=image+other.image;
    }
    void subtractC(const Complex& other) {
        real=real+other.real*(-1);
        image=image+other.image*(-1);
    }
    void multiplyC(const Complex& other) {
        double old_real=real;
        real=real*other.real-image*other.image;
        image=old_real*other.image+image*other.real;
    }
    void devideC(const Complex& other) {
        if (other.real!=0 && other.image!=0) {
            double old_real=real;
            real=(real*other.real+image*other.image)/(other.real*other.real+other.image*other.image);
            image=(image*other.real-old_real*other.image)/(other.real*other.real+other.image*other.image);
        }
        else {
            throw ZeroDivisorError();
        }
    }
    void multiply(double a) {
        real=real*a;
        image=image*a;
    }
    void devide(double a) {
        if (a!=0) {
            real=real/a;
            image=image/a;
        }
        else {
            throw ZeroDivisorError();
        }
    }
    void to_the_power_of(int n) {
        if (n==0) {
            real=0;
            image=0;
        }
        else if (n==1) {
            real=real;
            image=image;
        }
        else {
            int i=1;
            double first_real=real;
            double first_image=image;
            while (i<=n-1) {
                double old_real=real;
                double old_image=image;
                real=old_real*first_real-old_image*first_image;
                image=old_real*first_image+old_image*first_real;
                i++;
            }
        }
    }
    /*
    Complex operator+(const Complex& other) {
        Complex result(*this);
        result.addC(other);
        return result;
    }
    Complex operator-(const Complex& other) {
        Complex result(*this);
        result.subtractC(other);
        return result;
    }
    Complex operator*(const Complex& other) {
        Complex result(*this);
        result.multiplyC(other);
        return result;
    }
    Complex operator/(const Complex& other) {
        Complex result(*this);
        result.devideC(other);
        return result;
    }
    Complex operator^(int n) {
        Complex result(*this);
        result.to_the_power_of(n);
        return result;
    }
    Complex& operator+=(const Complex& other) {add(other); return *this;}
    */
    void print(ostream& out=cout) {
        initialize(real,image,eps);
        if (real!=0 && image!=0) {
            out<<real<<"+i*("<<image<<")"<<endl;
        }
        else if (real!=0 && image==0) {
            out<<real<<endl;
        }
        else if (real==0 && image!=0) {
            out<<"i*("<<image<<")"<<endl;
        }
        else if (real==0 && image==0) {
            out<<0<<endl;
        }
    }
    void input(istream& inp=cin) {
        double real,image,eps;
        cout<<"Real: ";
        inp>>real;
        cout<<"Image: ";
        inp>>image;
        cout<<"Eps: ";
        inp>>eps;
        initialize(real,image,eps);
    }
};

int main() {
    Complex z;
    z.input();
    z.print();
    
    Complex sum {};
    double n=0;
    Complex old_z=z;
    Complex new_z=z;
    while (true) {
        new_z.to_the_power_of(2*n+1);
        new_z.devide(2*n+1);
        new_z.multiply(pow(-1,n));
        if (new_z.module()>=z.eps) {
            sum.addC(new_z);
            new_z=old_z;
            n++;
        }
        else {
            break;
        }
    }
    cout<<"Sum: ";
    sum.print();
    return 0;
}