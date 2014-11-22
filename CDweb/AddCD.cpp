/************************************************************************************* 
* Filename: AddCD.cpp * 
* Student's first name: Yi  * 
* Lab: AUTM-CSCI114/MCS9114-CL/01 Tue from 8:30 to 10:30 * 
* Modification Date: 03/06/2013 *
* Purpose of this file (or program): Add new cd record function.*
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

extern struct CDweb CD[200];//extern the struct

int AddCD(int num)
{
	bool complete=false;	//make a flag for completing the whole addtion for cd records

	cout<<"Please enter the Identification Number of CD: "<<endl;

	cin>>CD[num].idnumber;

	while (CD[num].idnumber<0)//handling enter right format 
	{
		cout<<"Please enter the correct ID number: "<<endl;
		cin>>CD[num].idnumber;
	}

	cin.ignore();

	cout<<"Please enter the name of the Album: "<<endl;

	cin.getline(CD[num].tittle,256);

	cin.ignore();

	cout<<"Please enter the name of Artist: "<<endl;

	cin.getline(CD[num].artist,256);

	cout<<"Please enter the minute of the CD: "<<endl;

	cin>>CD[num].min;

	while (CD[num].min<0 || CD[num].min>=60)
	{
		cout<<"Please enter the correct format of time: "<<endl;
		cin>>CD[num].min;
	}

	cout<<"Please enter the second of the CD: "<<endl;

	cin>>CD[num].sec;

	while (CD[num].sec<0 || CD[num].sec>=60)
	{
		cout<<"Please enter the correct format of time: "<<endl;
		cin>>CD[num].sec;
	}
	cout<<"Please enter the price of the CD: "<<endl;

	cin>>CD[num].price;

	while (CD[num].price<0)
	{
		cout<<"Please enter the correct price of CD: "<<endl;
		cin>>CD[num].price;
	}
	cout<<"Please enter the number of stock: "<<endl;

	cin>>CD[num].stock;

	while (CD[num].stock<0)
	{
		cout<<"Please enter the correct number of stock: "<<endl;
		cin>>CD[num].stock;
	}
	cout<<"Please enter the type of the CD by number: "<<endl;//Let user choose one for storing the cd type
	int type;
	cout<<"Pop ----------------1"<<endl;
	cout<<"Dance --------------2"<<endl;
	cout<<"R&B ----------------3"<<endl;
	cout<<"Soul ---------------4"<<endl;
	cout<<"Alternative --------5"<<endl;
	cout<<"Sound Track --------6"<<endl;
	cout<<"Spoken -------------7"<<endl;
	cout<<"Easy Listening -----8"<<endl;
	cout<<"Rock ---------------9"<<endl;
	cout<<"Trance -------------10"<<endl;
	cout<<"Dance/Electric -----11"<<endl;
	cout<<"Hip Hop/Rap --------12"<<endl;
	cin>>type;
	
	switch (type)
	{
		case 1:		strcpy(CD[num].cdtype,"Pop");//store the cd type by choose the number
				complete=true;
				cout<<"A new CD record inserted sucessfully."<<endl;
				break;
		case 2:		strcpy(CD[num].cdtype,"Dance");
				complete=true;
				cout<<"A new CD record inserted sucessfully."<<endl;
				break;
		case 3:		strcpy(CD[num].cdtype,"R&B");
				complete=true;
				cout<<"A new CD record inserted sucessfully."<<endl;
				break;
		case 4:		strcpy(CD[num].cdtype,"Soul");
				complete=true;
				cout<<"A new CD record inserted sucessfully."<<endl;
				break;
		case 5:		strcpy(CD[num].cdtype,"Alternative");
				complete=true;
				cout<<"A new CD record inserted sucessfully."<<endl;
				break;
		case 6:		strcpy(CD[num].cdtype,"Sound Track");
				complete=true;
				cout<<"A new CD record inserted sucessfully."<<endl;
				break;
		case 7:		strcpy(CD[num].cdtype,"Spoken");
				complete=true;
				cout<<"A new CD record inserted sucessfully."<<endl;
				break;
		case 8:		strcpy(CD[num].cdtype,"Easy Listening");
				complete=true;
				cout<<"A new CD record inserted sucessfully."<<endl;
				break;
		case 9:		strcpy(CD[num].cdtype,"Rock");
				complete=true;
				cout<<"A new CD record inserted sucessfully."<<endl;
				break;
		case 10:	strcpy(CD[num].cdtype,"Trance");
				complete=true;
				cout<<"A new CD record inserted sucessfully."<<endl;
				break;
		case 11:	strcpy(CD[num].cdtype,"Dance/Electric");
				complete=true;
				cout<<"A new CD record inserted sucessfully."<<endl;
				break;
		case 12:	strcpy(CD[num].cdtype,"Hip Hop/Rap");
				complete=true;
				cout<<"A new CD record inserted sucessfully."<<endl;
				break;
		default:
				cerr << "Wrong number\n";
				PrintMenu();
	}
	if (complete)//when add a new record the container of the struct should also be enlarged. 
	{
		num++;

		return num;
	} 
	PrintMenu();
}
