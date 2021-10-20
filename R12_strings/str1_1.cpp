#include <iostream>
#include <string>
#include <cctype> // isdigit()
using namespace std;



string task1b(const string& str){

    string res;
    if(str.length()>=1){
       res.push_back(str[0]);
    }
    
    for(int i=1; i<str.length();++i){

       if(!(str[i]=='b' && str[i-1]=='c')){ // not (s[i]=='b' and s[i-1]=='c')
           res.push_back(str[i]);
       }

   }     
   return res;
}

void task1b2(string& str){ // argument -variable!!!

   string pr="cb";   
   //int m = s.find("ph");
   int m = str.find(pr); 
   while(m!=string::npos) {
       // b)
        str = str.substr(0,m+1) + str.substr(m+2,str.length());
        
        m= str.find(pr, m+1);
  }

}

void repl(string& s){
   
   int m = s.find("ph");
   
   while(m!=string::npos) {
       // d)
       s.replace(m,2,"f");   
       m = s.find("ph",m+1);
           
   }

}

int main(){

   string s;
   getline(cin,s); // cin>>s;

   //s = task1b(s);
   repl(s); 

#if 0
   //int m = s.find("+");
   string pr="  ";   
   //int m = s.find("ph");
   int m = s.find(pr); 
   while(m!=string::npos) {
       // b)
       /* if (m>=s.length()){
           break;
        }
        if(isdigit(s[m+1])){
          s = s.substr(0,m) + s.substr(m+1,s.length());
        }
        
        m= s.find("+", m + 1);
        */
       // d)
      // s.replace(m,2,"f");   
      // m = s.find("ph",m+1);
      
       s.replace(m,2," ");
       m= s.find(pr,m);
   }
#endif
  cout<<s;
}
