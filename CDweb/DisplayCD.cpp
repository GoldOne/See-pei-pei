/************************************************************************************* 
* Filename: DisplayCD.cpp * 
* Student's first name: Yi  * 
* Lab: AUTM-CSCI114/MCS9114-CL/01 Tue from 8:30 to 10:30 * 
* Modification Date: 03/06/2013 *
* Purpose of this file (or program): Dispaly CD record by searching id number.*
*************************************************************************************/
#include <iostream>

#include "cdweb.h"

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

void DisplayCD(int num)

{	
	int number;

	cout<<"Enter ID Number: ";

	cin>>number;

	while (number<0)//handling enter right format 
	{
		cout<<"Please enter a vaild number :";
		cin>>number;
	}
	
	bool found=false;//set for whether the cd found or not.

	for (int i=0;i<num;i++)
	{
				

		if (number==CD[i].idnumber)
		{
			found=true;
			cout<<"Found CD: "<<endl;//list the cd information
			cout<<"Identification Number: "<<CD[i].idnumber<<endl;
			cout<<"Album name: "<<CD[i].tittle<<endl;
			cout<<"Artist: "<<CD[i].artist<<endl;
			cout<<"Time: "<<CD[i].min<<"m "<<CD[i].sec<<"sec"<<endl;
			cout<<"Cost: "<<"$"<<CD[i].price<<endl;
			cout<<"Stock: "<<CD[i].stock<<endl;
			cout<<"Genre: "<<CD[i].cdtype<<endl;
		}
		
	}
	if (found!=true)
	cout<<"No CD found !"<<endl;
	PrintMenu();
}
	

