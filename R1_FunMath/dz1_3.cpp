
#include <iostream>
#include <cmath>
using namespace std;
/* Обчислити площу трикутника S зі сторонами a,b,c.
*/

int main()
{
	float a, b, c, S;
	cout << "Input a: ";
	cin >> a;
	cout << "\nInput b: ";
	cin >> b;
	cout << "\nInput c: ";
	cin >> c;
	float p = (a + b + c) / 2;
	if (a <= 0 || b <= 0 || c <= 0) {
		cout << "\nMistake";
	}
	else {
		S = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "\nS = " << S;
	}

}

