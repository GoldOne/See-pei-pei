/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>

#include "database.h"

using namespace std;

const char validCommand[]={'E', 'D', 'N', 'P','R','S'};

char displaymenu(int &record,char c,student stl[])

{
	int page=0;//the page of displaying for the search result
	int rec=0;//the number of search result
	
	char command;
	int result[databasesize]={-1};//an array to record the order of search result which meet the requirements
		
	switch (c)//display the command
	{
		case 'G':
			command=gpasearch(stl,record,rec,result,page);
			break;
		case 'N':
			command=namesearch(stl,record,rec,result,page);
			break;
		case 'S':
			command=subjectsearch(stl,record,rec,result,page);
			break;
	}
	if (command=='R')
		return command;
	do
	{	
		cout<<"\n==========Display Menu=========="<<endl;
		cout<<endl;
		cout<<"There are "<<record<<" students' records in the system now."<<endl;
		
		cout << "\nCommands Available:\n";
		if(rec>0)
			cout << "  E - Edit the current record\n";
		if(rec>0)
			cout << "  D - Delete the current record\n";
		if(rec>0&& page!=(rec-1))
			cout << "  N - Go to the next record\n";
		if(rec>1&& page!=0)
			cout << "  P - Go to the previous record\n";
		cout << "  R - Return to main menu\n";
		cout << "  S - Return to search menu"<<endl;
		
		cout << "\nPlease enter a Command:" << endl;
		
		command=getChar(validCommand,sizeof(validCommand));	
	
		switch (command)//display the command
		{
			case 'E':
				command=edit(stl,page,result);
				break;
			case 'D':
				command=del(stl,page,result,record);
				break;
			case 'N':
				display(stl,++page,result,rec);
				break;
			case 'P':
				display(stl,--page,result,rec);
				break;
			case 'R':
				break;
			case 'S':
				break;
			default:
				{
					cerr << "Illegal Command"<<endl;
					cerr << "Please enter a correct command"<<endl;
				}
		}
	}while(command !='S' && command !='R');
	return command;
}
