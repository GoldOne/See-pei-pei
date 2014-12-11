#include"Admin.h"
#include<iostream>
#include<cstdlib>
#include<sstream>
#include<cstring>
using namespace std;

void Admin::loadStudent(const char* filename)
{
	cout<<"Load students' records......"<<endl;
	ifstream fin;
	fin.open(filename);
	if(!fin.good())
   	{
        	cout<<"Student file not found or reading error!!!"<<endl;
        	return;
    	}
	do
	{
		char Temp[256];
		fin.getline(Temp,256,'\n');
		TotalStudents++;
	}while(!fin.eof());
	
	fin.clear();
	student=new Student[TotalStudents];

	fin.seekg(0,fin.beg);
	while(!fin.eof()&&fin.good())
	{
		int static i=0;
		char record[256];
		char temp[256];
		fin.getline(record,256,'\n');
		stringstream stemp(record);
		stemp.getline(temp,256,',');
		int num=atoi(temp);
		student[i].setNumber(num);
		stemp.getline(temp,256,',');
		student[i].setName(temp);
		stemp.getline(temp,256,'\n');
		student[i].setEmail(temp);
		i++;
	}
	fin.close();
}

void Admin::loadSubject(const char* filename)
{
	cout<<"Load subjects' records......"<<endl;
	ifstream fin;
	fin.open(filename);
	if(!fin.good())
   	{
        	cout<<"Subject file not found or reading error!!!"<<endl;
        	return;
    	}
	do
	{
		char Temp[256];
		fin.getline(Temp,256,'\n');
		TotalSubjects++;
	}
	while(!fin.eof());
	
	fin.clear();
	subject=new Subject[TotalSubjects];

	fin.seekg(0,fin.beg);
	while(!fin.eof()&&fin.good())
	{
		int static i=0;
		char record[256];
		char temp[256];
		fin.getline(record,256,'\n');
		stringstream stemp(record);
		stemp.getline(temp,256,',');
		subject[i].setCode(temp);
		stemp.getline(temp,256,',');
		subject[i].setTitle(temp);
		stemp.getline(temp,256,'\n');
		int num=atoi(temp);
		subject[i].setCredit(num);
		i++;
	}
	fin.close();
}

void Admin::loadLab(const char* filename)
{
	cout<<"Load labs' records......"<<endl;
	ifstream fin;
	fin.open(filename);
	if(!fin.good())
   	{
        	cout<<"Lab file not found or reading error!!!"<<endl;
        	return;
    	}
	do
	{
		char Temp[256];
		fin.getline(Temp,256,'\n');
		TotalLabs++;
	}
	while(!fin.eof());
	
	lab=new Lab[TotalLabs];

	fin.clear();
	fin.seekg(0,fin.beg);
	while(!fin.eof()&&fin.good())
	{
		int static i=0;
		char record[256];
		char temp[256];
		fin.getline(record,256,'\n');
		stringstream stemp(record);
		stemp.getline(temp,256,',');
		lab[i].setID(temp);
		stemp.getline(temp,256,',');
		int num=atoi(temp);
		lab[i].setCap(num);
		stemp.getline(temp,256,',');
		lab[i].setCode(temp);
		stemp.getline(temp,256,',');
		num=atoi(temp);
		lab[i].setBN(num);
		stemp.getline(temp,256,',');
		num=atoi(temp);
		lab[i].setRN(num);
		stemp.getline(temp,256,'\n');
		lab[i].setTime(temp);
		i++;
	}
	fin.close();
}

void Admin::loadEnrolment(const char* filename)
{
	cout<<"Load enrolments' records......"<<endl;
	ifstream fin;
	fin.open(filename);
	if(!fin.good())
   	{
        	cout<<"Enrolment file not found or reading error!!!"<<endl;
        	return;
    	}
	do
	{
		char Temp[256];
		fin.getline(Temp,256,'\n');
		TotalEnrolls++;
	}
	while(!fin.eof());
	
	enrol=new Enrolment[TotalEnrolls];

	fin.clear();
	fin.seekg(0,fin.beg);
	while(!fin.eof()&&fin.good())
	{
		int static i=0;
		char record[256];
		char temp[256];
		fin.getline(record,256,'\n');
		stringstream stemp(record);
		stemp.getline(temp,256,',');
		enrol[i].setCode(temp);
		stemp.getline(temp,256,',');
		int num=atoi(temp);
		enrol[i].setNumber(num);
		stemp.getline(temp,256,'\n');
		enrol[i].setEDate(temp);
		i++;
	}
	fin.close();
}

Admin::Admin()
{
	TotalStudents=0;
	TotalSubjects=0;
	TotalLabs=0;
	TotalEnrolls=0;
}

Admin::~Admin()
{
	delete [] student;
	delete [] subject;
	delete [] lab;
	delete [] enrol;
}
		
void Admin::displayStudent()
{
	for(int i=0;i<TotalStudents;i++)
		cout<<student[i].getNumber()<<", "<<student[i].getName()<<", "<<student[i].getEmail()<<endl;
}

