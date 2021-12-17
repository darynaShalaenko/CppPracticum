#include <iostream>
#include <vector>
using namespace std;

vector <char> letter;
char let_in;

int main()
{
    while(true)
    {
        cout << "Type the letter: \nType 0 for finish:\n";
        cin >> let_in;
        if(let_in == '0')
        {
            break;
        }
        letter.push_back(let_in);
    }
    for(int i_0 = 0; i_0 < letter.size(); i_0++)
    {
        cout << letter.at(i_0);
    }
    cout << endl;
    for(int n = 0; n < letter.size(); n++)
    {
        if(letter[n] == 'i' && letter[n+1] == 'n' && letter [n+2] == 'g')
        {
            cout << "ing";
        }
    }
    cout << endl << endl;
    return 0;
}
