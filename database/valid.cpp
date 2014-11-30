/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "database.h"
using namespace std;

const char vc[]={'I','A'};

const char VC[]={'B','A'};

void valid(student stl[],int record)

{
	bool check=false;
	cout<<"Checking for mismatch records between course code and course name..."<<endl;
	int cc[record];
	string cn[record];
	for (int i=0;i<record;i++)
	{
		cc[i]=atoi(stl[i].CourseName);
		string temp=stl[i].CourseName;
		if (cc[i]/1000==0)
			cn[i]=temp.substr(4);
		else
			cn[i]=temp.substr(5);
	}
	for (int i=0;i<record;i++)
	{
		for(int j=0;j<record;j++)
		{
			if(((i!=j)&&cc[i]==cc[j]&&cn[i].compare(cn[j])!=0)||((i!=j)&&cc[i]!=cc[j]&&cn[i].compare(cn[j])==0))
				{
					check=true;
					cout<<"==========Mismatch Record=========="<<endl;
					cout<<"1."<<stl[i].CourseName<<endl;
					cout<<"2."<<stl[j].CourseName<<endl;
					cout<<"What do you want to do?"<<endl;
					char temp;
					do
					{
						cout << "I - Ignore\n";
						cout << "A - All records to one of these conflicting names\n";
						temp=getChar(vc,sizeof(vc));	
	
						switch (temp)//display the command
						{
							case 'I':
								break;
							case 'A':
								char temP;
								do
								{
									cout<<"Which one of the record do you want to set?"<<endl;
									cout<<"A."<<stl[i].CourseName<<endl;
									cout<<"B."<<stl[j].CourseName<<endl;
									temP=getChar(VC,sizeof(VC));
									switch(temP)
									{
										case 'A':
											strcpy(stl[j].CourseName,stl[i].CourseName);
											cc[j]=cc[i];
											cn[j]=cn[i];	
										break;
										case 'B':
											strcpy(stl[i].CourseName,stl[j].CourseName);
											cc[i]=cc[j];
											cn[i]=cn[j];
										break;
										default:
											cerr << "Please enter a correct character!!!"<<endl;
									}
								}
								while(temP !='B' && temP!='A');
								cout<<"Mismatch Record updated!!!"<<endl;
								break;
								
							default:
								cerr <<"Please enter a correct character!!!"<<endl;
						}
			
					}while(temp !='I' && temp!='A');
				}
			}
	}
	if(check==false)
		cout<<"No mismatch record found!!!"<<endl;			
}
