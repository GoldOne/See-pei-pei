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
