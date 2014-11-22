/************************************************************************************* 
* Filename: Summary.cpp * 
* Student's first name: Yi  * 
* Lab: AUTM-CSCI114/MCS9114-CL/01 Tue from 8:30 to 10:30 * 
* Modification Date: 03/06/2013 *
* Purpose of this file (or program): summary values stocks and number of records.*
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

extern struct CDweb CD[200];//extern struct

void Summary(int num)

{
	bool flag=false;

	cout<<"The number of tittles is: "<<num<<endl;

	cout<<"The following CD records with ZERO stock: "<<endl;//list the title for ZERO stock

	for (int i=0;i<num;i++)
	{
		if (CD[i].stock==0)//searching the zero stock items
		{
			cout<<CD[i].tittle<<endl;			
		
			flag=true;
		}
	}

	if (flag)
	cout<<"There is no ZERO stock CD records."<<endl;

	float summary;
	
	for (int i=0;i<num;i++)//calculating the values of cd records
	{
		summary+=CD[i].price*CD[i].stock;
	}
	
	cout<<"The total retial value of the stock are $"<<summary<<"."<<endl;

	PrintMenu();
	
}











