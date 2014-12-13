//Yj742,4370673
#include"Date.h"
#include<cstdlib>
using namespace std;
using namespace MyLib;

int main()
{
	Date dates,Dates;

	string date;
	cout<<"Input date (DD/MM/YYYY): ";
	cin>>date;
	dates.setDate(date);
	try
	{
		dates.validDate();
	}catch(string err)
	{
		cout<<err<<endl;
		exit(1);
	}
	dates.toString();

	int day,month,year;
	cout<<"Input day: ";
	cin>>day;
	cout<<"Input month: ";
	cin>>month;
	cout<<"Input year: ";
	cin>>year;
	Dates.setDate(day,month,year);
	try
	{
		Dates.validDate();
	}catch(string err)
	{
		cout<<err<<endl;
		exit(1);
	}
	Dates.toString();

	return 0;
}
