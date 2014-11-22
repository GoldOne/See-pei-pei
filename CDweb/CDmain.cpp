/************************************************************************************* 
* Filename: CDmain.cpp * 
* Student's first name: Yi  * 
* Lab: AUTM-CSCI114/MCS9114-CL/01 Tue from 8:30 to 10:30 * 
* Modification Date: 03/06/2013 *
* Purpose of this file (or program): main function for CDweb.*
*************************************************************************************/
#include <iostream>

#include "cdweb.h"  // insert your header name here

using namespace std;

int count=0;

int main()
{
	char command;
	
	LoadDB();		// should report the number of records loaded

	PrintMenu();

	do
	{
		cout << "\nCDWeb Command:" << endl;
		cin >> command;
		switch (command)//display the command
		{
			case 'A':
				count=AddCD(count);
				break;
			case 'C':
				ModifyStockLevel(count);
				break;
			case 'D':
				DisplayCD(count);
				break;
			case 'L':
				list(count);
				break;
			case 'M':
				PrintMenu();
				break;
			case 'S':
				StoreDB(count);
				break;
			case 'V':
				Summary(count);
				break;
			case 'R':
				count=Remove(count);
				break;
			case 'Q':
				break;
			default:
				cerr << "Illegal CDWeb Command\n";
				PrintMenu();
		}
	} while (command != 'Q');
	StoreDB(count);  
	return 0;
}

void PrintMenu()
{
	cout << "CDWeb Inventory\nCommands Available:\n";
	cout << "  A - add new CD record\n";
	cout << "  C - change the stock level\n";
	cout << "  D - display a selected title\n";
	cout << "  L - list by genre or artist\n";
	cout << "  M - print this menu\n";
	cout << "  S - store the in-memory DB onto file\n";
	cout << "  V - summarise the value of the current inventory\n";
	cout << "  R - Remove a CD record\n";
	cout << "  Q - terminate the program" << endl;
}
