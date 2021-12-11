#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Ukrainian");

	string input; //вхідні дані
	string isolatedInput;
	char brackets[6] = { '(', ')', '{', '}', '[', ']' };
	bool check = true;

	cin >> input; //вводимо дані у консоль

	//знаходимо усі дужки у введеному рядку та додаємо їх до рядка isolatedInput
	for (int i = 0; i < input.length(); i++) {
		for (int j = 0; j < 6; j++) {
			if (input[i] == brackets[j]) {
				isolatedInput.append(1, input[i]);
			}
		}
	}

	if (isolatedInput.length() % 2 == 0) { //якщо дужок непарна кількість, відповідь хибна

		//перевіряємо кожну непарну дужку на наявність справа від неї її "закритої" варіації
		for (int i = 0; i < isolatedInput.length(); i += 2) {
			for (int j = 0; j < 6; j += 2) {
				if (isolatedInput[i] == brackets[j])
					if (isolatedInput[i + 1] == brackets[j + 1]) {

					}
					else
						check = false;
			}
			if (!check) {
				break;
			}
		}
	}
	else {
		check = false;
	}

	if (check) {
		cout << "Так";
	}
	else {
		cout << "Нi";
	}
}
