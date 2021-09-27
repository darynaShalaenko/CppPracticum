#include <iostream>
using namespace std;

struct Rectangle {
    double x1, x2, y1, y2;
};

int main() {
    Rectangle first = {}, second = {};
    cout << "Enter first rectangle's coordinates:" << endl;
    cout << "Enter left bottom point coordinates: ";
    cin >> first.x1 >> first.y1;
    cout << "Enter right top point coordinates: ";
    cin >> first.x2 >> first.y2;

    cout << "Enter second rectangle's coordinates:" << endl;
    cout << "Enter left bottom point coordinates: ";
    cin >> second.x1 >> second.y1;
    cout << "Enter right top point coordinates: ";
    cin >> second.x2 >> second.y2;

    Rectangle big = {};
    big.x1 = min(first.x1, second.x1);
    big.x2 = max(first.x2, second.x2);
    big.y1 = min(first.y1, second.y1);
    big.y2 = max(first.y2, second.y2);

    cout << "Big rectangle coordinates:" << endl;
    cout << "Left bottom point coordinates: ";
    cout << big.x1 << " " << big.y1 << endl;
    cout << "Right top point coordinates: ";
    cout << big.x2 << " " << big.y2 << endl;
    return 0;
}