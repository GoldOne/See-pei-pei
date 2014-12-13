//Yi Jin,4370673
#include"EmployeeManagement.h"
#include<fstream>
using namespace std;

EmployeeManagement::~EmployeeManagement()
{
	for(int i=0;i<length;i++)//delete all stuff in case of memory leak
	{
		if(employees[i]!=NULL)
			delete employees[i];
	}

	delete [] employees;
}

void EmployeeManagement::loadEmployees(const char *filename)
{
	ifstream fin;
	ofstream fout;
	fin.open(filename);
	fout.open("log.txt");//output the error message while reading the file
	if(!fin.good())
   	{
        	cout<<"Empoloyees file not found or reading error!!!"<<endl;
        	return;
    	}
	do
	{
		char Temp[256];
		fin.getline(Temp,256,'\n');
		length++;
	}while(!fin.eof());//count the line of file
	
	fin.clear();

	employees=new Employee*[length];

	fin.seekg(0,fin.beg);//read the file from the beginning again
	while(!fin.eof()&&fin.good())
	{
		int static i=0;
		int static line=1;
		char record[256];
		char temp[256];
		fin.getline(record,256,'\n');//read line by line
		stringstream stemp(record);
		stemp.getline(temp,256,',');//seperate and store for each part
		switch(temp[0])
		{
			case 'A':
				Administrator *a;
				a=new Administrator;	
				try
				{
					stemp>>(Administrator&)*a;//read the file to the correct derived class
				}catch (string err)
				{
					fout<<"In the text file line "<<line<<" has error: "<<err<<endl;
					line++;
					break;
				}
					employees[i]=a;//make a pinter point to the derived class
					cout<<(Administrator&)(*employees[i]);
					i++;
					line++;
					break;
			case 'T':
				Technician *t;
				t=new Technician;
				try
				{
					stemp>>(Technician&)*t;
				}catch (string err)
				{
					fout<<"In the text file line "<<line<<" has error: "<<err<<endl;
					line++;
					break;
				}
					employees[i]=t;
					cout<<(Technician&)*employees[i];
					i++;
					line++;
					break;
			case 'D':
				Driver *d;
				d=new Driver;
				try
				{
					stemp>>(Driver&)*d;
				}catch (string err)
				{
					fout<<"In the text file line "<<line<<" has error: "<<err<<endl;
					line++;
					break;
				}
					employees[i]=d;
					cout<<(Driver&)*employees[i];
					i++;
					line++;
					break;
			default:
				{
					fout<<"In the text file line "<<line<<" has error: '"<<temp[0]<<"' is a wrong employee type"<<endl;//output the error message for wrong type of employees
					line++;
				}
		}
	}
	
	fin.close();
	fout.close();
}

void EmployeeManagement::manageEmployees()
{
	char choice;

	do
	{
		cout<<"1. Display employees\n";
		cout<<"2. Update an employee\n";
		cout<<"0. Exit\n";
		cout<<"Your choice: ";
		cin>>choice;

		switch(choice)
		{
			case '1':
				displayEmployees();
				break;
			case '2':
				updateEmployee();
				break;
		}
	}while(choice!='0'); 

	saveEmployees();
	
	cout<<"Bye"<<endl;
}

void EmployeeManagement::displayEmployees()
{
	char choice;
	
	do
	{
		cout<<"1. Find an employee by a number\n";
		cout<<"2. Find all employees by a type\n";
		cout<<"0. Exit\n";
		cout<<"Your choice: ";
		cin>>choice;

		switch(choice)
		{
			case '1':
				int num;
				cout<<"Input an employee number: ";
				cin>>num;
				for(int i=0;i<length;i++)
				{
					if(employees[i]!=NULL)
						if(num==(employees[i])->getNumber())
						{
							if((employees[i])->getType()=="A")//output the employee's message with right type to show all correct message
								cout<<(Administrator&)*employees[i]<<endl;
							if((employees[i])->getType()=="D")
								cout<<(Driver&)*employees[i]<<endl;
							if((employees[i])->getType()=="T")
								cout<<(Technician&)*employees[i]<<endl;
						}
				}
				break;
			case '2':
				string type;
				cout<<"Input an employee type: ";
				cin>>type;
				for(int i=0;i<length;i++)
				{
					if(employees[i]!=NULL)
					{
						if((employees[i])->getType()==type&&type=="A")
							cout<<(Administrator&)*employees[i];
						if((employees[i])->getType()==type&&type=="D")
							cout<<(Driver&)*employees[i];
						if((employees[i])->getType()==type&&type=="T")
							cout<<(Technician&)*employees[i];
					}
				}
				cout<<endl;
				break;
		}
	}while(choice!='0'); 
}

void EmployeeManagement::saveEmployees()
{
	char filename[256];
	cout<<"Input a file name to save the data: ";
	cin>>filename;
	
	ofstream fout;
	fout.open(filename);
	
	for(int i=0;i<length;i++)
	{
		if(employees[i]!=NULL)//check the real data to be output
		{
			if((employees[i])->getType()=="A")
				fout<<(Administrator&)*employees[i];
			if((employees[i])->getType()=="D")
				fout<<(Driver&)*employees[i];
			if((employees[i])->getType()=="T")
				fout<<(Technician&)*employees[i];
		}
	}
	
	fout.close();
}

void EmployeeManagement::updateEmployee()
{
	int num;
	int mark=0;//know the goal object we are looking for
	string newaddress;
	cout<<"Employee number: ";
	cin>>num;
	for(int i=0;i<length;i++)
	{
		if(employees[i]!=NULL)
			if(num==(employees[i])->getNumber())
			{
				if((employees[i])->getType()=="A")
				{
					cout<<(Administrator&)*employees[i];
					mark=i;
				}
				if((employees[i])->getType()=="D")
				{
					cout<<(Driver&)*employees[i];
					mark=i;
				}
				if((employees[i])->getType()=="T")
				{
					cout<<(Technician&)*employees[i];
					mark=i;
				}
			}
	}
	
	cout<<"Input new address (Directly Enter for no change): ";
	cin.ignore();//ignore the enter from the previous input
	newaddress=cin.get();
	
	if(newaddress.length()>0)//if not empty just change it
		(employees[mark])->setAddress(newaddress);
		
	if((employees[mark])->getType()=="A")
	{
		cout<<"New office (0 for no change): ";
		cin>>num;
		if(num!=0)
			dynamic_cast<Administrator*>(employees[mark])->setRoomNumber(num);//change the tpye to derived class dynamically
		cout<<endl;
	}
	
	if((employees[mark])->getType()=="D")
		cout<<endl;
	
	if((employees[mark])->getType()=="T")
	{
		cout<<"New skill level(0 for no change): ";
		cin>>num;
		if(num!=0)
			dynamic_cast<Technician*>(employees[mark])->setLevel(num);
		cout<<endl;
	}
}
