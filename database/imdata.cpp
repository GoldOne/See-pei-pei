/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "database.h"
using namespace std;

void imdata(student stl[],int &rec)

{
	char name[100];
	
	cout<<"Please enter the name of the file you want to import: ";
	
	cin>>name;
	
	ifstream fin;
	
	fin.open(name, ios::binary|ios::ate);
	
	if(!fin.good())
	{
		cout << "File does not exist!" << endl;
		exit(1);
	}
	
	rec = fin.tellg()/sizeof(student);
	
	fin.seekg(0,fin.beg);
	
	fin.read((char *)stl,rec*sizeof(student));
	
	fin.close();
	
	cout<<"All data imported sucessfully!!!"<<endl;
}