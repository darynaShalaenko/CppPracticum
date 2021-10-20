#include <iostream>
#include <string>

#include "CashBox.hpp"
#include "DataBase.hpp"

using namespace std;

void findMenu(DataBase);

int main()
{
    DataBase db;
    int i, n;
    do
    {
        cout << "--- CashBox ---" << endl;
        cout << "Add record - 1" << endl;
        cout << "Delete record - 2" << endl;
        cout << "Show records - 3" << endl;
        cout << "Edit records - 4" << endl;
        cout << "Find records - 5" << endl;
        cout << "Quit - 0" << endl;
        cin >> i;
        cin.ignore();
        cout << endl;
        switch(i)
        {
        case 1:
            db.add();
            break;
        case 2:
            cout << "Which number you want to delete? ";
            cin >> n;
            db.del(n);
            break;
        case 3:
            db.show();
            break;
        case 4:
            cout << "Which number you want to edit? ";
            cin >> n;
            db.edit(n);
            break;
        case 5:
            findMenu(db);
            break;
        case 0:
            cout<<"The end";
            break;
        default:
            cout << "Unknown command!";
            break;
        }
        cout << endl << endl;
    } while(i);
    return 0;
}
void findMenu(DataBase db)
{
    int i;
    string s;
    do
    {
        cout << "Find by number - 1" << endl;
        cout << "Find by name - 2" << endl;
        cout << "Find by departure - 3" << endl;
        cout << "Find by arrival - 4" << endl;
        cout << "Find by place - 5" << endl;
        cout << "Back to main menu - 6" << endl;
        cin >> i;
        cout << endl;
        switch(i)
        {
            case 1:
            int n;
            cout << "Input search number: ";
            cin >> n;
            db.Find(n);
            return;
            break;
        case 2:
            cout << "Input search string: ";
            getline(cin, s);
            db.Find(s);
            return;
            break;
        case 3:
            cout << "Input search string: ";
            getline(cin, s);
            db.Find(s);
            return;
            break;
        case 4:
            cout << "Input search string: ";
            getline(cin, s);
            db.Find(s);
            return;
            break;
        case 5:
            double p;
            cout << "Input search place: ";
            cin >> p;
            db.Find(p);
            return;
            break;
        case 0:
            cout << "The end";
            return;
            break;
        default:
            cout << "Unknown command!";
            return;
            break;
        }
        cout<<endl<<endl;
    } while(i);
}
