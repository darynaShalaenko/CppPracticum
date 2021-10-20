//№6
#include <iostream>
//#include <cprocess>
void f(); 
int main() {
 f(); 
return 0; } 
void f() { 
int var=1; 
static int counter = 0; // Ініціалізація локальної статичної змінної
 counter = counter + 1;
 if(counter > 5) exit(0); 
cout << "counter = " << counter; 
cout << " &var " << &var << " &counter = " << &counter << endl;
 f(); 
}
//Вона виконує п'ять рекурсивних викликів функції f() 
//і “катапультується” за допомогою стандартної функції exit(). 
//При кожнім виклику функції на екран виводиться 
//значення статичної змінної counter і адреса локальної змінної var
