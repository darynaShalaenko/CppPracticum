#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Ukrainian");

	string input; //����� ���
	string isolatedInput;
	char brackets[6] = { '(', ')', '{', '}', '[', ']' };
	bool check = true;

	cin >> input; //������� ��� � �������

	//��������� �� ����� � ��������� ����� �� ������ �� �� ����� isolatedInput
	for (int i = 0; i < input.length(); i++) {
		for (int j = 0; j < 6; j++) {
			if (input[i] == brackets[j]) {
				isolatedInput.append(1, input[i]);
			}
		}
	}

	if (isolatedInput.length() % 2 == 0) { //���� ����� ������� �������, ������� �����

		//���������� ����� ������� ����� �� �������� ������ �� �� �� "�������" �������
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
		cout << "���";
	}
	else {
		cout << "�i";
	}
}
