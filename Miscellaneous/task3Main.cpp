//Yi Jin,4370673
#include"EmployeeManagement.h"
using namespace std;

int main(int argc,char* argv[])
{
	EmployeeManagement man;
	man.loadEmployees(argv[1]);
	cout<<endl;
	man.manageEmployees();
	return 0;
}
