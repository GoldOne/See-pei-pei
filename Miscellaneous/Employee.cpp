//Yi Jin,4370673
#include"Employee.h"
using namespace std;
using namespace MyLib;

ostream& operator<<(ostream &out,Employee &e)
{
	out<<e.type<<","<<e.number<<","<<e.name<<","<<e.DOB.getDate()<<","<<e.Address<<",";

	return out;
}

void operator>>(stringstream &stemp,Employee &e)
{
	char temp[256];//store data members by "," respectively
	stemp.getline(temp,256,',');
	int num=atoi(temp);
	e.number=num;
	stemp.getline(temp,256,',');
	e.name=temp;
	stemp.getline(temp,256,',');
	try
	{
		e.DOB.setDate(temp);
		e.DOB.validDate();
	}catch(string error)
	{
		throw(error);
	}
	stemp.getline(temp,256,',');
	e.Address=temp;
}
