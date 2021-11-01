#include <iostream>
#include <string>

using namespace std;

int main(){

  string str;

  cin>>str;

  //cout<<str; 
 /*
  size_t n = str.size();
  size_t k=-1;
  for(size_t i=0; i<n;++i){
     if(str[i]==','){
	k=i;
        break;
     }
  }
*/

  int k = str.find(',');

 if(k==string::npos){
    cout<<"Nema komy";
  } 
 else{
   cout<<"k="<<k;
 }

}

