/* Даний текстовий файл, що містить рядкові представлення дійсних чисел(але
  замість десяткової карпки — десяткова кома), роздільник — пробіл.Заповнити
 вектор V числами з цього файлу та вивести їх у вихідному порядку.У випадку
  некоректних даних видайте змістовне повідомлення.*/

#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include <typeinfo>

using namespace std;




void zamena(string &str)
{

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == ',')
      str[i] = '.';
  }
}
bool chyslo(char c)
{
    string s="0987654321";
    return(s.find(c)<s.size());
}

vector<double> split(string str, char seperator)
{

  vector<double> V;
  int i = 0;
  int startIndex = 0, endIndex = 0;
  while (i <= str.length())
  {
    if (str[i] == seperator || i == str.length())
    {
      endIndex = i;
      string subStr = "";
      zamena(str);
      subStr.append(str, startIndex, endIndex - startIndex);
      try
          {
                 V.push_back(atof(subStr.c_str()));
          throw subStr;}
          catch (string subStr)
        {
              cout<<"incorrect input"<<subStr;
        }


      startIndex = endIndex + 1;
    }
    i++;
  }
  return V;
}

int main()
{

  string my_t,f;
  string full_t;
  //cin>>f;
  f="text.txt";
  ifstream file; // создаем объект класса ifstream
  file.open(f); // открываем файл
  if(!file){cout<< "за даним шляхом файл не знайдено"; }
            else{
  while (getline(file,my_t)) {
    full_t+=" "+my_t;
  }
  file.close();
  vector<double> v_ch=split(full_t, ' ');
  cout<<v_ch.size();}




}
