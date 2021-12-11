
#pragma once
#include "human.h"

//додано: ВУЗ, посада,  з.п
class Lecturer : virtual public Humanoid{
   std::string VUZ1;
   protected: 
   std::string posada;
   double salary;

   public:
   Lecturer(){}
   Lecturer(std::string name, unsigned age_,std::string sex,
           std::string VUZ_, std::string pos, double zp):
               Humanoid(name,age_, sex), VUZ1(VUZ_), posada(pos),salary(zp){}

   void show();
   int input(); 
   void outVUZ() {
     std::cout<<"Lecturer VUZ "<< VUZ1;
  }
   
};




