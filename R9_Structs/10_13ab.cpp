#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

struct people
{
    string name,surname,sex,position;
    int d,m,y;
};
vector <people> p;

vector<string> fun_a(){
    map <string,int> r;
    vector <string> ans;
    ans.push_back("");
    for (int i = 0; i < p.size(); i++){
        r[p[i].position]++;
        if (r[ans[0]] < r[p[i].position]){
            ans.clear();
            ans.push_back(p[i].position);
        } else if (r[ans[0]] == r[p[i].position]){
            ans.push_back(p[i].position);
        }
    }
    return ans;
}

vector<string> fun_b(){
    map <string,int> r;
    string ans = "";
    for (int i = 0; i < p.size(); i++){
        r[p[i].name]++;
        if (r[ans] < r[p[i].name]){
            ans = p[i].name;
        }
    }
    vector <string> an;
    for (int i = 0; i < p.size(); i++)
        if (p[i].name == ans)
            an.push_back(p[i].name + " " + p[i].surname);
    return an;
}

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++){
        cout << "name = ";
        cin >> p[i].name;
        cout << "surname = ";
        cin >> p[i].surname;
        cout << "position = ";
        cin >> p[i].position;
        cout << "day HB = ";
        cin >> p[i].d;
        cout << "month HB = ";
        cin >> p[i].m;
        cout << "year HB = ";
        cin >> p[i].y;
    }

    vector <string> a = fun_a();
    vector <string> b = fun_b();
    cout << "task a  = \n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    cout << "task b = \n";
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << endl;
    
}