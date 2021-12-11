#include <iostream>

using namespace std;

int main(){
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    int x01, y01, x02, y02;
    int res;
    cout << "side's of first square (x1 < x2, y1 < y2)\nx1 = ";
    cin >> x1;
    cout << "\nx2 = ";
    cin >> x2;
    cout << "\ny1 = ";
    cin >> y1;
    cout << "\ny2 = ";
    cin >> y2;

    cout << "side's of second square (x3 < x4, y3 < y4)\nx3 = ";
    cin >> x3;
    cout << "\nx4 = ";
    cin >> x4;
    cout << "\ny3 = ";
    cin >> y3;
    cout << "\ny3 = ";
    cin >> y3;

    if (x1 < x3 < x2){
        if (y1 < y3 < y4){
            res = 1;
            x01 = x3;
            y01 = y3;
            x02 = min(x2, x4);
            y02 = min(y2, y4);
        } else if (y1 < y4 < y2){
            res = 1;
            x01 = x3;
            y01 = y3;
            x02 = min(x2, x4);
            y02 = max(y1, y3);
        } else{
            res = 0;
        }
    }
    else if (x1 < x4 < x2){
        if (y1 < y3 < y2){
            res = 1;
            x01 = max(x1, x3);
            y01 = max(y3, y1);
            x02 = min(y4, y2);
            y02 = x4;
        } else if (y1 < y4 < y2){
            res = 1;
            x01 = max(x1, x3);
            y01 = max(y1, y3);
            x02 = x4;
            y02 = y4;
        }
    }
    else if (x3 < x1 < x2 < x4){
        if (y1 < y4 < y2){
            res = 1;
            x01 = x1;
            y01 = max(y3, y1);
            x02 = x2;
            y02 = min(y4, y2);
        } else if (y1 < y3 < y2){
            res = 1;
            x01 = x1;
            y01 = y3;
            x02 = x2;
            y02 = min(y2, y4);
        } else if (y3 < y1 < y2 < y4){
            res = 1;
            x01 = x1;
            y01 = y1;
            x02 = x2;
            y02 = y2;
        } else{
            res = 0;
        }
    }
    else{
        res = 0;
    }
    if (res == 1){
        cout << "A1 = (" << x01 << ", " << y01 << "), A2 = (" << x02 << ", " << y02 << ").";
    } else{
        cout << "не перетинаються";
    }
}
