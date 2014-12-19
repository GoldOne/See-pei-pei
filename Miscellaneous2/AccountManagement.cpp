//Yi Jin,4370673
#include<fstream>
#include<cstdlib>
#include<cstring>
#include"AccountManagement.h"
using namespace std;
using namespace MYLIB;

void AccountManagement::loadData(const char*filename)
{
	ifstream fin;
	fin.open(filename);
	if(!fin.good())
   	{
        	cout<<"File not found or reading error!!!"<<endl;
        	return;
    	}
	
	while(!fin.eof()&&fin.good())
	{
		char temp[256];
		fin.getline(temp,256,'\n');
		if(strlen(temp)>1)//ignore the empty line
		{
			Account acc;
			stringstream stemp(temp);
			stemp>>acc;
			record.insert(acc);
		}
	}

	fin.close();
}

void AccountManagement::displayData()
{
	OrderedList<Account>::iterator it=record.begin();
	while(it!=record.end()) 
		cout<<*(it++)<<endl;
}

void AccountManagement::saveData(const char *filename)
{
	ofstream fout;
	fout.open(filename,ios::binary);
	OrderedList<Account>::iterator it=record.begin();
	while(it!=record.end()) 
	{
		Account ac;
		ac=*(it++);
		fout.write((char*)&ac,sizeof(Account));
	}
	fout.close();
}
	
