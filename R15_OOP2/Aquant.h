
#ifndef __AQUANT__
#define __AQUANT__

#include "Person.h"

class Aquant : public Person{

	protected:
	long long tel;

	public:
	Aquant(){}
	Aquant(std::string pname, unsigned y, long long t){
	 	name = pname;
		byear= y;
		tel =t;
	}

	//Override
	void show(){
		Person::show();
		std::cout<<"Phone:"<<tel;
	}

	
	friend std::ostream& operator<<(std::ostream & of, Aquant & p){
		//of<< "sadas";
		of<<p.getName()<<", "<<", "<<p.getPhone()<< "\n";
		return of;
	}

	friend std::istream& operator>>(std::istream & of, Aquant & p){
		std::string s;
		unsigned age;
		long long tel;
		of>>s;
		of>>age;
		of>>tel;
		p.setPhone(tel);
		p.setName(s);
		return of;
	}
  
	void setPhone(long long s){
		tel =s;
	}

	long long getPhone(){
		return tel;
	}

};





#endif // class __AQUANT__
