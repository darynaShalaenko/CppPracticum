
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int sl_word(string& s,char splitter,int count)
{
   bool space=true;
   int k = 0;
   int len = s.length();
   for (int i = 0; i < len; i++)
   {
       if(s[i] == splitter)
       {
           k++;
       }
       if(k==count)
       {
           s.erase(i,len);
           return 0;
       }
   }
   return 1;
}


int main(){

  string s;

  getline(cin,s);
  sl_word(s,' ',3);
  cout<<s<<endl;
}
