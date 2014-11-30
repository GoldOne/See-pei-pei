/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "database.h"
using namespace std;
const char STARTLABEL[]="###START###";
const char RECORDLABEL[]="###RECORD###";
const char ENDLABEL[]="###END###";


int getData(student stl[],int &rec)
{
	int ow=0;//the symbol to judge whether to overwrite the records or not
	char name[100];
	char overwrite;
	cout<<"Please enter the name of the file you want to import: ";
	cin>>name;
	int index=0;
	char junk[100];//eat the label
	char junk2;//see whether next is the label or not 
	fstream fin;
	fin.open(name);
	if(!fin.good())
	{
		cout << "File does not exist!" << endl;
		exit(1);
	}
	fin.getline(junk,sizeof(junk),'\n');
	junk2=fin.peek();
	
	while (!fin.eof())
	{
		
		int courses=0;
		int scorce[Maxsubject]={0};
		int credit[Maxsubject]={0};
		if (junk2=='#')
			fin.getline(junk,sizeof(junk),'\n');
		if (strcmp(junk,ENDLABEL)==0)
			break;	
		char temp1[31];
		fin.getline(temp1,sizeof(temp1));	
		char temp[8];
		fin.getline(temp,sizeof(temp));
		//cout<<"temp is"<<temp<<endl;
		for (int i=0;i<rec;i++)
		{
			if (strcmp(temp,stl[i].ID)==0)
			{
				do	
				{
					cout<<"There is a duplicated record student ID ("<<stl[i].ID<<") in the system, would you like to over write it? (y/n): ";	
					overwrite=getChar(validcommanD,sizeof(validcommanD));
					
					switch (overwrite)//display the command
					{
						
						case 'y':ow=1;
							break;
						
						case 'n':ow=2;
							break;
						default:
							cerr << "Illegal input!!!"<<endl;
							cerr << "Please enter a correct character!!!"<<endl;
					}
					cout<<overwrite<<endl;
				}while(overwrite !='n'&& overwrite !='y');
			}
		}
		
		if(ow==0||ow==1)
		{
			strcpy(stl[index].name,temp1);
			strcpy(stl[index].ID,temp);
			fin.getline(stl[index].CourseName,Maxcourse+1);
		
			int cos=0;
			do 
			{			
				fin.getline(stl[index].sul[courses].year,5);
				
				fin.clear();	
			
				fin.getline(stl[index].sul[courses].session,2);
				
				fin.clear();
			
				fin.getline(stl[index].sul[courses].code,8);
				
				fin.clear();
			
				fin.getline(stl[index].sul[courses].credit,3);
				
				credit[courses]=transint(stl[index].sul[courses].credit);//transfer char to int
				fin.clear();
			
				fin.getline(stl[index].sul[courses].Mark,3);
				if (stl[index].sul[courses].Mark[0]!='e'||stl[index].sul[courses].Mark[0]!='w')
					scorce[courses]=transint(stl[index].sul[courses].Mark);//transfer char to int
				
				fin.clear();
			
				courses++;
				cos++;
				junk2=fin.peek();
						
			}while (junk2!='#'&& cos<30);//max subjects are 30
			stl[index].cs=cos;		
			gpa(stl,scorce,credit,courses,index);	
		}
		if(ow==0)
			index++;
		if(ow==2)
		{
			cout<<"Import data canceled!!!"<<endl;
			break;
		}

	}
	fin.close();
	if(ow!=2)
		cout<<"All data imported sucessfully!!!"<<endl;
	return index;
}