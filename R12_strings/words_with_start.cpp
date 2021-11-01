#include <iostream>
#include <string>


using namespace std;

int main()
{

    string str, s;
    cout<<"string: "<<endl;
    getline(cin, str);
    char ch;
    cout<<"char: ";
    cin >>ch;
    for(int i=str.length()-1; i>0; i--)
    {
        if(str[i-1]==' '&&str[i]==ch)
        {
          s = str.substr(i, str.length());
          for(int h=0; h<s.length(); h++)
          {
              if(s[h]==' ')
              {
                  s=s.substr(0, h);
              }
          }
          cout<<s<<endl;
        }
    }
    if(str[0]==ch)
        {
            for(int h=str.length(); h>0; h--)
          {
              if(str[h]==' ')
              {
                  s=str.substr(0, h);
              }
          }
           cout<<s<<endl;
        }
    return 0;
}

