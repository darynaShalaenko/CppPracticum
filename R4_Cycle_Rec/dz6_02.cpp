#include <iostream>
#include <cmath>
int factorial(int n){
    int ans = 1;
    for(int i = 1;i <=n;i++){
        ans *= i;
    }
    return ans;
}

int main(){
    float a1 = 1, b1 = 1, sn = 0;
    int n;
    std :: cout << "input n" << std :: endl;
    std :: cin >> n;
    for (int k = 1; k <= n; k++){
        float ak = 3 * b1 + 2 * a1;
        float bk = 2 * a1 +b1;
        sn += float(pow(2,k))/((1 + ak + bk) * factorial(k));
        a1 = ak;
        b1 = bk;
        }
    std :: cout << sn << std :: endl;
}

