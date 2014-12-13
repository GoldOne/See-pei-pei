//Yi Jin,4370673
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include"Date.h"
#include<sstream>
#include<cstdlib>
class Employee
{
	friend std::ostream& operator<<(std::ostream&,Employee &);
	friend void operator>>(std::stringstream &,Employee &);
	protected://this class will be inheritaged
		int number;
		std::string name;
		MyLib::Date DOB;
		std::string Address;
		std::string type;
	public:
		Employee(){};
		virtual ~Employee(){};//virtual destructor for delete obeject pointers dynamically
		void setNumber(int num){number=num;};
		int getNumber() const {return number;};
		void setName(std::string n) {name=n;};
		std::string getName() const {return name;};
		void setAddress(std::string a){Address=a;};
		std::string getAddress() const {return Address;};
		void setType(std::string t) {type=t;};
		std::string getType() const {return type;};
};
#endif
