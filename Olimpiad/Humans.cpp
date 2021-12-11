#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <stdlib.h>



class  Human {

public:
    std::string name;

    Human(std::string name):
        name(name)
        {}
    
    virtual std::string vSay(){
        return "privet";
    }

    std::string say()    {
        printf("%s says: ", name, vSay());
        return vSay();
    };

//private:
   
};


  class  Student: public Human {


public:
   std::string group;

    Student(std::string name,  std::string group):
        Human::Human(name), group(group)
    {
    };
    virtual  std::string vSay(){
         return "Hi";
     };

 
};

class  Teacher: public Human {


public:
   std::string dept; //kafedra

    Teacher(std::string name,  std::string dept):

        Human::Human(name), dept(dept)
    {

    };
    virtual  std::string vSay(){
         return "Good morning";
     };

  
};

class  Aspirante: public Student, Teacher  {


public:
    std::string exams; 

     Aspirante(std::string name,  std::string dept, std::string group, std::string exams):
        Student::Student(name, group),   exams(exams), Teacher::Teacher(name, dept)
     {

     };
    virtual  std::string vSay(){
         return "Good bye";
     };

  
};


int  main(int argc, char *argv[])
{
Aspirante * asp = new Aspirante("Kolya", "ICS", "KOMPMAT", "KCHE")    ;

std::cout << asp->Student::say() <<std::endl;
}