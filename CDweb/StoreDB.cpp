/************************************************************************************* 
* Filename: StoreDB.cpp * 
* Student's first name: Yi  * 
* Lab: AUTM-CSCI114/MCS9114-CL/01 Tue from 8:30 to 10:30 * 
* Modification Date: 03/06/2013 *
* Purpose of this file (or program): store the change into database.*
*************************************************************************************/
#include <iostream>

#include <fstream>

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

void StoreDB(int num)

{	
	ofstream out;

	cout<<"Storing all data to CDData.txt ..."<<endl;

	out.open("CDData.txt");

	if (out.good())
	{
		for (int i=0;i<num-1;i++)//storing the information
		{
			out<<CD[i].idnumber<<endl;
			out<<CD[i].tittle<<endl;
			out<<CD[i].artist<<endl;
			out<<CD[i].min<<" "<<CD[i].sec<<endl;
			out<<CD[i].price<<endl;
			out<<CD[i].stock<<endl;
			out<<CD[i].cdtype<<endl;
		}
		
		out.close();
		cout<<"All data stored completed"<<endl;
	}
	
}



