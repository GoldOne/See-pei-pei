#include"Student.h"
#include"Subject.h"
#include"Lab.h"
#include"Enrolment.h"
#include"Allocation.h"
#include<fstream>
#include<iostream>

class Admin
{
	private:
		int TotalStudents;
		Student* student;
		int TotalSubjects;
		Subject* subject;
		int TotalLabs;
		Lab* lab;
		int TotalEnrolls;
		Enrolment* enrol;
		AllocationList alist;
	public:
		void loadStudent(const char*);
		void loadSubject(const char*);
		void loadLab(const char*);
		void loadEnrolment(const char*);
		void displayStudent();
		void displaySubject();
		void displayLab();
		void displayEnrolment();
		int displaySubjectCode(int);
		std::string displayLabID(std::string,int,std::string &);
		void allocateLab();
		void showAllocate();
		Admin();
		~Admin();
};