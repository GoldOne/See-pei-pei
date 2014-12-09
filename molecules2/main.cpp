/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include "molecules.h"

using namespace std;

const char validcommand[]={'N', 'I', 'Q', 'R'};

char getChar(const char valid[], int size)
{
	char c=' ';
	cin >> c;
	return c;
}

int main()
{
	mol root=NULL;//initialization

	cout<<"==========Welcome to Lonely Molecules C++ version 1.1 !!!=========="<<endl;
	
	int total=0;
	
	char command;
	
	int record=0;
	
	do
	{
		cout<<"\n==========Main Menu=========="<<endl;
		
		cout << "\nCommands Available:\n";
		cout<<endl;
		cout << "  I - Import data from text file\n";
		cout << "  N - Display the number of molecules imported\n";
		cout << "  R - Generate a Report\n";
		cout << "  Q - Quit\n";
		cout << "\nPlease enter a Command:" << endl;
		
		command=getChar(validcommand,sizeof(validcommand));	
	
		switch (command)//display the command
		{
			case 'I':
				total=import(root,record);
				break;
			case 'N':
				if(record>1)
					cout<<"There are "<<total<<" records imported at this time."<<endl;
				else
					cout<<"There is "<<total<<" record imported at this time."<<endl;
				break;
			case 'R':
				report(root,record);
				break;
			case 'Q':
				break;
			default:
				{
					cerr<< "Illegal Command"<<endl;
					cerr<< "Please enter a correct command"<<endl;
				}
		}
		
	}while(command !='Q');
	
	cout<<"Thank you for using this system. Bye Bye!!!"<<endl;
	
	return 0;
}