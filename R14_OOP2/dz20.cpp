
#include <iostream>
#include <fstream>
#include<string>
#include <list>
using namespace std;


class Person
{
public:
	string name;
	unsigned year;

	void input() {
		cout << "Name:";
		cin >> name;
		cout << "\nYear: ";
		cin >> year;
	}

	void print() {
		cout << name << "," << year << endl;
	}
};

class Familiar : public Person
{
public:
	string phone_number;

	void input1() {
		Person::input();
		cout << "\nPhone number: ";
		cin >> phone_number;
	}

	void print() { 
		Person::print();
		cout << phone_number << endl;
	}
};




int main() {
	list<Familiar> dictionary;
	int n;
	cin >> n;
	Familiar* famil = new Familiar[n];
	for (int i = 0; i < n; i++) {
		famil[i].input1();
	}
	
	cout << "Input surname\n";
	string surname;
	cin >> surname;
	string number;
	cin >> number;
	for (int i = 0;i<n;i++) {
		if (surname == famil[i].name) {
			famil[i].phone_number = number;
		}
	}

}