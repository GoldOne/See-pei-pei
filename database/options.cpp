/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>

#include "database.h"

using namespace std;

const char key[]={'I','N','G'};

const char order[]={'A','D'};

void options(student stl[],int record)
{
	char sortkey[3];
	char orderkey[3];
	cout<<"The default sorting configuration is "<<endl;
	cout<<"First Sort Key: ID , ascending."<<endl;
	cout<<"Second Sort Key: Name, ascending."<<endl;
	cout<<"Third Sort Key: GPA, descending."<<endl;
	for(int i=0;i<3;i++)
	{
		switch(i)
		{
			case 0:
				cout<<"Please enter the first sort key "<<endl;
				break;
			case 1:
				cout<<"Please enter the Second sort key "<<endl;
				break;
			case 2:
				cout<<"Please enter the Third sort key "<<endl;
				break;
		}
		char temp;
		
		do
		{
			cout<<"I - ID\n";
			cout<<"N - Name\n";
			cout<<"G - GPA\n";
			temp=getChar(key,sizeof(key));	

			switch (temp)//display the command
			{
				case 'I':
					sortkey[i]='I';
					break;
				case 'N':
					sortkey[i]='N';
					break;
				case 'G':
					sortkey[i]='G';
					break;
				default:
					cerr << "Please enter a correct character!!!"<<endl;
			}
		}while(temp !='I' && temp!='N'&&temp !='G');	
		
		switch(i)
		{
			case 0:
				cout<<"Please enter the order of first sort key "<<endl;
				break;
			case 1:
				cout<<"Please enter the order of Second sort key "<<endl;
				break;
			case 2:
				cout<<"Please enter the order of Third sort key "<<endl;
				break;
		}	

		char Temp;
		
		do
		{
			cout<<"A - Ascending\n";
			cout<<"D - Descending\n";
			Temp=getChar(order,sizeof(order));	

			switch (Temp)//display the command
			{
				case 'A':
					orderkey[i]='A';
					break;
				case 'D':
					orderkey[i]='D';
					break;
				default:
					cerr << "Please enter a correct character!!!"<<endl;
			}
		}while(Temp !='A' && Temp!='D');
	}
	
	
	cout<<"Sorting ... Please wait..."<<endl;
	cout<<endl;
	sort(stl,record,orderkey,sortkey);
	for(int i=0;i<record;i++)
	{
		cout<<"==========Sorted Result=========="<<endl;
		cout<<"ID: "<<stl[i].ID<<endl;
		cout<<"Name: "<<stl[i].name<<endl;
		cout<<"GPA: "<<stl[i].GPA<<endl;
		cout<<endl;
	}
}










