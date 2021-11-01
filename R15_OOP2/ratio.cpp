#include <iostream>

#include <exception>
#include <fstream>

struct ZeroDenom: public std::exception{

   public: 
   
   const char* what(){
     return "Denominator can\'t be 0";
   } 
     
};


class Ratio{

   int x;
   unsigned y;
   public:
   Ratio(){
     x=0;y=1;
   }

   // Ratio(int x1, unsigned y1):x(x1),y(y1){}
   Ratio(int x1, unsigned y1){
      if (y1==0){
        //std::cout<<"Denominator can\'t be 0"<<std::endl;
        //return;
        throw ZeroDenom();   
      }
      x=x1;y=y1;
   }

   bool setAll(int x1, unsigned y1){
      if (y1==0){
        //std::cout<<"Denominator can\'t be 0"<<std::endl;
        //return false;
        throw ZeroDenom();  
      }
      x=x1;y=y1;
      return true;
   }
  

   bool setDenom(unsigned y1){
      if (y1==0){
        //std::cout<<"Denominator can\'t be 0"<<std::endl;
       /// return false;
        throw ZeroDenom();  
      }
      y=y1;
      return true;
   }
   

   void setNom(int y1){
      x=y1;      
   }
 
   Ratio add(const Ratio& z){
     Ratio t;
     int n = z.x*y + z.y*x;
     int d = z.y*y;      
     return Ratio(n,d);
  }

  Ratio operator+(const Ratio& z){
     int n = z.x*y + z.y*x;
     int d = z.y*y;      
     return Ratio(n,d);
  
  }
   // operator -, *

  
  bool operator<(const Ratio& z){
     return (z.x*y>z.y*x);
  }

  void show(){
  std::cout<<x<<"/"<<y<<std::endl;
  }
  
  friend std::ostream &operator<<( std::ostream &output, const Ratio &D ) {
    output << D.x << "/" << D.y <<std::endl;
    return output;
  }

  // operotor cin>>>
  friend std::istream &operator>>( std::istream &input, Ratio &D ) {
    input >> D.x >> D.y;
    return input;
  }


  friend void writeToFile(std::string fname, Ratio r); // дружня функція

};



void writeToFile(std::string fname, Ratio r){
   
   try{
    std::fstream f1;
    f1.open(fname.c_str(), std::ios::app);
    
    f1 << r.x<<r.y;
     f1.close();
   }
   catch(...){
    std::cerr<<"problems with writing to file";
  }
}


int main(){
   Ratio x(1,2),y(1,3),z;
   //z = x.add(y);
   z = x+y;
   //z.show();
   std::cout<<z;
   try{
   Ratio z1(1,0);
   //z1.y=0;
  
     z1.setDenom(0);
   }
   catch(std::exception& e){
    ZeroDenom* p = static_cast<ZeroDenom*> (&e);
    std::cout<<"Exception caught:" << p->what()<<std::endl;
     Ratio z1(1,1);
   z1.setNom(1);
   //z1.show();
   std::cout<<z1;
  }


  writeToFile("1.txt",z);

}
