/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>

#include "database.h"

using namespace std;

void display(student stl[],int &page,int result[],int record)

{
	cout<<"Here is the "<<page+1<<" / "<<record<<" for searching result."<<endl;
	cout<<"************Record************"<<endl;
	cout<<"Name: "<<stl[result[page]].name<<endl;
	cout<<"ID: "<<stl[result[page]].ID<<endl;
	cout<<"Course Name: "<<stl[result[page]].CourseName<<endl;
	cout<<"GPA: "<<stl[result[page]].GPA<<endl;
	for (int j=0; j<stl[result[page]].cs;j++)
	{
		cout<<"Year: "<<stl[result[page]].sul[j].year<<endl;
		cout<<"Session: "<<stl[result[page]].sul[j].session<<endl;
		cout<<"Subject Name: "<<stl[result[page]].sul[j].code<<endl;
		cout<<"Subject Credit: "<<stl[result[page]].sul[j].credit<<endl;
		cout<<"Subject Mark or Status: "<<stl[result[page]].sul[j].Mark<<endl;
	}
	cout<<"************Record************"<<endl;
}	
	
