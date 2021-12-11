#include <iostream>
#include <vector>

using namespace std;

int main(){
    cout << "string = ";
    string s;
    getline(cin, s);
    int i = 0;
    vector <string> arr;
    string t = "";
    while (i < s.size()){
        if (s[i] == ' '){
            if (t.size() > 2 && t[t.size() - 1] == 'g' && t[t.size() - 2] == 'n' && t[t.size() - 3] == 'i')
                arr.push_back(t);
            if (t.size() > 3 && t[t.size() - 1] == 's' && t[t.size() - 2] == 'g' && t[t.size() - 3] == 'n' && t[t.size() - 4])
                arr.push_back(t);
            t = "";
        } else
            t += s[i];
        i++;
    }
    if (t.size() > 2 && t[t.size() - 1] == 'g' && t[t.size() - 2] == 'n' && t[t.size() - 3] == 'i')
        arr.push_back(t);
    if (t.size() > 3 && t[t.size() - 1] == 's' && t[t.size() - 2] == 'g' && t[t.size() - 3] == 'n' && t[t.size() - 4])
        arr.push_back(t);

    cout << "answer : ";

    if (arr.size()){
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << ' ';
        cout << endl;
    } else{
        cout << "no such words were found\n";
    }
}
