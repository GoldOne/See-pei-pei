/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include "database.h"
using namespace std;

const char Session[]={'A','S'};

const char MS[]={'M','S'};

const char ew[]={'e','w'};

char edit(student stl[],int page,int result[])

{	
	cout<<"Attention!!! For all options, if you just press enter, it means keeping the existing value."<<endl;
	int marK=0;//the new mark from user input
	char temp;
	bool find=false;
	int id=0;//the new id from user input
	int length=0;//the length of user input
	int iD=0;//the new year from user input
	int cd=0;//the new credit from user input
	char name[100];
	char ID[8];
	char CourseName[100];
	float GPA=-1;
	char year[30][5];
	char session[30][1];
	char code[30][subjectname+1];
	char Mark[30][3];
	char credit[30][3];
	cout<<"Please enter a new name: "; 
	do
	{
		cin.get();
		cin.getline(name,sizeof(name));
		length=strlen(name);
		
		if (length>30)
		{
			cout<<"The name is too long !!!"<<endl;
			cout<<"Please enter again !!!"<<endl;
		}
	}while(length>30);	
	cout<<"Please enter a new ID: ";	
	do
	{
		do
		{	
			find=false;
			id=getint();
			if (id<0 || id>9999999)
				cout<<"ID is too long or it is a negative number, please enter again !!!"<<endl;
		}while(id<0 || id>9999999);
			
		for (int i=0; i<databasesize;i++)
		{
			int temp[databasesize];
			temp[i]=atoi(stl[i].ID);
			if (temp[i]==id)
				find=true;
		}
		if (find)		
			cout<<"Your entered ID is already existed or you enter a NULL value, please enter agian!!!"<<endl;
	}while(find==true);	
	sprintf(ID,"%d",id);
	cout<<"Please enter the Course Name: ";
	do
	{
		cin.getline(CourseName,sizeof(CourseName));
		length=strlen(CourseName);
		
		if (length>85)
		{
			cout<<"The Course Name is too long !!!"<<endl;
			cout<<"Please enter again !!!"<<endl;
		}
	}while(length>85);	
	cout<<"Please enter the GPA: ";
	GPA=getInt();
	for (int i=0;i<stl[result[page]].cs;i++)
	{
	
		cout<<"Please enter the "<<i+1<< " year: ";
		do
		{	
			
			iD=getint();
			if (iD<0 || iD>9999)
				cout<<"Please enter a correct year !!!"<<endl;
			
		}while(iD<0 || iD>9999);
		sprintf(year[i],"%d",iD);
		cout<<"Please enter the "<<i+1<< " session (A/S): ";
		do
		{
			session[i][0]=getChar(Session,sizeof(Session));	
			if(session[i][0]!='A'&&session[i][0]!='S')
				cout<<"Please enter 'A' or 'S' only!!!: "<<endl;
		}while(session[i][0]!='A'&&session[i][0]!='S');
		cout<<"Please enter the "<<i+1<<" subject code: ";
		cin.get();
		do
		{
			
			cin.getline(code[i],sizeof(code[i]));
			length=strlen(code[i]);
			
			if (length>7)
			{
				cout<<"The subject code is too long !!!"<<endl;
				cout<<"Please enter again !!!"<<endl;
			}
		}while(length>7);		
		cout<<"Please enter the "<<i+1<<" credit: ";
		do
		{	
			
			cd=getint();
			if (cd<0 || cd>99)
			cout<<"Please enter a correct credit !!!"<<endl;
			
		}while(cd<0 || cd>99);
		sprintf(credit[i],"%d",cd);		
		cout<<"Please enter the "<<i+1<<" Mark (M for Mark, S for Status): ";
		do
		{		
			cin>>temp;	
			if(temp!='M'&&temp!='S')
				cout<<"Please enter 'M' or 'S' only!!!: "<<endl;
		}while(temp!='M'&&temp!='S');
		switch (temp)
		{
			case 'M':cout<<"Please enter a mark between 0 and 100: ";
				cin.get();
				do
				{			
					marK=getInt();
					if (marK<0 || marK>100)
						cout<<"Please enter a correct credit !!!"<<endl;
					
				}while(marK<0 || marK>100);
				sprintf(Mark[i],"%d",marK);
				break;
			case 'S':cout<<"Please enter Status (e for enroll, w for withdraw): ";
				do
				{
					Mark[i][0]=getChar(ew,sizeof(ew));	
					if(Mark[i][0]!='e'&&Mark[i][0]!='w')
						cout<<"Please enter 'e' or 'w' only!!!: "<<endl;
				}while(Mark[i][0]!='e'&&Mark[i][0]!='w');
				break;
		}
			
	}		
	cout<<"************Edited Record************"<<endl;		
	
	cout<<"New Name: "<<name<<endl;
	
	cout<<"New ID: "<<ID<<endl;
	
	cout<<"New Course Name: "<<CourseName<<endl;
	if(GPA!=-1)
		cout<<"New GPA: "<<GPA<<endl;
	for (int i=0;i<stl[result[page]].cs;i++)
	{
		cout<<"New year: "<<year[i]<<endl;
		
		cout<<"New session: "<<session[i]<<endl;	
	
		cout<<"New Subject Name: "<<code[i]<<endl;	
	
		cout<<"New Credit: "<<credit[i]<<endl;
	
		cout<<"New Mark: "<<Mark[i]<<endl;	
	}
	
	cout<<"========================================================="<<endl;	
	
	cout<<"************Record************"<<endl;
	cout<<"Name: "<<stl[result[page]].name<<endl;
	cout<<"ID: "<<stl[result[page]].ID<<endl;
	cout<<"Course Name: "<<stl[result[page]].CourseName<<endl;
	cout<<"GPA: "<<stl[result[page]].GPA<<endl;
	for (int j=0; j<stl[result[page]].cs;j++)
	{
		cout<<"Year: "<<stl[result[page]].sul[j].year<<endl;
		cout<<"Session: "<<stl[result[page]].sul[j].session<<endl;
		cout<<"Subject Name: "<<stl[result[page]].sul[j].code<<endl;
		cout<<"Subject Credit: "<<stl[result[page]].sul[j].credit<<endl;
		cout<<"Subject Mark or Status: "<<stl[result[page]].sul[j].Mark<<endl;
	} 
	cout<<"************Record************"<<endl;	
	
	char symbol;
	char overwrite;
	do
	{
		cout<<"Do you really want to modify record? (y/n)? ";
		overwrite=getChar(validcommanD,sizeof(validcommanD));
		switch (overwrite)//display the command
		{	
			case 'y':
				break;
			
			case 'n':
				break;
			default:
				cerr << "Illegal input!!!"<<endl;
				cerr << "Please enter a correct character!!!"<<endl;
		}
		cout<<overwrite<<endl;
	}while(overwrite !='n'&& overwrite !='y');		
			
	if (overwrite=='y')
	{	
		strcpy(stl[result[page]].name,name);
		strcpy(stl[result[page]].ID,ID);
		strcpy(stl[result[page]].CourseName,CourseName);
		stl[result[page]].GPA=GPA;
		
		for (int i=0; i<stl[result[page]].cs;i++)
		{
			strcpy(stl[result[page]].sul[i].year,year[i]);	
			strcpy(stl[result[page]].sul[i].session,session[i]);
			strcpy(stl[result[page]].sul[i].code,code[i]);
			strcpy(stl[result[page]].sul[i].credit,credit[i]);
			strcpy(stl[result[page]].sul[i].Mark,Mark[i]);
		}	
		
		cout<<"Record updated !!!"<<endl;
		
	}				
	symbol='S';
	return symbol;						
}
