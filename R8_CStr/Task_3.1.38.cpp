// Task_3.1.38.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;
int main() {
	string s = "", v;
	setlocale(LC_ALL, "ukr");
	int a;
	cout << "Введіть число: ";
	cin >> a;
	cout << "Ваше число: " << " ";
	if (a < 0) {
		cout << "Погане число";
	}switch (a / 100)
	{
	case 1: s += "Сто "; break;
	case 2: s += "Двісті "; break;
	case 3: s += "Триста "; break;
	case 4: s += "Чотириста "; break;
	case 5: s += "П'ятьсот "; break;
	case 6: s += "Шістьсот "; break;
	case 7: s += "Сімсот "; break;
	case 8: s += "Вісімсот "; break;
	case 9: s += "Дев'ятьсот "; break;
	}switch ((a % 100) / 10)
	{
	case 2: s += "двадцять "; break;
	case 3: s += "тридцять "; break;
	case 4: s += "сорок "; break;
	case 5: s += "п'ятьдесят "; break;
	case 6: s += "шістьдесят "; break;
	case 7: s += "Сімдесят "; break;
	case 8: s += "Вісіммьдесят "; break;
	case 9: s += "Дев'яносто "; break;
	}
	if (a % 100 >= 10 & a % 100 < 20) {
		switch (a % 100) {
		case 10: s += "десять"; break;
		case 11: s += "одинадцать"; break;
		case 12: s += "дванадцять"; break;
		case 13: s += "тринадцять"; break;
		case 14: s += "чотирнадцять"; break;
		case 15: s += "п'ятнадцять"; break;
		case 16: s += "шістнадцять"; break;
		case 17: s += "сімнадцять"; break;
		case 18: s += "вісімнадцять"; break;
		case 19: s += "дев'ятнадцять"; break;
		}
	}
	else {
		switch (a % 10)
		{
		case 0: s += "нуль"; break;
		case 1: s += "один"; break;
		case 2: s += "два"; break;
		case 3: s += "три"; break;
		case 4: s += "чотири"; break;
		case 5: s += "п'ять"; break;
		case 6: s += "шість"; break;
		case 7: s += "сім"; break;
		case 8: s += "вісім"; break;
		case 9: s += "дев'ять"; break;
		}
	}
	cout << s;
	_getch();
	return 0;
}
