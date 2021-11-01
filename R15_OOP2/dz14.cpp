#include <iostream>
#include <string>

using namespace std;
struct Informtion {
    string surname;
    string city;
    string adress;
};
Informtion person[4];

int main()
{
    const int n = 4;

    for (int i = 0; i < n; i++) {
        cout << "input surname:";
        cin >> person[i].surname;
        cout << "input city:";
        cin >> person[i].city;
        cout << "input adress:";
        cin >> person[i].adress;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (person[i].adress == person[j].adress && person[i].city != person[j].city) {
                cout << person[i].surname << ", " << person[j].surname << " - have the same adress\n";
            }
        }
    }


}

