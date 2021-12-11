
#include <fstream>

#include "Rational.h"

void Rational::show(){
	std::cout<< nom<< "/"<<denom<<"\n";
}

int Rational::input(){
   int ch;
   unsigned zn=0;		
   std::cout<<"Input nom:";
   std::cin>>ch;	
   while(!zn){	
   	std::cout<<"Input denom:";
   	std::cin>>zn;
   }
   nom = ch;
   denom = zn;
		
   reduce();	

   return 0;	
}

Rational Rational::add(const Rational& x){
	int t = (int)(this->nom * x.denom + denom * x.nom);
	unsigned y = x.denom * denom;
	return Rational(t,y);
}

Rational Rational::mult(const Rational& x){
	int t = nom * x.nom;
	unsigned y = x.denom * denom;
	return Rational(t,y);
}

unsigned Rational::gcd(unsigned x, unsigned y){
	if(y==0||x==0) return x+y;
	if(x>=y) return gcd(x%y,y);
	return gcd(y%x,x);
}

void Rational::reduce(){
	
	int nsd; 
	if(nom>=0)
	 nsd = (int)gcd(nom,denom);
	else
	 nsd = (int)gcd(-nom,denom);

	nom /= nsd;
	denom /= nsd;
}


Rational Hregory(double eps){
	Rational s;
	int sign = -1;
	for(int i=2;eps*i*i<1;i++){
		Rational tmp;
		tmp.setNom(sign);
		sign = -sign;
		tmp.setDenom(i*i);
		//s = s.add(tmp); //+=
		s = s + tmp; 
		if(tmp<1.0/(i*i)) break;
	}
	return s;
}



void writeToFile(std::string fname, const Rational& r){
   
   try{
    std::fstream f1;
    f1.open(fname.c_str(), std::ios::app);
    
    f1 << r.nom<<r.denom;
     f1.close();
   }
   catch(...){
    std::cerr<<"problems with writing to file";
  }
}

