/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>

#include "database.h"

using namespace std;

const char validCommand[]={'G', 'N', 'R', 'S'};

void searchmenu(int &record,student stl[])
{
	char command;
	do
	{
	
		cout<<"\n==========Search Menu=========="<<endl;
		cout<<endl;
		cout<<"There are "<<record<<" students' records in the system now."<<endl;
		cout << "\nCommands Available:\n";
		cout << " G - Search by GPA\n";
		cout << " N - Search by Name\n";
		cout << " R - Return to main menu\n";
		cout << " S - Search by Subject"<<endl;
		cout << "\nPlease enter a Command:" << endl;
		command=getChar(validCommand,sizeof(validCommand));
	
		switch (command)//display the command
		{
			case 'G':
				command=displaymenu(record,command,stl);
				break;
			case 'N':
				command=displaymenu(record,command,stl);
				break;
			case 'R':
				break;
			case 'S':
				command=displaymenu(record,command,stl);
				break;
			default:
				cerr << "Illegal Command"<<endl;
				cerr << "Please enter a correct command"<<endl;
		}
	}while(command !='R');	
}
