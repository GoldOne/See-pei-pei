//Yi Jin,4370673
#include"Technician.h"
using namespace std;

ostream& operator<<(ostream& out,Technician &t)
{
	out<<(Employee &)t<<t.skill<<","<<t.skillLevel<<endl;//cast and use base class friend function to output

	return out;
}

void operator>>(stringstream &stemp,Technician &t)
{
	stemp>>(Employee &)t;//cast and use base class friend function to input
	char temp[256];
	stemp.getline(temp,256,',');
	t.skill=temp;
	stemp.getline(temp,256,'\n');
	int num=atoi(temp);
	t.skillLevel=num;
}
