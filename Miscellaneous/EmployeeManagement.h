//Yi Jin,4370673
#include"Driver.h"
#include"Employee.h"
#include"Technician.h"
#include"Administrator.h"

class EmployeeManagement
{
	private:
		Employee** employees;//define a dynamic pointer array
		int length;
	public:
		EmployeeManagement(){length=0;};
		~EmployeeManagement();
		void loadEmployees(const char*);
		void manageEmployees();
		void displayEmployees();
		void updateEmployee();
		void saveEmployees();
};
