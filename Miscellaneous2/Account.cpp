//Yi Jin,4370673
#include"Account.h"
using namespace std;
using namespace MYLIB;

ostream& operator<<(ostream &out,const Account &a)
{
	out<<setw(10)<<setfill('0')<<a.number<<" "<<setw(19)<<setfill(' ')<<left<<a.name<<" "<<a.sex<<"   "<<a.DOB.toString()<<" "<<setw(40)<<a.address<<" "<<Currency<<a.balance;

	return out;
}

void operator>>(stringstream &stemp,Account &a)
{
	char temp[256];
	string tmp;
	stemp.getline(temp,256,',');
	int num=atoi(temp);
	a.number=num;
	stemp.getline(temp,256,',');
	strcpy(a.name,temp);
	stemp.getline(temp,256,',');
	strcpy(a.sex,temp);
	stemp.getline(temp,256,',');
	istringstream is(temp);	
	is>>tmp;
	a.DOB.setDate(tmp);
	stemp.getline(temp,256,',');
	strcpy(a.address,temp);;
	stemp.getline(temp,256,'\n');
	a.balance=atof(temp);
}

ostream& Currency(ostream& out)//manipulator
{
	out<<'$';
	out<<setprecision(2);
	out<<fixed<<setfill('0')<<right;
	out.width(10);

	return out;
}

Account Account::operator=(const Account& a)
{
	number=a.number;
	strcpy(name,a.name);
	strcpy(sex,a.sex);
	DOB=a.DOB;
	strcpy(address,a.address);
	balance=a.balance;
	return *this;
}

