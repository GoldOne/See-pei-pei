/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include <cstring>
#include "database.h"
using namespace std;

char del(student stl[],int page,int result[],int &record)

{
	char symbol;//the symbol for return to the main menu
	char overwrite;
	do
	{
		cout<<"Do you really want to delete this record? (y/n)? ";
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
		if (result[page]<record)
		{	
			strcpy(stl[result[page]].name,stl[result[page]+1].name);
			strcpy(stl[result[page]].ID,stl[result[page]+1].ID);
			strcpy(stl[result[page]].CourseName,stl[result[page]+1].CourseName);
			stl[result[page]].GPA=stl[result[page]+1].GPA;
			stl[result[page]].cs=stl[result[page]+1].cs;
			for (int i=0; i<stl[result[page]+1].cs;i++)
			{
				strcpy(stl[result[page]].sul[i].year,stl[result[page]+1].sul[i].year);	
				strcpy(stl[result[page]].sul[i].session,stl[result[page]+1].sul[i].session);
				strcpy(stl[result[page]].sul[i].code,stl[result[page]+1].sul[i].code);
				strcpy(stl[result[page]].sul[i].credit,stl[result[page]+1].sul[i].credit);
				strcpy(stl[result[page]].sul[i].Mark,stl[result[page]+1].sul[i].Mark);
			}
			record--;	
			symbol='R';	
			cout<<"Record deleted !!!"<<endl;
			return symbol;
			
		}
		else
		{
			record--;
			symbol='R';	
			cout<<"Record deleted !!!"<<endl;
			return symbol;
		}
	}	
			
	symbol='o';
	return symbol;
}
			
			
			
			
			
