//Yi Jin,4370673
#include"Employee.h"
class Driver : public Employee
{
	friend	std::ostream& operator<<(std::ostream&,Driver&);	
	friend  void operator>>(std::stringstream &,Driver&);
	private:
		int LicenseNumber;
	public:
		Driver(){type="D";};
		virtual~Driver(){};//virtual destructor for delete obeject pointers dynamically
		void setLicense(int license){LicenseNumber=license;};
		int getLicense() const {return LicenseNumber;};
};
