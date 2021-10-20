#include <iostream>
#include <string>
using namespace std;


struct Date {
	int day;
	int month;
	int year;
};

struct Adress {
	string city;
	string street;
	int building;
	int flat;
};

struct Seminar {
	string subject;
	string teacher;
	int group;
	string day_of_week;
	int hours_of_classes;
	string audience;
};
int main()
{
	Date birthday = { 15,6,2001 };
	Adress home = { "Kyiv","Lomonosova",47,520 };
	cout << birthday.month<<endl;
	cout << home.city << home.building << endl;
}

