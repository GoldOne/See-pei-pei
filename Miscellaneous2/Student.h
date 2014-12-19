//Yi Jin,4370673
#include<iostream>

class Student
{
	friend std::ostream& operator<<(std::ostream&,const Student &);
	friend std::istream& operator>>(std::istream&,Student &);

	private:
		int number;
		std::string name;
		std::string email;
	public:
		Student(){};
		Student(int num,std::string Name,std::string Email){number=num;name=Name;email=Email;};
		Student operator=(const Student &s){number=s.number;name=s.name;email=s.email;return *this;};
		bool operator<=(const Student &s){return email<=s.email;};
};
