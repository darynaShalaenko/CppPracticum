#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

vector <vector <double>> a;
int n,m;

const double EPS = 1E-9;

int Rank(){
    int rank = max(n,m);
    vector<char> line_used (n);
    for (int i=0; i<m; ++i) {
        int j;
        for (j=0; j<n; ++j)
            if (!line_used[j] && abs(a[j][i]) > EPS)
                break;
        if (j == n)
            --rank;
        else {
            line_used[j] = true;
            for (int p=i+1; p<m; ++p)
                a[j][p] /= a[j][i];
            for (int k=0; k<n; ++k)
                if (k != j && abs (a[k][i]) > EPS)
                    for (int p=i+1; p<m; ++p)
                        a[k][p] -= a[j][p] * a[k][i];
        }
    }
    return rank;
}

double Det(){
    double det = 1;
    for (int i=0; i<n; ++i) {
        int k = i;
        for (int j=i+1; j<n; ++j)
            if (abs (a[j][i]) > abs (a[k][i]))
                k = j;
        if (abs (a[k][i]) < EPS) {
            det = 0;
            break;
        }
        swap (a[i], a[k]);
        if (i != k)
            det = -det;
        det *= a[i][i];
        for (int j=i+1; j<n; ++j)
            a[i][j] /= a[i][i];
        for (int j=0; j<n; ++j)
            if (j != i && abs (a[j][i]) > EPS)
                for (int k=i+1; k<n; ++k)
                    a[j][k] -= a[i][k] * a[j][i];
    }
    return det;
}

int main(){
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    a.resize(n, vector <double> (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    if (n != m){
        cout << "det no search\n";
        cout << "rank = " << Rank() << endl;
    } else{
        cout << "det = " << Det() << endl;
        cout << "rank = " << Rank() << endl;
    }
}