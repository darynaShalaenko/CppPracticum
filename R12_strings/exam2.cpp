/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

string punctuation = ".,?!"; //  Всі символи пунктуації

bool in(char s) {
    for (char sym : punctuation) { // Перебор симвлів зі всіх символів пунктуації
        if (s == sym) {return true;} // Перевірка чи збігається символ з одним із символів пунктуації
    }
    return false; // Якщо символ не співпалв з одним символом пунктуації,йде повернення що не є символом пунктуації 
}

int main() {
    string line;
    ifstream infile ("example.txt"); // Відкриваємо файл для зчитування
    string ans = ""; // Створюємо змінну для запису пунктуації
    if (infile.is_open()) { // Перевірка чи відкрився файл
        while ( getline (infile,line) ) { // отримання рядка з файлу поки можливо
            for (char sym: line) { //  Прохід по кожному символу з рядка
                if (in(sym)) { //  Перевірка чи є символ знаком пунктуації
                    ans += sym; // У разі якщо є ,запис до відповіді
                }
            }
        }
        infile.close(); // Закриття файлу зчитування
    }

    ofstream outfile ("ans.txt"); // Відкриття файлу для записування відповіді
    outfile << ans << endl; // запис відповіді
    outfile.close(); // Закриття файлу записи

    return 0; // Відповідь, що програма працює нормально
}


