//Yi Jin,4370673
#include<fstream>
#include"AccountMap.h"
using namespace std;

void AccountMap::loadData(const char* filename)
{
	ifstream fin;
	Account *acc;
	fin.open(filename,ios::binary|ios::ate);
	int count;
	count=fin.tellg()/sizeof(Account);//get the number of records
	fin.clear();
	fin.seekg(0,fin.beg);
	for(int i=0;i<count;i++)
	{
		acc=new Account();
		fin.read((char*)acc,sizeof(Account));
		char* temp=new char[20];
		strcpy(temp,acc->getName());
		map.insert(pair<char* const,Account>(temp,*acc));
	}

	fin.close();
}

void AccountMap::displayData()
{
	multimap<char *,Account,CompareCharArrays>::const_iterator it;
	for(it=map.begin();it!=map.end();it++)
		cout<<it->second<<endl;
}

