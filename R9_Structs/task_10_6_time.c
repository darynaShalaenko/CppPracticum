#include <iostream>
using namespace std;

typedef struct {

    int hour;
    int minute;
    int second;
    int days;
} Time;



Time Input(){
    Time a{};
    cout<<"Enter hour: ";
    cin >> a.hour;
    cout<<"Enter minute: ";
    cin >>a.minute;
    cout<<"Enter second: ";
    cin >> a.second;
    return a;
}

void Output(Time a) {
    if (a.second >=60 ){
        a.minute += a.second/60;

    }
    if (a.minute >=60 ){
        a.hour += a.minute/60;
    }
    if (a.hour >=24 ){
        a.days += a.hour/24;
    }
    cout << a.days << " day " << a.hour%24 << " hour " << a.minute%60 << " minute "<< a.second%60 << " second " << endl;

}



int main() {
    Time obj;
    obj = Input();
    Output(obj);
    return 0;
}
