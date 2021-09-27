#include <iostream>
using namespace std;
/*Дано два прямокутники, сторони яких паралельні координатним осям. 
Відомо координати лівого нижнього та правого верхнього кутів кожного з прямокутників.
Знайти координати лівого нижнього та правого верхнього кутів мінімального прямокутника, що містить задані прямокутники.
*/


int main()
{
    float x1_l, y1_l, x1_r, y1_r; //Координати 1 прямокутника, де "l"- координати лівого нижнього кута, а "r" - правого верхнього.
    float x2_l, y2_l, x2_r, y2_r; //Координати 2 прямокутника, де "l"- координати лівого нижнього кута, а "r" - правого верхнього.
    cout << "Enter the coordinates of 1 rectangle:\n" << "Lower left:\n" << "x1: ";
    cin >> x1_l;
    cout << "y1: ";
    cin >> y1_l;
    cout<<"Upper right:\n" << "x2: "; 
    cin >> x1_r;
    cout << "y2: ";
    cin >> y1_r;


    cout << "\nEnter the coordinates of 2 rectangle:\n" << "Lower left:\n" << "x1: ";
    cin >> x2_l;
    cout << "y1: ";
    cin >> y2_l;
    cout << "Upper right:\n" << "x2: ";
    cin >> x2_r;
    cout << "y2: ";
    cin >> y2_r;


    float xl, yl, xr, yr; //Координати мінімального прямокутника
    if (x1_l <= x2_l) {
        xl = x1_l;
    }
    else { xl = x2_l; }

    if (y1_l <= y2_l) {
        yl = y1_l;
    }
    else { yl = y2_l; }

    if (x1_r >= x2_r) {
        xr = x1_r;
    }
    else { xr = x2_r; }

    if (y1_r >= y2_r) {
        yr = y1_r;
    }
    else { yr = y2_r; }

    cout << "lower left: \nx1: " << xl << "\ny1: " << yl;
    cout << "\nupper right: \nx2: " << xr << "\ny2: " << yr;
}

