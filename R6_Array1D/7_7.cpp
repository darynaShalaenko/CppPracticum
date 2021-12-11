#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    double x;
    vector <double> a;
    while(1){
        cout << "a[" << a.size() << "] = ";
        cin >> x;
        if (x == 0)
            break;
        a.push_back(x);
        if (a.size() == 20)
            break;
    }
    double sum_gar = 0;
    double sum_ger = 1;
    for (int i = 0; i < a.size(); i++){
        sum_gar += 1.0 / a[i];
        sum_ger *= a[i];
    }
    sum_gar = a.size() / sum_gar;
    sum_ger = pow(sum_ger, 1.0 / a.size());
    cout << sum_ger << ' ' << sum_gar << endl;
}

