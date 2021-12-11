/*У текстовому файлі записані координати точок на площині задані парою цілих
чисел. Точки записуються в форматі : ( х1, х2 ) (х1 , х2) , .... - саме так через коми та
дужки. Створити файл, в якому будуть записані координати всіх відрізків з точок
цього файлу, при цьому ці відрізки відсортовані за зростанням довжини.*/

#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    vector <pair<int, int> > a;
    while (getline(cin, s)) {
        stringstream in(s);
        char c;
        do {
            in >> c;
        } while (c != '(');
        int x1;
        in >> x1;
        in >> c;
        int x2;
        in >> x2;
        a.push_back({x1, x2});
    }
    int n = (int)a.size();
    vector <pair<int, int> > b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                b.push_back({i, j});
            }
        }
    }
    sort(b.begin(), b.end(), [&] (pair<int, int> c, pair<int, int> d) {
        long long l1 = (a[c.x].x - a[c.y].x) * 1ll * (a[c.x].x - a[c.y].x) + (a[c.x].y - a[c.y].y) * 1ll * (a[c.x].y - a[c.y].y);
        long long l2 = (a[d.x].x - a[d.y].x) * 1ll * (a[d.x].x - a[d.y].x) + (a[d.x].y - a[d.y].y) * 1ll * (a[d.x].y - a[d.y].y);
        return l1 < l2;
    });
    for (auto &i : b) {
        cout << "( ( " << a[i.x].x << ", " << a[i.x].y << "), (" << a[i.y].x << ", " << a[i.y].y << ") )\n";
    }
}
