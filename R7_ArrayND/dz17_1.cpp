#include <iostream>
#include <string>
using namespace std;
/*Дана рядок, що складається з символів латинського алфавіту, розділених пробілами (одним або декількома).
Визначити кількість слів, які містять введений символ.*/

int main()
{
    string string_1 = "jhhgd hjgd hgds   ghs hgs hhhhh susjs hjh js ";
    char sumbol = 'h';
    string string_2;
    for (int i = 0; i < string_1.size(); i++) {
        if (string_1[i] == sumbol || string_1[i] == ' ') {
            string_2 += string_1[i];
        }
    }
    string_2 += " ";
    //cout << string_2;
    int counter = 0;
    for (int i = 0; i < string_2.size()-1; i++) {
        if (string_2[i] == sumbol && string_2[i + 1] == ' ') {
            counter++;
        }
    }
    cout << counter;
}

