#include <iostream>
#include <cstring>
#include <string>


using namespace std;

class Human{

   protected:
   string PIB; // char PIB[20];
   unsigned age;

   bool gender;// true - man, false - woman
   public:

   Human(){}
   Human(string s, unsigned x, bool g):PIB(s),age(x),gender(g){}

   friend ostream& operator<<(ostream & ost, const Human & h){
          const char* gen = h.gender?"Male":"Female";
          ost << h.PIB << ", " << h.age <<"," << gen<<endl;
   } 


  bool input(){
   
   string pib; // char PIB[20];
   unsigned ag;
   bool gend;
   
     cout<<"PIB:";
     cin>> pib;
     cout<<"age:";
     cin>> ag;
     cout<<"Male or Female? M/F?";
     string sex; 
     cin>>sex;
     if (tolower(sex[0])=='f'){
     gend =false;
    }
    else{
     gend =true;
    }

   PIB =pib;
   age=ag; 
   gender = gend;
   return true;
  }	

   int getAge(){
    return age;
  }

  virtual void show(){
   cout<<*this;
  }

};



class Student : virtual public Human{

   string VUZ;
   unsigned char kurs;
   char grupa[3]; 

   public:

   Student(){};

   Student(string s, unsigned x, bool g, string V, unsigned char k, const char grup[3]):Human(s,x,g){
    VUZ = V;
    kurs=k;
    strcpy(grupa,grup); // const_cast<...>
   }

   void set(string s, unsigned x, bool g, string V, unsigned char k, const char grup[3]){
    PIB = s;
    age=x;
    gender=g;  
    VUZ = V;
    kurs=k;
    strcpy(grupa,grup);
   }

   friend ostream& operator<<(ostream & ost, const Student & h){
          const char* gen = h.gender?"Male":"Female";
          ost << h.PIB << ", " << h.age <<"," << gen<<" Grupa "<<h.kurs<<h.grupa<<endl;
   } 


   // method of input for class Student
   void input(){

   string VU;
   unsigned char kur;
   char grup[3]; 

    Human::input();
    cout<<"Vuz";
    cin>> VU;
     cout<<"Kurs";
    cin>>kur;
    cout<<"Group";
    cin>>grup;   
 
   VUZ=VU;
  kurs= kur;

  strcpy(grupa,grup);
    

   }


  void show(){
  cout<<*this;
 } 

};


class Lecturer: virtual public Human{

 string VUZ;

   public:
   Lecturer(){};

   Lecturer(string s, unsigned x, bool g, string V):Human(s,x,g){
    VUZ = V;
   }

  friend ostream& operator<<(ostream & ost, const Lecturer & h){
          const char* gen = h.gender?"Male":"Female";
          ost << h.PIB << ", " << h.age <<"," << gen<<endl<<h.VUZ<<endl;
   } 

   bool input(){
   
   string pib; // char PIB[20];
   unsigned ag;
   bool gend;
   string VU;
   unsigned char kur;
   char grup[3]; 

     cout<<"PIB:";
     cin>> pib;
     cout<<"age:";
     cin>> ag;
     cout<<"Male or Female? M/F?";
     string sex; 
     cin>>sex;
     if (tolower(sex[0])=='f'){
     gend =false;
    }
    else{
     gend =true;
    }	

    cout<<"Vuz";
    cin>> VU;
  
    set(pib, ag, gend, VU);
    return true;	
  }


   void set(string s, unsigned x, bool g, string V){
    PIB = s;
    age=x;
    gender=g;  
    VUZ = V;
   }


  void show(){
  cout<<*this;
 } 

};


class Aspirant: public Student, Lecturer{

   float mark;

   string VUZ2;

   public:
   Aspirant(){};

   /*Aspirant(string s, unsigned x, bool g, string V, float m){
      set(s,x,g,V,m);
   }*/
   
  Aspirant(string s, unsigned x, bool g, string V, float m):Human(s,x,g){
      set(s,x,g,V,m);
   }
   

   void set(string s, unsigned x, bool g, string V, float m){
    PIB = s;
    age=x;
    gender=g;  
    VUZ2 = V;
    mark=m;
    
   }

   friend ostream& operator<<(ostream & ost, const Aspirant & h){
          const char* gen = h.gender?"Male":"Female";
          ost << h.PIB << ", " << h.age <<"," << gen<<" Mark "<<h.mark<<endl;
   } 


   // method of input for class Student
   void input(){

   string VU;
   unsigned char kur;
   char grup[3]; 

    Human::input();
    cout<<"Vuz";
    cin>> VU;
     
   VUZ2=VU;
     }


  void show(){
  cout<<*this;
 } 

};



int main(){

   /*Human x;
   Human y("Ivanova I.I.",24,false);

   x.input();
   cout<<x<<y;
 
   Student z("Ivanov I.I.",24,true,"KNU",2,"2.1"); 
   cout<<z;

   Lecturer t;//("Petrov I.I.",44,true,"KNU"); 

   t.input();

   cout<<t;
*/

/*
  Human m[10];

   int N=2;
   for(int i=0;i<N;++i){
    cout<<"Lecturer or student l/s?";
    string str;
    cin>>str;
    if (tolower(str[0])=='l'){
      Lecturer l; // = new Lecturer();
      l.input(); 

      m[i] = l; //dynamic_cast<Human>(l);   
    }
   else{
      Student* l = new Student;
      l->input(); 

      m[i] = *l;   
    }


  }

   double ag = 0;
   for(int i=0;i<N;++i){
	cout<<m[i];
       ag += m[i].getAge();
  }

 cout<<ag/N;


*/
int N=3;

   Human* m1[10];

   //int N=2;
   for(int i=0;i<N;++i){
    cout<<"Lecturer or student or aspirant l/s/a?";
    string str;
    cin>>str;
    if (tolower(str[0])=='l'){
      Lecturer* l = new Lecturer();
      l->input(); 

      m1[i] =l;   
    }
   else if(tolower(str[0])=='a'){
      Aspirant* l = new Aspirant();
      l->input(); 

      m1[i] =l;
   }
   else{
      Student* l = new Student;
      l->input(); 

      m1[i] = l;   
    }


  }

   for(int i=0;i<N;++i){
	cout<<(*m1[i]); //для Хумана
        m1[i]->show(); 
  }

       



}





