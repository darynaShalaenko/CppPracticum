#include <iostream>
using namespace std;

class RationalNumber {
private:
    int nominator;              //Ініціалізація 
    unsigned int denominator;       //змінних
public:
    void inPutNominator() {    //Метод уведення чисельнику
        cout << "Enter an integer:" << endl;
        cin >> nominator;
    };
    int inPutDenominator() {    // Метод уведення чисельнику
        cout << "Enter a natural number:" << endl;
        cin >> denominator;
        if (denominator == 0) {
            cout << "The denominator must not be zero" << endl;
            return inPutDenominator();
        }
        else return 0;
    };
    void outPut() {             //Метод виведення
        cout << "You have entered a natural number: " << nominator << "/" << denominator << endl;
    }
    void addition() {           //Метод присвоювання
        cout << "Enter the numerator and denominator of the fraction to be added to the fraction: " << nominator << "/" << denominator << endl;
        int nominator;
        unsigned int denominator;
        cin >> nominator >> denominator;
        int sum_nominator = nominator * this->denominator + this->nominator * denominator;
        unsigned int sum_denominator = denominator * this->denominator;
        int p = sum_nominator;
        int q = sum_denominator;
        for (int i = 1; i <= sum_nominator && i <= sum_denominator; i++) {
            if (!(sum_nominator % i) && !(sum_denominator % i))
            {
                p = sum_nominator / i;
                q = sum_denominator / i;
            }
        }
        cout << "The sum of fractions:" << p << "/" << q << endl;
    }
    void multiplication() {     //Метод множення
        cout << "Enter the numerator and denominator of the fraction to be multiplied by the fraction: " << nominator << "/" << denominator << endl;
        int nominator;
        unsigned int denominator;
        cin >> nominator >> denominator;
        int multiplication_nominator = nominator * this->nominator;
        int multiplication_denominator = denominator * this->denominator;
        int p = multiplication_nominator;
        int q = multiplication_denominator;
        for (int i = 1; i <= multiplication_nominator && i <= multiplication_denominator; i++) {
            if (!(multiplication_nominator % i) && !(multiplication_denominator % i))
            {
                p = multiplication_nominator / i;
                q = multiplication_denominator / i;
            }
        }
        cout << "Product of fractions:" << p << "/" << q << endl;
    }
};


int main() {
    setlocale(LC_ALL, "ru");
    RationalNumber test;
    test.inPutNominator();
    test.inPutDenominator();
    test.outPut();
    test.addition();
    test.multiplication();
    return 0;
}