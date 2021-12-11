#include <iostream>
using namespace std;


typedef struct {
    struct {
        int x, y;
    } p1, p2;
} Rectangle;

void Output(Rectangle s) {
    cout << "(" << s.p1.x << "," << s.p1.y << ")" << endl;
    cout << "(" << s.p2.x << "," << s.p2.y << ")" << endl;
}

Rectangle Input() {
    Rectangle s;
    cout << "x1 = ";
    cin >> s.p1.x;
    cout << "y1 = ";
    cin >> s.p1.y ;
    cout<< "x2 = ";
    cin >> s.p2.x;
    cout << "y2 = ";
    cin >> s.p2.y;
    return s;
}

int main() {
    Rectangle t = Input();
    Output(t);
    return 0;
]
