
lude <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, x, i, j, k;
    int tf1 = false, tf2 = false, tf3 = false;
    cout << "Write natural number(x>=1), x= ";
    cin >> x;
    for (i = 1; i <= sqrt(x); i++) {
        for (j = 1; j <= sqrt(x); j++) {
            if (x == pow(i, 2) + pow(j, 2)) {
                tf1 = true;
                cout << x << "=" << i << "^" << 2 << "+" << j << "^" << 2 << endl;
                break;
            }
        }
        if (tf1 == true){
            break;
        }
    }
    if (tf1 == false ){
        for (i = 1; i <= sqrt(x); i++) {
            for (j = 1; j <= sqrt(x); j++) {
                for (k = 1; k <= sqrt(x); k++){
                    if (x == pow(i, 2) + pow(j, 2) + pow(k,2)) {
                        tf2 = true;
                        cout << x << "=" << i << "^" << 2 << "+" << j << "^" << 2 << "+" << k << "^" << 2 << endl;
                        break;
                    }

                }
                if (tf2 == true){
                    break;
                }
            }
            if (tf2 == true){
                break;
            }

        }
    }
    if (tf2 == false and tf1 == false  ){
        for (i = 1; i <= sqrt(x); i++) {
            for (j = 1; j <= sqrt(x); j++) {
                for (k = 1; k <= sqrt(x); k++){
                    for (n = 1; n <= sqrt(x); n++){
                        if (x == pow(i, 2) + pow(j, 2) + pow(k,2) + pow(n,2)) {
                            tf3 = true;
                            cout << x << "=" << i << "^" << 2 << "+" << j << "^" << 2 << "+" << k << "^" << 2 << "+" << n << "^" << 2 << endl;
                            break;
                        }
                    }
                    if (tf3 == true){
                        break;
                    }
                }
                if (tf3 == true){
                    break;
                }
            }
            if (tf3 == true){
                break;
            }

        }
    }



