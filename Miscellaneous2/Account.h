//Yi Jin,4370673
#include"Date.h"
#include<sstream>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<iostream>
using namespace MYLIB;

class Account
{
	friend std::ostream& operator<<(std::ostream&,const Account &);
	friend void operator>>(std::stringstream &,Account &);

	private:
		int number;
		char name[20];
		char sex[2];
		Date DOB;
		char address[41];
		float balance;
	public:
		Account(){};
		Account operator=(const Account &);
		char* getName(){char* temp=new char[20];strcpy(temp,name);return temp;}
		bool operator<=(const Account &a){return number<=a.number;};
};

std::ostream& Currency(std::ostream& );
