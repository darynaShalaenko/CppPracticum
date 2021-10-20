/*Слово поліморфізм означає, що щось має багато форм.
Як правило, поліморфізм виникає, коли існує ієрархія класів, і вони пов'язані успадкуванням.
Поліморфізм в C ++ означає, що виклик методу призведе до виконання іншої функції
в залежності від типу об'єкта, який викликає цей метод.
Абстрактний клас, концептуально, клас, який не може бути створений і зазвичай реалізується як клас,
який має одну або більше чистих віртуальних (абстрактних) функцій.
Чиста віртуальна функція є такою, яка повинна бути перевизначена будь-яким конкретним
(тобто, не абстрактним) похідним класом. Це вказується в декларації з синтаксисом "= 0" у декларації функції-члена.
class AbstractClass {
public:
virtual void AbstractMemberFunction() = 0; // Pure virtual function робить
// цей клас Abstract class.
virtual void NonAbstractMemberFunction1(); // Virtual function – віртуальна функція
void NonAbstractMemberFunction2();
};
Віртуальні методи є відносно простими, але їх часто неправильно розуміють.
Концепція є невід'ємною частиною розробки ієрархії класів щодо класів підкласів,
оскільки вона визначає поведінку перевизначених методів у певних контекстах.
Віртуальними методами є функції членів класу, які можуть бути перевизначені в будь-якому класі,
отриманому від того, де вони були оголошені. Тіло методу потім замінюється новим набором реалізації в похідному класі.

C ++ дозволяє вказати більше ніж одне визначення для назви функції або оператора в деякій області.
Це називається перевантаженням функції і перевантаження оператора відповідно.
Перевантажені оператори - це функції зі спеціальними іменами: ключове слово "operator",
за яким слідує символ, який визначається оператором. Як і будь-яка інша функція,
перевантажений оператор має тип повернення і список параметрів

Мова C++ має широкі можливості для перевантаження більшості операторів. Перевантаження оператору 
означає використання оператору для оперування об’єктами класів. Перевантаження оператору – спосіб
оголошення та реалізації оператору таким чином, що він обробляє об’єкти конкретних класів або виконує
деякі інші дії. При перевантаженні оператору в класі викликається відповідна операторна функція 
(operator function), яка виконує дії, що стосуються даного класу.
Якщо оператор “перевантажено”, то його можна використовувати в інших методах 
у звичному для нього вигляді. Наприклад, команди поелементного сумування двох масивів a1 та a2
a1.add(a2);
a3 = add(a1, a2);
краще викликати більш природнім способом:
a1 = a1 + a2;
a3 = a1 + a2;
У даному прикладі оператор ‘+’ вважається перевантаженим.
*/

#include <iostream>

using namespace std;

class ComplexComplex
{
public:
    virtual double getReal() = 0;
    virtual double getImag() = 0;
};

class Complex : public ComplexComplex
{
protected:
    double real, imag;
public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }
    ~Complex()
    {

    }
    double getReal()
    {
        return real;
    }
    double getImag()
    {
        return imag;
    }

    void printComplex()
    {
        cout << real << " + " << imag << "*i" << endl;
    }
    Complex operator+(const Complex& c)
    {
        Complex comp;
        comp.real = this->real + c.real;
        comp.imag = this->imag + c.imag;
        return comp;
    }
    Complex operator-(const Complex& c)
    {
        Complex comp;
        comp.real = this->real - c.real;
        comp.imag = this->imag - c.imag;
        return comp;
    }
    Complex operator * (const Complex& c)
    {
        Complex comp;
        comp.real = this->real * c.real - this->imag * c.imag;
        comp.imag = this->real * c.imag + c.real * this->imag;
        return comp;
    }
};

int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }

int main()
{
  
    add(1, 2);
    add(1.1, 1.2);

    Complex C1(2, 3);
    C1.printComplex();
    double a, b;
    a = C1.getReal();
    b = C1.getImag();
    cout << a << " , " << b << endl;
    Complex C2(4, 2);
    C2.printComplex();
    Complex C3;
    C3 = C1 + C2;
    C3.printComplex();
    Complex C4;
    C4 = C1 - C2;
    C4.printComplex();
    Complex C5;
    C5 = C1 * C2;
    C5.printComplex();
    return 0;
}
