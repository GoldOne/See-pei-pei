/************************************************************************************* 
* Filename: list.cpp * 
* Student's first name: Yi  * 
* Lab: AUTM-CSCI114/MCS9114-CL/01 Tue from 8:30 to 10:30 * 
* Modification Date: 03/06/2013 *
* Purpose of this file (or program): list cd information by artist or genre.*
*************************************************************************************/
#include <iostream>

#include "cdweb.h"

#include <cstring>

using namespace std;

struct CDweb

{
	int idnumber;

	char tittle[256];

	char artist[256];

	int min,sec,stock;

	float price;

	char cdtype[256];
};

extern struct CDweb CD[200]; //extern the struct

void list(int num)

{
	bool find=false;//flag for whether found or not
	char type[256];
	cout<<"Enter Search Criteria (Artist/ Genre): ";
	cin>>type;
	if (strcmp(type,"Artist")==0)
	{
		cin.ignore();
		
		char temp[256];
		cout<<"Artist Name: ";
		cin.getline(temp,256);
		for (int i=0;i<num;i++)
		{		
			if (strcmp(temp,CD[i].artist)==0)//searching codition			
			{	
				find=true;
				cout<<"1 Found CD:"<<endl;//list the result
				cout<<endl;
				cout<<"Identification Number: "<<CD[i].idnumber<<endl;
				cout<<"Album name: "<<CD[i].tittle<<endl;
				cout<<"Artist: "<<CD[i].artist<<endl;
				cout<<"Time: "<<CD[i].min<<"m "<<CD[i].sec<<"sec"<<endl;
				cout<<"Cost: "<<"$"<<CD[i].price<<endl;
				cout<<"Stock: "<<CD[i].stock<<endl;
				cout<<"Genre: "<<CD[i].cdtype<<endl;
			}
		
		}
		if(find!=true)
		cout<<"No CD found !"<<endl;
		PrintMenu();
	}
	else if (strcmp(type,"Genre")==0)//searching codition		
	{
		cin.ignore();
		
		char temp[256];
		cout<<"Genre Name: ";
		cin.getline(temp,256);
		for (int i=0;i<num;i++)
		{		
			if (strcmp(temp,CD[i].cdtype)==0)			
			{	
				find=true;
				cout<<"1 Found CD:"<<endl;//list the result
				cout<<endl;
				cout<<"Identification Number: "<<CD[i].idnumber<<endl;
				cout<<"Album name: "<<CD[i].tittle<<endl;
				cout<<"Artist: "<<CD[i].artist<<endl;
				cout<<"Time: "<<CD[i].min<<"m "<<CD[i].sec<<"sec"<<endl;
				cout<<"Cost: "<<"$"<<CD[i].price<<endl;
				cout<<"Stock: "<<CD[i].stock<<endl;
				cout<<"Genre: "<<CD[i].cdtype<<endl;
			}
		
		}
		if(find!=true)
		cout<<"No CD found !"<<endl;
		PrintMenu();

	}

	else {
			cout<<"Invalid Search Criteria"<<endl;//handle wrong input
			PrintMenu();
	     }
	

}





	
