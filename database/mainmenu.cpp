/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>

#include "database.h"

using namespace std;

const char validcommand[]={'E', 'I', 'Q', 'S'};

char getChar(const char valid[], int size)
{
	char c=' ';
	cin >> c;
	return c;
}

void PrintMenu()
{
	student stl[databasesize];
	
	static int records=0;
	
	char command;
	do
	{
		cout<<"\n==========Main Menu=========="<<endl;
		cout<<endl;
		cout<<"There are "<<records<<" students' records in the system now."<<endl;
		cout << "\nCommands Available:\n";
		cout << "  E - Export data from text file\n";
		cout << "  I - Import data from text file\n";
		cout << "  Q - Quit SOLS\n";
		cout << "  S - Display the search menu"<<endl;
	
		cout << "\nPlease enter a Command:" << endl;
		
		command=getChar(validcommand,sizeof(validcommand));	
	
		switch (command)//display the command
		{
			case 'E':
				exportdata(stl,records);
				break;
			case 'I':
				records+=getData(stl,records);
				break;
			case 'Q':
				break;
			case 'S':
				searchmenu(records,stl);
				break;
			default:
				{
					cerr << "Illegal Command"<<endl;
					cerr << "Please enter a correct command"<<endl;
				}
		}
	}while(command !='Q');
}
