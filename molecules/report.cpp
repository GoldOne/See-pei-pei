/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include "molecules.h"
using namespace std;

void report(mol &head,int total)
{
	if(total==0)
	{
		cout<<"==========Molecules Report=========="<<endl;
		cout<<endl;
		cout<<"   1. Total number of molecules 0"<<endl;
		cout<<"   2. Number of lonely molecules 0"<<endl;
		cout<<"   3. Average speed of the lonely molecules 0"<<endl;
		cout<<"   4. Average energy of the lonely molecules 0"<<endl;
	}
	else
	{
		mol report =new molecules[total];
		
		int lonely=0;
		
		float sums=0;
		
		float sume=0;
		
		mol display=head;
		
		for(int i=0;i<total;i++)
		{
			report[i].position=display->position;
			
			report[i].speed=display->speed;
			
			report[i].energy=display->energy;
			
			display=display->next;
		}
		
		for(int i=0;i<total;i++)
		{
			if(i==0)
			{
				if(report[i+1].position-report[i].position>100)
				{
					lonely++;
					sums+=report[i].speed;
					sume+=report[i].energy;
				}
			}	
			else if(i==total-1)
			{
				if(report[i].position-report[i-1].position>100)
				{
					lonely++;
					sums+=report[i].speed;
					sume+=report[i].energy;
				}
			}
			else
			{
				if(report[i].position-report[i-1].position>100 && report[i+1].position-report[i].position>100)
				{
					lonely++;
					sums+=report[i].speed;
					sume+=report[i].energy;
				}
			}
		}	
									
		cout<<"==========Molecules Report=========="<<endl;
		cout<<endl;
		cout<<"   1. Total number of molecules "<<total<<endl;
		cout<<"   2. Number of lonely molecules "<<lonely<<endl;
		if(lonely==0)
			cout<<"   3. Average speed of the lonely molecules 0"<<endl;
		else
			cout<<"   3. Average speed of the lonely molecules "<<sums/lonely<<endl;
		if(lonely==0)
			cout<<"   4. Average energy of the lonely molecules 0"<<endl;
		else
			cout<<"   4. Average energy of the lonely molecules "<<sume/lonely<<endl;	
				
		delete [] report;	
	}
}