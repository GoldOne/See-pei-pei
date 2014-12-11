#include"Admin.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int main(int argc,char* argv[])
{
	Admin admin;
	admin.loadStudent(argv[1]);
	admin.displayStudent();
	admin.loadSubject(argv[2]);
	admin.displaySubject();
	admin.loadLab(argv[3]);
	admin.displayLab();
	admin.loadEnrolment(argv[4]);
	admin.displayEnrolment();
	cout<<endl;
	admin.allocateLab();
	cout<<endl;	
	admin.showAllocate();

	return 0;
}
