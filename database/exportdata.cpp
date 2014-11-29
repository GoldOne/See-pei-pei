/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include <fstream>
#include "database.h"
using namespace std;
const char STARTLABEL[]="###START###";
const char RECORDLABEL[]="###RECORD###";
const char ENDLABEL[]="###END###";

void exportdata(student stl[],int rec)

{
	int ow=0;//judge the operation for overwrite

	ofstream fout;
	
	ifstream fin;
	
	char overwrite;
	
	char name[100];
	
	cout<<"Please enter the file name you want to output: ";
	
	cin>> name;
	fin.open(name);	
	if (fin.good())
	{
		do
		{
			cout<<"The file has already existed!! Do you want to overwirte it? (y/n)? ";
			overwrite=getChar(validcommanD,sizeof(validcommanD));
			switch (overwrite)//display the command
			{
				
				case 'y':
					break;
				
				case 'n':ow=2;
					cout<<"Export data canselled!!!"<<endl;
					break;
				default:
					cerr << "Illegal input!!!"<<endl;
					cerr << "Please enter a correct character!!!"<<endl;
			}
			cout<<overwrite<<endl;
		}while(overwrite !='n'&& overwrite !='y');

	}
	
	if (ow==0)
	{
		fout.open(name);
		fout<<STARTLABEL<<endl;
		for (int i=0; i<rec; i++)
		{
			fout<<RECORDLABEL<<endl;
			fout<<stl[i].name<<endl;
			fout<<stl[i].ID<<endl;
			fout<<stl[i].CourseName<<endl;
			
			for (int j=0;j<stl[i].cs;j++)
			{
				fout<<stl[i].sul[j].year<<stl[i].sul[j].session
				<<stl[i].sul[j].code<<stl[i].sul[j].credit
				<<stl[i].sul[j].Mark<<endl;
			}
		}
		fout<<ENDLABEL<<endl;
		fout.close();
		cout<<"Export file completed!!!"<<endl;
	}
}
			
			
			
			
			
			
			
			
			
			
			
			
			
