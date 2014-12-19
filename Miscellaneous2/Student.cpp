//Yi Jin,4370673
#include<cstdlib>
#include"Student.h"
using namespace std;

ostream& operator<<(ostream &out,const Student &s)
{
	out<<s.number<<","<<s.name<<","<<s.email;

	return out;
}

istream& operator>>(istream &in,Student &s)
{
	int static i=0;

	if(i==0)
		in.ignore();

	string tmp;
	cout<<"Input number: ";
	getline(in,tmp,'\n');
	s.number=atoi(tmp.c_str());
	cout<<"Input name: ";
	getline(in,s.name,'\n');
	cout<<"Input email: ";	
	getline(in,s.email,'\n');

	i++;

	return in;
}

