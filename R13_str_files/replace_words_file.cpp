#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void replace(string& text, int i) {
    if (i < text.length()) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] + ('A' - 'a');
        }
    }
}

int moveToWordEnd(string& text, int i) {
    while (text.length() > i && text[i] != ' ') {
        i++;
    }
    return i;
}

void replace(string& text) {

    int length = text.length();

    for (int i = 0; i < length; i++) {

        //a 
        if (i + 2 < length && text[i] == 'a' && text[i + 1] == ' ') {
            replace(text, i + 2);
            i = moveToWordEnd(text, i + 2);
            continue;
        }
        //an
        if (i + 3 < length && text[i] == 'a' && text[i + 1] == 'n' && text[i + 2] == ' ') {
            replace(text, i + 3);
            i = moveToWordEnd(text, i + 3);
            continue;
        }

        //the
        if (i + 4 < length && text[i] == 't' && text[i + 1] == 'h' && text[i + 2] == 'e' && text[i + 3] == ' ') {
            replace(text, i + 4);
            i = moveToWordEnd(text, i + 4);
            continue;
        }

        i = moveToWordEnd(text, i);

    }
}

int main()
{
    ifstream infile("TestIn.txt");
    string line;

    ofstream outFile("TestOut.txt");

    while (std::getline(infile, line))
    {
        replace(line);
        cout << line << endl;
        outFile << line << endl;
    }

    outFile.close();
    infile.close();
    /*
    string text;
    cout << "enter text : ";
    getline(cin, text);
    cout << "text: " << text << endl;

    replace(text);

    cout << "text: " << text << endl;
    */
}