#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct point{
    double x;
    double y;
    double length(point pt){
        return sqrt((pt.x - x)*(pt.x - x) + (pt.y - y)*(pt.y - y));
    }
};

int main(){
    point A = {0,0},B = {0,0},C = {0,0};
    for (int i = 0; i < 3; i++){
        double x,y;
        cout << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;
        cout << "1 if dekart or 2 if polyar = ";
        int t;
        cin >> t;
        if (t == 2){
           double p = x;
           double pi = y;
           x = p * cos(pi);
           y = p * sin(pi); 
        }
        if (i == 0){
            A = {x,y};
        }
        if (i == 1){
            B = {x,y};
        }
        if (i == 2){
            C = {x,y};
        }
    }

    double p = (A.length(B) + A.length(C) + B.length(C)) / 2;
    double S =  sqrt(p*(p - A.length(B))*(p - A.length(C))*(p - B.length(C)));
    cout << "S = " << S << endl;
}
