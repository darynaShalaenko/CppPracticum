#include <iostream>
#include <string>
using namespace std;

/*Дана рядок, що складається з символів латинського алфавіту, розділених пробілами (одним або декількома). 
Перетворити кожне слово в рядку, видаливши з нього всі входження заданого символу 
(кількість пропусків між словами не змінювати).*/

int main()
{
    string string_1 = "vhjgjh bnvh jh    jjhgk k hjkg tjgkj";
    char sumbol='j';
    string string_2;
    for (int i = 0; i < string_1.size(); i++) {
        if (string_1[i] != sumbol) {
            string_2 += string_1[i];
        }
    }
    cout << string_2;
}

