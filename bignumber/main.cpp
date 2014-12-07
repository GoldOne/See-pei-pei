/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include "llong.h"
using namespace std;

const char validcommand[]={'A', 'S', 'M', 'D','m','Q','C'};

char getChar(const char valid[], int size)
{
	char c=' ';
	cin >> c;
	return c;
}

int main()
{	
        char command;
        
        cout<<"Caution: the range of integer -2147483648 to 2147483647 (10 digits number)"<<endl;
        
	cout<<"Please enter the first number (A)"<<endl;
	
	int num;
	
	cin>> num;
	
	LLONG a(num);
	
	cout<<"Please enter the Second number (B)"<<endl;
	
	cin>>num;
	
	LLONG b(num);
	
	//a.output(cout<<"The first number is ");
	
	//b.output(cout<<"The second number is ");
	
	//cout<<a.compare(b)<<endl;
	
	do
	{
		cout<<"\n==========Calculator C++ version 1.0=========="<<endl;
		cout<<endl;
		cout<<"What do you want to do ?"<<endl;
		cout<< "\nCommands Available:\n";
		cout<< "  A -> A+B\n";
		cout<< "  S -> A-B\n";
		cout<< "  M -> A*B\n";
		cout<< "  D -> A/B\n";
		cout<<endl;
		cout<< "XXXThe above calculation will change the value of A !!!XXX"<<endl;
		cout<<endl;
		cout<< "  m -> A%B\n";
		cout<< "  C -> Compare A and B\n";
		cout<< "  Q -> Quit "<<endl;
	        cout<<endl;
	        cout<<"You are not allowed to change the previous numbers !!!"<<endl;
		cout<< "\nPlease enter a Command:" << endl;
		
		command=getChar(validcommand,sizeof(validcommand));	
	
		switch (command)//display the command
		{
			case 'A':
				a.add(b);
				a.output(cout<<"Result: ");
				break;
			case 'S':
				a.subtract(b);
				a.output(cout<<"Result: ");
				break;
			case 'M':
				a.multiply(b);
				a.output(cout<<"Result: ");
				break;
			case 'D':
				a.divide(b);
				a.output(cout<<"Result: ");
				break;
		        case 'm':
				a.mod(b);
				break;
			case 'C':
				if(a.compare(b)==0)
			                cout<<"They are equal !!!"<<endl;
			        if(a.compare(b)==1)
			                cout<<"A is larger than B !!!"<<endl; 
			        if(a.compare(b)==-1)
			                cout<<"A is smaller than B !!!"<<endl;
				break;
			case 'Q':
				break;
			default:
				{
					cerr << "Illegal Command"<<endl;
					cerr << "Please enter a correct command"<<endl;
				}
		}
	}while(command !='Q');
	
	cout<<"See you later !!!"<<endl;
	
	return 0;
}
