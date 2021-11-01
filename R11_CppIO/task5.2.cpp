/*
 task5.2.cpp
На терміналі вводяться 10*n цифр. Перші 10 цифр -- це перше натуральне
  число, наступні 10 -- друге і так далі. Введіть всі ці числа в масив
  розміру n та обчисліть і виведіть їх суму (вважайте що сума влазить в
  точність unsigned long long).
*/
#include <iostream>
#include <cstdlib>
#include <string>
//using namespace std;

int main(){
  char str[10];
  unsigned a;
  unsigned long long sum=0L;
  std::cout << "Enter;\n";
  unsigned n = 0;

  unsigned mas[1000];

  while(std::cin.get(str,10)){
   std::cout<<str<<","<<std::endl;
   a = atoi(str); 
   //stod(),stoll - c++11
   //std::string::size_type sz;     // alias of size_t
   //a = std::stoul(str,&sz);
   
   mas[n] = a;
   n++;
   sum += a;
 }  

  std::cout<<"s="<<sum<<"\n";
}


