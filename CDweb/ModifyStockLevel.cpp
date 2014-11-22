/************************************************************************************* 
* Filename: ModifyStockLevel.cpp * 
* Student's first name: Yi  * 
* Lab: AUTM-CSCI114/MCS9114-CL/01 Tue from 8:30 to 10:30 * 
* Modification Date: 03/06/2013 *
* Purpose of this file (or program): change the stock level function.*
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

extern struct CDweb CD[200];//extern the struct

void ModifyStockLevel(int num)

{
	int number;

	cout<<"Enter ID Number: ";

	cin>>number;

	while (number<0)//handle the exception
	{
		cout<<"Please enter a vaild number :";
		cin>>number;
	}
	
	bool found=false;//check whether cd found or not

	for (int i=0;i<num;i++)
	{
		if (number==CD[i].idnumber)
		{
			int temp;
			found=true;
			cout<<"The currecnt stock level of this CD record is "<<CD[i].stock<<endl;//display the current stock
			cout<<"Please change the stock level by enter an integer number ";//prompt user to enter a number for change
			cin>>temp;
			if (temp+CD[i].stock<0)
			{
				cout<<"Warning far beyond the stock level and it is set to ZERO."<<endl;//waring for negetive result
				CD[i].stock=0;
			}
			else CD[i].stock+=temp;
		}
		
	}
	if (found!=true)
	cout<<"No CD found !"<<endl;
	PrintMenu();
}
