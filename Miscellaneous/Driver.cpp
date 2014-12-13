//Yi Jin,4370673
#include"Driver.h"
using namespace std;

ostream& operator<<(ostream& out,Driver &d)
{
	out<<(Employee &)d<<d.LicenseNumber<<endl;//cast and use base class friend function to output
	
	return out;
}

void operator>>(stringstream &stemp,Driver &d)
{
	stemp>>(Employee &)d;//cast and use base class friend function to input
	char temp[256];
	stemp.getline(temp,256,'\n');
	int num=atoi(temp);
	d.LicenseNumber=num;
}
