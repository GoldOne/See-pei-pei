//Yi Jin,4370673
#include<map>
#include"Account.h"

struct CompareCharArrays
{
    bool operator()(char *c1 ,char* c2) const
    {
        return strcmp(c1, c2)<0;
    }
};

class AccountMap
{
	private:
		std::multimap<char *,Account,CompareCharArrays> map;
	public:
		~AccountMap(){};
		void loadData(const char*);
		void displayData();
};
