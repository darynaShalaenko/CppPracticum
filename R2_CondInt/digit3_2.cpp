#include <iostream>
#include <string>
using namespace std;

void check(string number){
    int i = 0;
    while(number[i] != '\0'){
        if(number[i] != '1' && number[i] != '2' && number[i] != '3' && number[i] != '4' && number[i] != '5' &&
        number[i] != '6' && number[i] != '7' && number[i] != '8' && number[i] != '9' && number[i] != '0'){
            cout << "Ви ввели символ." << endl;
            //exit(0);
        }
        i++;
    }
    
}

int main(){
    cout << "Введіть 3-хзначне натуральне число: " << endl;
    string number = "905";
    cin>>number;	
    if(number[0] == '0'){
        cout << "Число не начинається з 0" << endl;
        //exit(0);
    }
    check(number);
    if(number.length() != 3){
        cout << "Це не 3-хзначне число. " << endl;
        //exit (0);
    }
    string temp = "";
    char ch1 = number[0];
    char ch2 = number[1];
    char ch3 = number[2];

    if(ch1 == ch2 || ch2 == ch3 || ch3 == ch1){
        cout << "Цифри повторяються." << endl;
        //exit (0);
    }
    if(ch1 != '0'){
        number = temp + ch1 + ch2 + ch3;
        cout << "number: " << number << endl;
        number = temp + ch1 + ch3 + ch2;
        cout << "number: " << number << endl;
    }
    if(ch2 != '0'){
        number = temp + ch2 + ch1 + ch3;
        cout << "number: " << number << endl;
        number = temp + ch2 + ch3 + ch1;
        cout << "number: " << number << endl;
    }
    if(ch3 != '0'){
        number = temp + ch3 + ch2 + ch1;
        cout << "number: " << number << endl;
        number = temp + ch3 + ch1 + ch2;
        cout << "number: " << number << endl;
    }
}
