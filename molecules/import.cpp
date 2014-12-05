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

int import(mol &head,int &record)
{		
	record=0;	
	
	char name[256];
	
	cout<<"Please enter the name of the file you want to import: ";
	
	cin>>name;
	
	ifstream fin;
	
	fin.open(name);
	
	if(!fin.good())
	{
		cout << "File does not exist!" << endl;
		
		return 0;
	}
	char junk[100];
	
	fin>>junk;

	do
	{	
		fin>>junk;

		if(junk[0]!='#')
		{
			mol temp=new molecules;
			temp->position=atof(junk);
			fin>>temp->speed;
			fin>>temp->energy;
			temp->next=NULL;
		
			if(head==NULL)
				head=temp;
			else
			{	
				mol current=head;
				mol previous=NULL;
				while (current != NULL)
				{
					if((temp->position)<=(current->position))
						break;
					else
					{
						previous=current;
						current=current->next;
					}
				}
				if(previous==NULL)
				{
					if((temp->position)<=(current->position))
					{
						temp->next=head;
						head=temp;
					}
					else
						current->next=temp;
				}
				else
				{
					temp->next=current;
					previous->next=temp;
				}
			}
	
			record++;
		}
		else
			break;

	}while(!fin.eof());
	
	fin.close();
	
	cout<<"All data imported successfully!!!"<<endl;
	
	/*mol show=head;
	
	while(show!=NULL)
	{
		cout<<show->position<<endl;
		cout<<"====="<<endl;
		cout<<show->speed<<endl;
		cout<<"====="<<endl;
		cout<<show->energy<<endl;
		cout<<"====="<<endl;
		show=show->next;
		cout<<"+++++++"<<endl;
	}*/
	
	return record;
}	
