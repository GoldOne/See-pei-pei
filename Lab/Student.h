#include<iostream>
#include<string>
class Student
{
	private:
		std::string Name;
		int Number;
		std::string Email;
	public:
		void setNumber(int num ) { Number=num; };
		int  getNumber() const { return Number; };
		void setName(std::string name) { Name=name; };
		std::string getName() const { return Name; };
		void setEmail(std::string email) { Email=email; };
		std::string getEmail() const { return Email; };
		Student();
};
