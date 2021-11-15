/*  У текстовому файлі, що складається зі слів, відокремлених одним пропуском,
  замінити першу літеру у словах, що йдуть за словами die, der, das, на
  відповідну літеру верхнього регістру.*/

#include <iostream>
#include <fstream>
#include <cctype> //ctype.h - toupper()

using namespace std;

int main(){
 char fname[20] = "deutsch.txt";
 ifstream f(fname);

 string Artikles[] = {"der", "das", "die", 
                     // "ein", "einen", "einem", "einer",
                      "den", "der", "dem"
                     };

 string buf;
 bool isArtikle = false; 

 ofstream f2("tmp.txt"); // resulting file - temporary

 while(f>>buf){
  //  cout<<"buf"<<buf;

    if(art) {
       buf[0] = toupper(buf[0]);
    }
    clog<<buf<<" ";
    f2<<buf<<" "; // записати buf into file

    isArtikle = false; 
    for(int i=0;i<6;i++){
       if(buf==Artikles[i]){ 
          isArtikle = true;
          break;
       }
    }  
   
 } 

 f.close(); 
 f2.close();

 //remove(fname);
 rename("tmp.txt", fname);

}
