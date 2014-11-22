/************************************************************************************* 
* Filename: LoadDB.cpp * 
* Student's first name: Yi  * 
* Lab: AUTM-CSCI114/MCS9114-CL/01 Tue from 8:30 to 10:30 * 
* Modification Date: 03/06/2013 *
* Purpose of this file (or program): Load the CD database.*
*************************************************************************************/
#include <iostream>

#include <fstream>

using namespace std;

extern int count;

struct CDweb

{
	int idnumber;

	char tittle[256];

	char artist[256];

	int min,sec,stock;

	float price;

	char cdtype[256];
};

CDweb CD[200];//declare the struct

void LoadDB()

{
	ifstream in("CDData.txt");

	if (in.good())//input data from files
	{
		int i=0;

		while(!in.eof())
		{		
		        char temp[256];
			in>>CD[i].idnumber;
			in.ignore();
			in.getline(CD[i].tittle,256);
			in.getline(CD[i].artist,256);
			in>>CD[i].min;
			in>>CD[i].sec;
			in>>CD[i].price;
			in>>CD[i].stock;
			in.ignore();
			in.getline(CD[i].cdtype,256);
			count++;
			i++;
		}
		
		in.close();

		cout<<count<<" records are loaded."<<endl;
	}
	else cout<<"Bad load of Database!!!"<<endl;
		

	/*for (int i=0; i<count;i++)
	{
		cout<<CD[i].idnumber<<endl;
		cout<<CD[i].tittle<<endl;
		cout<<CD[i].artist<<endl;
		cout<<CD[i].min<<" "<<CD[i].sec<<endl;
		cout<<CD[i].price<<endl;
		cout<<CD[i].stock<<endl;
		cout<<CD[i].cdtype<<endl;
	}*/ //just for testing
}
