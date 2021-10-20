#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){

   string s1;
   string s2; 
   cin>>s1;

   for(int i=0; i<s1.size();++i){
	if(isdigit(s1[i])){ // do nothing
        }
        else if(s1[i]=='+' || s1[i]=='-'){
        
         //s2.push_back(s1[i]);
         //s2.push_back(s1[i]);  
         string s3="aa";
         s3[0]=s1[i];
         s3[1]=s1[i];
 
         s2+=s3;
       } 
       else{
	//s2.push_back(s1[i]);
         string s3="a";
         s3[0]=s1[i]; 
         s2+=s3;
        }

   }

  cout<<s2;


}
