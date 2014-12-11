#include<iostream>
#include<string>
class Subject
{
	private:
		std::string Title;
		std::string SubjectCode;
		int Credits;
	public:
		void setCode(std::string code) { SubjectCode=code; };
		std::string getCode() const { return SubjectCode; };
		void setTitle(std::string title) { Title=title; };
		std::string getTitle() const { return Title; };
		void setCredit(int credit) { Credits=credit; };
		int getCredit() const { return Credits; };
		Subject();
};
