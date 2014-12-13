//Yi Jin,4370673
#include"Date.h"
#include<cstdlib>
#include<sstream>
using namespace std;
using namespace MyLib;

void Date::setDate(const string &str)
{
	string d=str.substr(0,2);//take each data member from a sub string
	string m=str.substr(3,2);
	string y=str.substr(6,4);
	
	day=atoi(d.c_str());//convert into int
	month=atoi(m.c_str());
	year=atoi(y.c_str());
}

void Date::toString()
{
	string result;

	stringstream ss;
	if(day<10&&month<10)
		ss<<"0"<<day<<"/0"<<month<<"/"<<year;
	else if(day<10)
		ss<<"0"<<day<<"/"<<month<<"/"<<year;
	else if(month<10)
		ss<<day<<"/0"<<month<<"/"<<year;
	else
		ss<<day<<"/"<<month<<"/"<<year;

	ss>>result;

	cout<<result<<endl;
}

void Date::validDate()
{
	if(year<0)
		throw(string("Invalid year."));
	if(month<1||month>12)
		throw(string("Invalid month."));
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		if(day<1||day>31)
			throw(string("Invalid day. Day should be between 1 and 31"));
	}
	if(month==4||month==6||month==9||month==11)
	{
		if(day<1||day>30)
			throw(string("Invalid day. Day should be between 1 and 30"));
	}
	if((year%4==0&&year%100!=0)||year%400==0)
	{
		if(month==2&&(day<1||day>29))
			throw(string("Invalid day. Day should be between 1 and 29"));
	}
	else
	{
		if(month==2&&(day<1||day>28))
			throw(string("Invalid day. Day should be between 1 and 28"));
	}
}

string Date::getDate()
{
	string result;

	stringstream ss;
	
	if(day<10&&month<10)
		ss<<"0"<<day<<"/0"<<month<<"/"<<year;
	else if(day<10)
		ss<<"0"<<day<<"/"<<month<<"/"<<year;
	else if(month<10)
		ss<<day<<"/0"<<month<<"/"<<year;
	else
		ss<<day<<"/"<<month<<"/"<<year;

	ss>>result;
	
	return result;
}	
