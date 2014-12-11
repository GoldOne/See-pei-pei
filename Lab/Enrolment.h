#include<iostream>
#include<string>
class Enrolment
{
	private:
		int Number;
		std::string SubjectCode;
		std::string EnrolledDate;
	public:
		void setNumber(int num ) { Number=num; };
		int  getNumber() const { return Number; };
		void setCode(std::string code) { SubjectCode=code; };
		std::string getCode() const { return SubjectCode; };
		void setEDate(std::string date) { EnrolledDate=date; };
		std::string getEDate() const { return EnrolledDate; };
		Enrolment();
};
