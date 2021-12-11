
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

void input_marks (int n){
    string name, group, kurs, marks;
    ofstream outp;
    outp.open ("test2.txt");
    for (int i = 0; i < n; i++){
        cout << "Name :" << ends;
        cin >> name;
        outp << name << " ";

        cout << ends << "Kurs :" << ends;
        cin >> kurs;
        outp << kurs << " ";

        cout << ends << "Group :" << ends;
        cin >> group;
        outp << group << " ";

        cout << ends << "Marks :" << ends;
        cin >> marks;
        outp << marks << "\n";
    }
    outp.close();
}

string sred (int n1) {
    ifstream inp;
    inp.open ("test2.txt");
    string symb;
    string st[200];
    int n = 0;

    while (1) {
        inp >> symb;
        st[n] = symb;
        if (inp.eof()) {
            break;
        }
        n++;
    }
    int mar, k = 0;
    string stroka;
    double m[n1];
    for (int i = 3; i < n; i += 4){
        double sr = 0;
        int len = st[i].size();
        for (int j = 0; j < len; j += 2){
            stroka = st[i][j];
            int mar = stoi (stroka);
            sr += mar;
        }
        sr = sr / ( len / 2 + 1);
        m[k] = sr;
        k++;
    }


    double minimum = m[0];
    int min_stud = 0;
    for (int i = 1; i < n1; i++) {
        if (m[i] < minimum) {
            minimum = m[i];
            min_stud = i;
        }
    }

    inp.close();


    return st[min_stud * 4];
}

int main() {
    int n = 3;
    cout << sred(n) << endl;
    return 0;
}


