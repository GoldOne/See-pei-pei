/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>

#include "database.h"

using namespace std;

const char validvalue[]={'<','>','='};

char gpasearch(student stl[],int record,int &count,int result[],int &page)

{	
	bool find=false;
	float gpa;
	char symbol;
	cin.ignore();
	cout<<"Please enter GPA value: ";
	gpa=getInt();
	cout<<"Your entered gpa is "<<gpa<<"."<<endl;
	do
	{
		cout<<"Please enter symbol of it (<,>,=)";
		symbol=getChar(validvalue,sizeof(validvalue));
		
		switch (symbol)
		{
			case '=':
				cout<<"Searching... Please wait!!!"<<endl;
				for (int i=0;i<record;i++)
				{
					if(stl[i].GPA>=gpa-1&&stl[i].GPA<=gpa+1)
					{
						find=true;
						static int j=0;
						result[j]=i;
						j++;
						count++;
					}
				}
				if(find!=true)
				{
					char temp='R';
					cout<<"Nothing found !!!"<<endl;
					return temp;
				}
				else display(stl,page,result,record);
				break;
			case '<':
				cout<<"Searching... Please wait!!!"<<endl;
				for (int i=0;i<record;i++)
				{
					if (stl[i].GPA<gpa)
					{
						find=true;
						static int j=0;
						result[j]=i;
						j++;
						count++;
						
					}
				}
				if(find!=true)
				{
					char temp='R';
					cout<<"Nothing found !!!"<<endl;
					return temp;
				}
				else display(stl,page,result,record);
				break;
			case '>':
				cout<<"Searching... Please wait!!!"<<endl;
				for (int i=0;i<record;i++)
				{
					if (stl[i].GPA>gpa)
					{
						find=true;
						static int j=0;
						result[j]=i;
						j++;
						count++;
					}
				}
				if(find!=true)
				{
					char temp='R';
					cout<<"Nothing found !!!"<<endl;
					return temp;
				}
				else display(stl,page,result,record);
				break;
			default:
				cerr << "Illegal input"<<endl;
				cerr << "Please enter a correct symbol"<<endl;
		}
	
	}while(symbol !='='&&symbol !='<'&&symbol !='>');
	return symbol;
}
