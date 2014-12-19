//Yi Jin,4370673
#include<iostream>
#include"Account.h"
#include"OrderedList.h"
using namespace MYLIB;

class AccountManagement
{
	private:
		OrderedList<Account> record;
	public:
		void loadData(const char*);
		void displayData();
		void saveData(const char*);
};
