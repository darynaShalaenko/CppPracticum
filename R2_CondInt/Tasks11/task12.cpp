#include <iostream>
using namespace std;

struct Square {
    double x1, x2, y1, y2;
};

bool checkPoint(Square* r, double x, double y) {
    if(x >= r->x1 && x <= r->x2 && y >= r->y1 && y <= r->y2)
        return true;
    return false;
}

bool check(Square* first, Square* second) {
    if(checkPoint(first, second->x1, second->y2)) return true;
    if(checkPoint(first, second->x2, second->y2)) return true;
    if(checkPoint(first, second->x2, second->y1)) return true;
    if(checkPoint(first, second->x1, second->y1)) return true;
    if(checkPoint(second, first->x1, first->y2)) return true;
    if(checkPoint(second, first->x2, first->y2)) return true;
    if(checkPoint(second, first->x2, first->y1)) return true;
    if(checkPoint(second, first->x1, first->y1)) return true;
    return false;
}

int main() {
    Square first = {}, second = {};
    cout << "Enter first square's x coordinates: ";
    cin >> first.x1 >> first.x2;
    cout << "Enter first square's y coordinates: ";
    cin >> first.y1 >> first.y2;
    cout << "Enter second square's x coordinates: ";
    cin >> second.x1 >> second.x2;
    cout << "Enter second square's y coordinates: ";
    cin >> second.y1 >> second.y2;
    cout << endl;
    bool res = check(&first, &second);
    if(res) {
        double x1 = max(first.x1, second.x1);
        double x2 = min(first.x2, second.x2);
        double y1 = max(first.y1, second.y1);
        double y2 = min(first.y2, second.y2);
        cout << "Left bottom point coordinates: " << x1 << " " << y1 << endl;
        cout << "Right top point coordinates: " << x2 << " " << y2 << endl;
    }
    else {
        cout << "Squares do not intersect." << endl;
    }
    return 0;
}