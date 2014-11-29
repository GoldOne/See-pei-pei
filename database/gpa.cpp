/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>

#include "database.h"

using namespace std;

void gpa(student stl[],int m[],int c[],int cs,int index)

{
	float sum=0;
	
	int fcs=cs;//the number of courses
	
	for (int i=0;i<cs;i++)
	{
		if (stl[index].sul[i].Mark[0]=='e'||stl[index].sul[i].Mark[0]=='w')
			fcs--;
		else 
			sum+=c[i]*m[i];
					
	}
	
	stl[index].GPA=(sum/(6*fcs));
	
}
