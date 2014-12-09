/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "molecules.h"
using namespace std;

int import(mol &root,int &record)
{		
	int imported=0;
	
	char name[256];
	
	cout<<"Please enter the name of the file you want to import: ";
	
	cin>>name;
	
	ifstream fin;
	
	fin.open(name);
	
	if(!fin.good())
	{
		cout<<"File does not exist!"<<endl;
		
		return 0;
	}
	char junk[100];
	
	fin>>junk;

	do
	{	
		fin>>junk;

		if(junk[0]!='#')
		{
			buffer temp;
			temp.position=atof(junk);
			fin>>temp.speed;
			fin>>temp.energy;
			fin>>temp.finger;
			if(find(root,temp)==false)
				record+=insert(root,temp);
			imported++;
		}
		else
			break;

	}while(!fin.eof());
	
	fin.close();
	
	cout<<"All data imported successfully!!!"<<endl;
	
	//inorder(root);
	
	//cout<<record<<endl;
	
	return imported;
}	
