#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int randRage (int low, int high){
    return rand() % ( high - low + 1 ) + low;
}

int main()
{

    int d, h, m, minute;
    while ( true ){
        system ("cls");
        cout << "Enter deegrese: ";
        // d= randRage (1, 8640);
        cin >> d;
        while ( true ){
            if ( d < 1 || d > 360  ){
                cout << "uncorrect number, enter number thet is > 0 and < 8640: ";
                cin >> d;
            }
            else {
                break;
            }
        }
        cout <<"degreese: " << d << endl;
        minute = d*2;
        h = minute/60;
        m = minute - (h * 60 );
        cout << "The time is: " << endl <<  h << " hours" << endl << m << " minutes" << endl;
        system ( "pause" );
    }

}
