#include <iostream> 
#include <string> 
 using namespace std; 
 int main() { 
 // Ініціалізуєму змінну для суми double 
 double summ = 0; 
 // Вводимо перший элемент 
 cout << "a[0] = "; 
 double element = 0; 
 cin >> element; 
 // Ініціалізємо змінну для підрахунку номеру елементу 
 int counter = 1; 
 // Перевіряємо, чи не ввели 0 
 while(element != 0) { 
  // Збільшуємо суму на значення елементу 
   summ += element; 
  // Вводимо нове значення елементу 
  cout << "a[" << counter << "] = "; 
  int newValue = 0; 
  cin >> newValue; 
  cout << endl; 
  element = newValue; 
  // Збільшуємо номер вхідного елементу 
  counter++; 
 } 
 cout << "Sum = " << summ; 
 return 0; 
} 
