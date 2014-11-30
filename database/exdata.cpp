/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include <fstream>
#include "database.h"
using namespace std;

void exdata(student stl[],int rec)

{
	ofstream fout;	
	
	char name[100];
	
	cout<<"Please enter the file name you want to output: ";
	
	cin>> name;
	
	fout.open(name,ios::binary);	

	fout.write((char *)stl, rec*sizeof(student));

	fout.close();
	
	cout<<"Export file completed!!!"<<endl;
}