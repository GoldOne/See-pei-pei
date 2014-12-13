//Yi Jin,4370673
#include"Administrator.h"
using namespace std;

ostream& operator<<(ostream& out,Administrator &a)
{
	out<<(Employee &)a<<a.roomNumber<<endl;//cast and use base class friend function to output
	
	return out;
}

void operator>>(stringstream &stemp,Administrator &a)
{
	stemp>>(Employee &)a;//cast and use base class friend function to input
	char temp[256];
	stemp.getline(temp,256,'\n');
	int num=atoi(temp);
	a.roomNumber=num;
}
