/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include <cstring>
#include "database.h"

using namespace std;

char subjectsearch(student stl[],int record,int &count,int result[],int &page)

{
	int length=0;//the length of user input
	int sign=0;//the position of '*'
	int mark=0;//the status of '*'
	bool find=false;
	cin.ignore();
	char temp[100];
	cout<<"Please enter the name of the subject (case sensitive) ";
	cin.getline(temp,sizeof(temp));
	length=strlen(temp);
	for (int i=0; i<100;i++)
	{
		if (temp[i]=='*')
		{
			sign=i;
			if(i>0&&length>1)
				mark=1;
			if (sign==0&&length>1)
				mark=2;
			if (sign==(length-1)&&length!=1)
				mark=3;
			if (i==0&&length==1)
				mark=4;	
		}
	}

	switch (mark)
	{
		case 0: cout<<"Searching... Please wait!!!"<<endl;
			for(int i=0;i<record;i++)
			{
				for (int j=0;j<stl[i].cs;j++)
				{
					
					char temp1[30];
			
					strcpy(temp1,stl[i].sul[j].code);
				
					if (strcmp(temp,temp1)==0)
					{
						find=true;
						static int j=0;
						result[j]=i;
						j++;
						count++;	
					}
				}
			}
			break;
		case 1: cout<<"Searching... Please wait!!!"<<endl;
			for(int i=0;i<record;i++)
			{
				for (int j=0;j<stl[i].cs;j++)
				{
					char temp1[30];
					int lon=0;
					lon=strlen(stl[i].sul[j].code);
					strcpy(temp1,stl[i].sul[j].code);
							
					if (temp[length-1]==temp1[lon-1]&&temp[0]==temp1[0])
					{
				
						find=true;
						static int j=0;
						result[j]=i;
						j++;
						count++;
					}
				}
			}
			break;
		case 2: cout<<"Searching... Please wait!!!"<<endl;
			for(int i=0;i<record;i++)
			{
				for (int j=0;j<stl[i].cs;j++)
				{
					char temp1[30];
					int lon=0;
					lon=strlen(stl[i].sul[j].code);
					strcpy(temp1,stl[i].sul[j].code);
						
					if (temp[length-1]==temp1[lon-1])
					{
				
						find=true;
						static int j=0;
						result[j]=i;
						j++;
						count++;
					}
				}
			}
			break;
		case 3:	cout<<"Searching... Please wait!!!"<<endl;
			for(int i=0;i<record;i++)
			{
				for (int j=0;j<stl[i].cs;j++)
				{
					char temp1[30];
					strcpy(temp1,stl[i].sul[j].code);
					if (temp[0]==temp1[0])
					{
				
						find=true;
						static int j=0;
						result[j]=i;
						j++;
						count++;
					}
				}
			}
			break;
		case 4: cout<<"Searching... Please wait!!!"<<endl;
			for(int i=0;i<record;i++)
			{
				find=true;
				result[i]=i;
				count++;
			}
			break;
	}
	if(find!=true)
	{
		char temp='R';
		cout<<"Nothing found !!!"<<endl;
		return temp;
	}
	else 
	{
		display(stl,page,result,record);
		return temp[41];
	}
}
