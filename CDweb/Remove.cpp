/************************************************************************************* 
* Filename: Remove.cpp * 
* Student's first name: Yi  * 
* Lab: AUTM-CSCI114/MCS9114-CL/01 Tue from 8:30 to 10:30 * 
* Modification Date: 03/06/2013 *
* Purpose of this file (or program): remove the record from database.*
*************************************************************************************/
#include <iostream>

#include <cstring>

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

extern struct CDweb CD[200];//extern struct 

int Remove(int num)

{
	int del=0;

	char enter;

	int temp;	

	cout<<"Please enter the identification number of CD record you want to delete: "<<endl;

	cin>>temp;

	while (temp<0)

	{
		cout<<"Please enter a correct number: ";
		
		cin>>temp;
	}

	cout<<"Searching ...."<<endl;

	bool flag=false;//flag for searching result

	for (int i=0;i<num;i++)
	{
		if (temp==CD[i].idnumber)
		{
			del=i;
			cout<<"Found CD: "<<endl;//display the found cd record information
			cout<<"Identification Number: "<<CD[i].idnumber<<endl;
			cout<<"Album name: "<<CD[i].tittle<<endl;
			cout<<"Artist: "<<CD[i].artist<<endl;
			cout<<"Time: "<<CD[i].min<<"m "<<CD[i].sec<<"sec"<<endl;
			cout<<"Cost: "<<"$"<<CD[i].price<<endl;
			cout<<"Stock: "<<CD[i].stock<<endl;
			cout<<"Genre: "<<CD[i].cdtype<<endl;
			flag=true;
		}
	}
	if (!flag)
	{
		cout<<"No CD record found !"<<endl;
		PrintMenu();
	}
	else 
	{	 cout<<"Do you really want to delete this record? (Y/N)";//confirm to delete

		 cin>>enter;
		
		 while (enter!='Y' && enter!='y' && enter!='N' && enter!='n')
		 {
			cout<<"Pleae enter Y or N: ";

			cin>>enter;
		 }
	
		 if (enter=='Y' || enter=='y')//delete record.
		 {	
			for(int i=0;i<num;i++)
			{
				CD[del+i].idnumber=CD[del+i+1].idnumber;
				strcpy(CD[del+i].tittle,CD[del+i+1].tittle);
				strcpy(CD[del+i].artist,CD[del+i+1].artist);
				CD[del+i].min=CD[del+i+1].min;
				CD[del+i].sec=CD[del+i+1].sec;
				CD[del+i].price=CD[del+i+1].price;
				CD[del+i].stock=CD[del+i+1].stock;
				strcpy(CD[del+i].cdtype,CD[del+i+1].cdtype);
			}
			if (flag)
			{
		 		cout<<"Record is deleted successfully."<<endl;//decrease the container of array
				num--;
				return num;
			}
		 }
		
		 PrintMenu();		
	}
}
		












