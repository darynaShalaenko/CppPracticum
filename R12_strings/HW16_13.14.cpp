
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int sl_word(string s,char symb)
{
   int start = 0;
   int final = 0;
   bool space=true;
   int res = 0;
   int len = s.length();
   string s1,s2;
   for(int i=1;i<len;i++)
   {
       if(s[i] != ' ' && space)
       {
           space = false;
           start = i;
       }
       if((s[i] == ' ' && !space) || i == len)
       {
           space = true;
           final = i;
       }
       if(final != 0 && start != 0 && final>start)
       {
           cout << "start and final " << start << " " <<final << endl;
           s1 = s;
           s1 = s1.erase(0,start);
           s2 = s1.erase(final-start,len-start);
           if(s2.find(symb) != string::npos)
           {
               res++;
           }
       }
   }
  return res;
}

int main(){

  string s;
  getline(cin,s);
  int co = sl_word(s,'a');
  cout<<co<<endl;
}


