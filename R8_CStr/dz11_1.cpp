#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;


    //a)
    int first_occurrence=0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            first_occurrence = i+1;
            break;
        }
    }
    if (first_occurrence == 0) {
        cout << "Zero coma\n";
    }
    else { cout << "first occurrence: " << first_occurrence << endl; }


    //b)
    int last_occurrence=0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            last_occurrence = i+1;
        }
    }
    if (last_occurrence == 0) {
        cout << "Zero coma\n";
    }
    else { cout << "last occurrence: " << last_occurrence << endl; }


    //c)
    int count_coma = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            count_coma++;
        }
    }
    cout << "count coma = " << count_coma;
}

