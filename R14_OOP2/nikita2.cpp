
//Класс, который представляет натуральное число в виде суммы двух или трех 
//квадратов натуральных чисел
class Splitter
{
	int N;
	int result[4]; //Результат

	//Проверка условия
	bool Ok()
	{
		int sum = 0;
		for (int k = 0; k < 4; k++)
			sum += result[k] * result[k];
		return sum == N;
	}

	//Основной метод.
	void Split()
	{
		//пока не получен результат
		//изменять значение начального элемента массива 
		//от 1 до N
		//если достигнута верхняя граница изменения индекса,
		//то поменять следующий элемент массива
		while (!Ok())
		{
			result[0]++;
			if (result[0] > N)
			{
				result[0] = 1;
				result[1]++;
				if (result[1] > N)
				{
					result[1] = 1;
					result[2]++;
					if (result[2] > N)
					{
						result[2] = 1;
						result[3]++;
					}
				}
			}
		}

	}

public:
	Splitter(int N)
	{
		for (int k = 0; k < 4; k++) result[k] = 0;
		this->N = 0;
		if (N <= 0) return;
		this->N = N;
		Split();
	}

	int Count()
	{
		if (result[0] == 0) return 0; //Некорректные исходные данные
		if (result[1] == 0) return 1; //Это и так квадрат числа
		if (result[2] == 0) return 2; //В виде суммы двух квадратов
		if (result[3] == 0) return 3; //Трех
		return 4;
	}
	int Result(int index)
	{
		return result[index];
	}

};

#include <iostream>
using namespace std;

int main()
{
	//system("chcp 1251>nul");
	int i = 0;
	while (i < 5)
	{

		cout << "Input natural number:";
		int N;
		cin >> N;
		if (!N) break;
		Splitter S(N);
		if (S.Count() == 0)
		{
			cout << "Invalid source data" << endl;
		}
		else
		{
			cout << "Decomposition" << endl;
			cout << N << " = ";
			for (int k = 0; k < S.Count(); k++)
			{
				if (k) cout << " + ";
				int x = S.Result(k);
				cout << x << "^2";
			}
			cout << endl;

			//В значениях
			cout << N << " = ";
			for (int k = 0; k < S.Count(); k++)
			{
				if (k) cout << " + ";
				int x = S.Result(k) * S.Result(k);
				cout << x;
			}
			cout << endl;

			cout << endl;
		}
		i++;
	}
}
