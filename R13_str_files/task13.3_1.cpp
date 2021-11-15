#include <iostream> 
#include <string> 
#include <fstream> 

using namespace std; 

int tag_words(string &s, int starts[], int ends[], int& n){ 
  int start_tag = false; //
  n = 0;	
  for(size_t i=0; i<s.length()-4; i++) {
      //if(s[i]=='<' && s[i+1]=='t' && s[i+2]=='d' && s[i+3]=='>') { 
       //size_t pos = s.find("<td>");          
       string buf = s.substr(i,4);
       if(buf=="<td>"){  
        //cout << "Zdarowa" << endl; 
        start_tag = true; 
	starts[n] = i+3;
       } 
      else{ 
       if(start_tag &&  s.substr(i,5)="</td>")// s[i]=='<' && s[i+1]=='/' && s[i+2]=='t' && s[i+3]=='d' && s[i+4]=='>')
         {
	  //cout << "Close tag found" << endl; 
          start_tag = false;
	  ends[n]=i;
	  n++;		 
         } 
       } 
		
    } 
  return 1; 
} 

int main() {
    ifstream File("file.txt");
    string str;     
    int s[10],e[10];
    int n;	 

    while (getline (File, str)) { 
      tag_words(str,s,e,n); 
     // cout << str << endl;

      for(int i=0;i<n;++i){
	string buf = str.substr(s[i],e[i]);
	cout<<buf;	
      }	  
    }

} 