void Admin::displaySubject()
{
	for(int i=0;i<TotalSubjects;i++)
		cout<<subject[i].getCode()<<", "<<subject[i].getTitle()<<", "<<subject[i].getCredit()<<endl;
}

void Admin::displayLab()
{
	for(int i=0;i<TotalLabs;i++)
		cout<<lab[i].getID()<<", "<<lab[i].getCap()<<", "<<lab[i].getCode()<<", "<<lab[i].getBN()<<", "<<lab[i].getRN()<<", "<<lab[i].getTime()<<endl;
}	

void Admin::displayEnrolment()
{
	for(int i=0;i<TotalEnrolls;i++)
		cout<<enrol[i].getCode()<<", "<<enrol[i].getNumber()<<", "<<enrol[i].getEDate()<<endl;
}

int Admin::displaySubjectCode(int num)
{
	if(num==0)
		return 0;
	int number=0;
	bool find=false;
	for(int i=0;i<TotalEnrolls;i++)
	{
		if(num==enrol[i].getNumber())
		{
			find=true;
			number++;
		}
	}

	string* result=new string[number];
	int j=0;
	
	for(int i=0;i<TotalEnrolls;i++)
	{
		if(num==enrol[i].getNumber())
		{
			find=true;
			result[j]=enrol[i].getCode();
			j++;
		}
	}
	
	if(find)
	{
		cout<<"Enrolled in the subjects: ";
		for(int i=0;i<number;i++)
			cout<<result[i]<<" ";
		cout<<endl;
		delete [] result;
		return num;
	}
	else
	{
		cout<<"Student number "<<num<<" not exists."<<endl;
		return 0;	
	}
}

string Admin::displayLabID(string code,int num,string &id)
{
	const char *temp=code.c_str();
	
	if(strcmp(temp,"0")==0)
		return "0";
	int number=0;
	bool find=false;
	bool found=false;
	for(int i=0;i<TotalEnrolls;i++)
		if(num==enrol[i].getNumber())
			number++;

	string* result=new string[number];
	int j=0;
	
	for(int i=0;i<TotalEnrolls;i++)
	{
		if(num==enrol[i].getNumber())
		{
			result[j]=enrol[i].getCode();
			j++;
		}
	}

	for(int i=0;i<number;i++)
		if(code==result[i])
			found=true;	
	delete [] result;	

	if(!found)
	{
		cout<<"Incorrect subject code."<<endl;
		return "0";
	}
	else
	{
		number=0;
		int  j=0;

		for(int i=0;i<TotalLabs;i++)
		{
			if(code==lab[i].getCode())
			{
				find=true;
				found=true;
				number++;
			}
		}
	
		string* Result=new string[number];
	
		for(int i=0;i<TotalLabs;i++)
		{
			if(code==lab[i].getCode())
			{
				find=true;
				Result[j]=lab[i].getID();
				j++;
			}
		}
	
		if(find)
		{
			bool find=false;
			cout<<"Available labs/tutorials: ";
			for(int i=0;i<number;i++)
				cout<<Result[i]<<" ";
			cout<<endl;
			
			cout<<"Lab ID: ";
			cin>>id;
			for(int i=0;i<number;i++)
			{
				if(id==Result[i])
					find=true;
			}
			
			if(!find)
				cout<<"Student cannot be allocated in this lab/tutorial."<<endl;

			Allocation node(num,id,code);

			if(alist.find(node))
			{
				cout<<"The student has already been allocated in a lab/tutorial for the subject."<<endl;
				return "0";
			}	
			else
				alist.push_back(node);

			delete [] Result;

			return code;
		}
		else
		{
			cout<<"Available labs/tutorials: No lab / tutorial available."<<endl;
			return "0";
		}
	}

	return code;
}

void Admin::allocateLab()
{
	int input,Number;
	string Input,Code,id;

	do
	{	
		do
		{
			cout<<"Student number (0-Exit): ";
			cin>>input;
			Number=displaySubjectCode(input);
			if(Number!=0)
				break;
		}while(input!=0);

		if(input==0)
			break;

		do
		{
			cout<<"Subject code (0-Stop): ";
			cin>>Input;
			Code=displayLabID(Input,Number,id);
			const char *temp=Code.c_str();
			if(strcmp(temp,"0")!=0)
				break;
		}while(Input!="0");

		if(Input=="0")
			break;		

	}while(1);
}

void Admin::showAllocate()
{
	for(int i=0;i<TotalLabs;i++)
	{
		cout<<lab[i].getCode()<<"--";
		for(int j=0;j<TotalSubjects;j++)
		{
			if(lab[i].getCode()==subject[j].getCode())
				cout<<subject[j].getTitle()<<endl;
		}
		cout<<"Lab / Tutorial: "<<lab[i].getID()<<endl;

		for(int k=0;k<TotalStudents;k++)
		{
			Allocation node(student[k].getNumber(),lab[i].getID(),lab[i].getCode());
			if(alist.find(node))
				cout<<student[k].getNumber()<<", "<<student[k].getName()<<", "<<student[k].getEmail()<<endl;
		}

		cout<<endl;
	}
}