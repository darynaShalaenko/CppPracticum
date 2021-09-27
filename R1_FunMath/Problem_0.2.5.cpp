// Problem_0.2.5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a, b, c, p = 0;
	double m1 = 0, m2 = 0, m3 = 0;
	double h1 = 0, h2 = 0, h3 = 0;
	double l1 = 0, l2 = 0, l3 = 0;
	cin >> a;
	cin >> b;
	cin >> c;
	m1 = 0.5 * (pow(2 * a * a + 2 * b * b - c * c, 0.5));
	m2 = 0.5 * (pow(2 * a * a + 2 * c * c - b * b, 0.5));
	m3 = 0.5 * (pow(2 * c * c + 2 * b * b - a * a, 0.5));
	cout << "median 1 = " << m1 << endl;
	cout << "median 2 = " << m2 << endl;
	cout << "median 3 = " << m3 << endl;
	p = (a + b + c) / 2;
	h1 = (2 / c) * (pow(p * (p - a) * (p - b) * (p - c), 0.5));
	h2 = (2 / b) * (pow(p * (p - a) * (p - b) * (p - c), 0.5));
	h3 = (2 / a) * (pow(p * (p - a) * (p - b) * (p - c), 0.5));
	cout << "height 1 = " << h1 << endl;
	cout << "height 2 = " << h2 << endl;
	cout << "height 3 = " << h3 << endl;
	l1 = (2 / (a + b)) * (pow(a * b * p * (p - c), 0.5));
	l2 = (2 / (a + c)) * (pow(a * c * p * (p - b), 0.5));
	l3 = (2 / (c + b)) * (pow(c * b * p * (p - a), 0.5));
	cout << "bisector 1 = " << l1 << endl;
	cout << "bisector 2 = " << l2 << endl;
	cout << "bisector 3 = " << l3 << endl;

}


