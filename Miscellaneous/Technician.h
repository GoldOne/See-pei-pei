//Yi Jin,4370673
#include"Employee.h"
class Technician : public Employee
{
	friend	std::ostream& operator<<(std::ostream&,Technician&);	
	friend  void operator>>(std::stringstream &,Technician&);
	private:
		std::string skill;
		int skillLevel;
	public:
		void setSkill(std::string s){skill=s;};
		std::string getSkill() const {return skill;};
		void setLevel(int level){skillLevel=level;};
		int getLevel() const {return skillLevel;};
		Technician(){type="T";};
		virtual~Technician(){};//virtual destructor for delete obeject pointers dynamically
};
