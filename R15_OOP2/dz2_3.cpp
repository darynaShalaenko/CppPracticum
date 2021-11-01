#include <iostream>
#include <string>
using namespace std;

/*Описати клас ігрова Дошка(визначається розміром та назвою гри: шашки (міжнародні, російські та турецькі), шахи, нарди) 
та Фігура (назва, гра)*/

class Board {
public:
	int lenght;
	int weight;
	enum Name_game
	{
		checkers_internationa,
		checkers_russian,
		checkers_turkish,
		chess,
		backgammon
	};
};

class Figure {
	string name_figure;
	enum Name_game
	{
		checkers_internationa,
		checkers_russian,
		checkers_turkish,
		chess,
		backgammon
	};

};

int main() {

}