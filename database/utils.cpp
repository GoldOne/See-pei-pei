/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include "database.h"
using namespace std;

void getCString(char input[], unsigned int MAX, bool allowNULL)
{
	bool errflag=false;
	do
	{
		char buf[BUFMAX+1]="";
		if (errflag==true)
		{
			cout << "Input should be less than " << MAX+1 << " characters and it " << ((allowNULL==true)?"can":"cannot") << " be NULL" << endl;
			cout << "Please enter again. " << endl;
		}
		cin.getline(buf, sizeof(buf), '\n');
		if ((strlen(buf)>MAX) || (strlen(buf)==0 && !allowNULL))
			errflag=true;
		else
		{
			strcpy(input, buf);
			errflag = false;
		}
	} while (errflag==true);
}
int getPositiveInt(int min, int max)
{
	int res=0;
	bool errflag = false;
	do
	{
		char buf[BUFMAX+1]="";
		if (errflag == true)
			cout << "Invalid Input. Please enter an integer between " << min << " and " << max << ": " ;
		getCString(buf, sizeof(buf), false);
		res = atoi(buf);
		if (res <min || res >max)
			errflag = true;
		else
			errflag = false;
	} while (errflag == true);
	return res;
}

float getInt()//transfer char to float!!!
{
	int length=0;
	bool alpha=false;
	char input[256];
	do
	{
		
		cin.getline(input,sizeof(input));
		length=strlen(input);
		for (int i=0;i<length;i++)
		{
			if (isalpha(input[i])!=0)
			{
				alpha=true;
				cout<<"Please enter a number !!! ";
				break;
			}	
			else alpha=false;
		}
	}while(alpha==true);
	
	return atoi(input);	
	
}
int getint()
{
	int length=0;
	bool alpha=false;
	char input[256];
	do
	{
		
		cin.getline(input,sizeof(input));
		length=strlen(input);
		for (int i=0;i<length;i++)
		{
			if (isalpha(input[i])!=0)
			{
				alpha=true;
				cout<<"Please enter a number !!! ";
				break;
			}	
			else alpha=false;
		}
	}while(alpha==true);
	
	return atoi(input);	
	
}
/////////////////////////////////////////////////////////////////////
void sort(student stl [], int size, char orderkey[],char sortkey[])
{
	for (int i = 0; i < size; i++)
		for (int j=0; j< size-1; j++)
			if (cmp(stl[j], stl[j+1],orderkey,sortkey)>0)
			{
				swap(stl[j], stl[j+1]);
				cout<<stl[j].ID<<endl;
				cout<<stl[j].name<<endl;
				cout<<stl[j].GPA<<endl;
			}
}
int cmp(student &A, student &B,char orderkey[],char sortkey[])
{
	for (int i=0;i<3;i++)
	{
		switch(sortkey[i])
		{
			case 'I':if (cmpID(A.ID, B.ID,orderkey,i)==0)
						break;
					else
						return cmpID(A.ID, B.ID,orderkey,i);
			case 'N':if (cmpName(A.name, B.name, orderkey,i)==0)
						break;
					else 
						return cmpName(A.name, B.name, orderkey,i);
			case 'G':if (cmpGPA(A.GPA, B.GPA, orderkey,i)==0)
						break;
					else
						return cmpGPA(A.GPA, B.GPA, orderkey,i);
		}
	}
	return 0;
	
}
int cmpID(char A[],char B[], char orderkey[],int i)
{
	if(orderkey[i]=='A')
	{
		if (strcmp(A,B)>0)
			return 1;
		else if (strcmp(A,B)<0)
			return -1;
	}
	if(orderkey[i]=='D')
	{
		if (strcmp(A,B)<0)
			return 1;
		else if (strcmp(A,B)>0)
			return -1;
	}		
	return 0;		
}
int cmpName(char A[],char B[], char orderkey[],int i)
{
	if(orderkey[i]=='A')
	{
		if (strcmp(A,B)>0)
			return 1;
		else if (strcmp(A,B)<0)
			return -1;
	}
	if(orderkey[i]=='D')
	{
		if (strcmp(A,B)<0)
			return 1;
		else if (strcmp(A,B)>0)
			return -1;
	}		
	return 0;	
}
int cmpGPA(float A,float B, char orderkey[],int i)
{
	if(orderkey[i]=='A')
		if (A>B)
			return 1;
	if(orderkey[i]=='D')
		if (A<B)
			return 1;		
	return 0;	
}
void swap(student &A, student &B)
{
	student C = A;
	A = B;
	B = C;
}

