// Task_14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

class Game
{
private:
    string x[3] = { "_", "_" ,"_" };
    string y[3] = { "_", "_" ,"_" };
    string z[3] = { " ", " " ," " };
public:

    void start()
    {

        for (int i = 0; i < 3; i++)
        {
            if (i != 2)
            {
                cout << "_" << "|" << "_" << "|" << "_" << endl;
                
            }
            else
            {
                cout << " " << "|" << " " << "|" << " " << endl;
            }
        }
    }
    void make_move(string a, int pos)
    {
        if ((a != "o" and a != "x") or (pos < 0 and pos>8))
        {
            cout << "Not legal move"<< endl;
        }
        else
        {
            int k = pos / 3;
            if (k < 1 )
            {
                x[pos] = a;
            }
            else if (k == 1)
            {
                y[pos%3] = a;
            }
            else if (k ==2)
            {
                z[pos % 6] = a;
            }
        }
    }
    void current_game()
    {
        cout << x[0] << "|" << x[1] << "|" << x[2] << endl;
        cout << y[0] << "|" << y[1] << "|" << y[2] << endl;
        cout << z[0] << "|" << z[1] << "|" << z[2] << endl;
    }
    void who_win()
    {
        int g = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if ((i + j + k) % 3 == 0)
                    { 
                        if (x[i] == y[j] and y[j] == z[k] and z[k] == "x")
                        {
                            cout << "x win";
                            g = 1;
                        }
                        else if (x[i] == y[j] and y[j] == z[k] and z[k] == "y")
                        {
                            cout << "y win";
                            g = 1;
                        }
                    }
                }
            }
        }
        if (g == 0)
        {
            cout << "We do not have winner";
        }
    }
};

int main()
{
    Game g;
    g.start();
    g.make_move("x", 2);
    g.make_move("o", 1);
    g.make_move("x", 4);
    g.make_move("o", 0);
    g.make_move("x", 6);
    g.current_game();
    g.who_win();

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
