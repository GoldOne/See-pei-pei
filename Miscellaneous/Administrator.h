//Yi Jin,4370673
#include"Employee.h"
class Administrator : public Employee
{
	friend	std::ostream& operator<<(std::ostream&,Administrator&);	
	friend void operator>>(std::stringstream &,Administrator &);
	private:
		int roomNumber;
	public:
		Administrator(){type="A";};
		virtual~Administrator(){};//virtual destructor for delete obeject pointers dynamically
		void setRoomNumber(int room){roomNumber=room;};
		int getRoomNumber() const {return roomNumber;};
};
