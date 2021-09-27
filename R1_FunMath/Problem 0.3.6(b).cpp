// Problem 0.3.6(b).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;

float Bent(float x)
{
	return ((pow(x * x + 1, 0.5) - 1) / 2) + x;
}

float Bent_derivative(float x)
{
	return (x / (2 * (pow(x * x + 1, 0.5)))) + 1;
}


int main()
{
	float x;
	cin >> x;
	cout << Bent(x) << endl;
	cout << Bent_derivative(x) << endl;
}


