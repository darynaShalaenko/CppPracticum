#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    int s,n;
    cout << "first line number to delete = ";
    cin >> s;
    cout << "numbqer of line to delete = ";
    cin >> n;
    ifstream f_in ("input.txt");
    if (f_in.is_open()){
        string line;
        vector <string> lines;
        while(getline(f_in,line))
            lines.push_back(line);
        ofstream f_out ("output.txt");
        if (s + n - 1 > lines.size()){
            cout << "ERROR\n";
            f_out << "ERROR\n";
        } else{
            for (int i = 0; i < s - 1; i++)
                f_out << lines[i] << '\n';
            for (int i = s + n - 1; i < lines.size(); i++)
                f_out << lines[i] << '\n';
        }
        f_out.close();
    } else
        cout << "File close\n";
    f_in.close();
}