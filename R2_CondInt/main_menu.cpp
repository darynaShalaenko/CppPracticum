#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

const int size_usr = 100;
void enter(); void datausers(); void searchdata(); void main_menu();
int i_1, i_2, i, counts, s; //счетчики

struct user
{
    string name;
    string phone;
    const string region = "+380";
};

user catalogue[size_usr];

void enter()
{
    system ("cls");
    for(i_1 = counts; i_1 < size_usr; i_1++)
    {
        cout << "\n";
        cout << " Введите имя : ";
        cin >> catalogue[i_1].name;
        cout << " Введите номер телефона : " << catalogue[i_1].region;
        cin >> catalogue[i_1].phone;
        cout << " Новый контакт сохранен !\n";
        i++;
        counts++;
        main_menu();
    }
}

void datausers()
{
    system ("cls");
    cout << "\n\n\n";
    if(i == 0)
    {
        cout << " На данный момент у вас нет контактов. \n\n";
        main_menu();
    }
    cout << " Ваши контакты: \n\n";
    for(i_2 = 0; i_2 < i; i_2++)
    {
        cout << " Имя   : " << catalogue[i_2].name << endl;
        cout << " Номер : " << catalogue[i_2].region << catalogue[i_2].phone << endl;
        cout << endl;

    }
    main_menu();
}

void searchdata()
{
    string searchof_usr;
    system ("cls");
    cout << "\n\n\n";
    if(i == 0)
    {
        cout << " На данный момент у вас нет контактов. \n\n";
        main_menu();
    }
    cout << " Напишите имя контакта: ";
    cin >> searchof_usr;
    for(s = 0; s < i; s++)
    {
        if(searchof_usr == catalogue[s].name)
        {
            cout <<" Номер телефона: " << catalogue[s].region << catalogue[s].phone << endl;
            main_menu();
        }
    }
    cout << " Контакт не найден" << endl;
    main_menu();
}

void main_menu()
{
    char choiceusr;
    cout << "                                   Нажмите + , что бы добавить новый контакт.\n";
    cout << "                                   Нажмите * , что бы посмотреть все свои контакты.\n";
    cout << "                                   Нажмите / , что бы найти нужный Вам контакт.\n";
    cout << "                                   Нажмите - , что бы выйти из программы.\n";
    cout << " Ваш выбор :  ";
    cin >> choiceusr;
    while(choiceusr != '+' && choiceusr != '*' && choiceusr != '-' && choiceusr != '/')
    {
        cout << "\n Введите символ из вышепредложенных !\n\n";
        cout << " Ваш выбор : ";
        cin  >> choiceusr;
    }
    switch(choiceusr)
    {
        case '+' : enter();
                   break;
        case '*' : datausers();
                   break;
        case '/' : searchdata();
                   break;
        case '-' : exit(0);
                   break;
    }
}

int main()
{
    int choiceusr;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("Color F1");
    cout << "                                              *КОНТАКТНАЯ КНИЖКА* \n "
    " Нажмите 1 , что бы начать: ";
    cin >> choiceusr;
    if(choiceusr == 1)
    {
        system("cls");
        main_menu();
    }
    else
    {
        return 0;
    }
    return 0;
}
