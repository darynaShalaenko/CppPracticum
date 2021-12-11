#ifndef __PERSON__
#define __PERSON__

#include <string>
#include <iostream>


class Person{ 
	protected:
	std::string name; 
	unsigned byear;

	public:
	int input(){
		std::cout<<"Input name";
		std::cin>>name;
		std::cout<<"year:";
		std::cin>>byear;
	} 
	void show(){
		std::cout<< name<< " of "<<byear<<"\n";
	} 

	friend std::ostream& operator<<(std::ostream & of, const Person & p){
		of<<p.name<<", "<<p.byear<<"\n";
		return of;
	}

	friend std::istream& operator>>(std::istream & of, Person & p){
		of>>p.name;
		of>>p.byear;
		return of;
	}

	std::string getName(){
		return name;
	}


	void setName(std::string s){
		name = s;
	}

};


#endif // #define __PERSON__

