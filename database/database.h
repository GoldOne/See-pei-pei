/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
void PrintMenu();

char getChar(const char [], int);//handling unexpected input

const int MaxName=30;  //maximum character of student name in the datafile

const char Maxcourse=85; //maximum number of courses in the datafile

const int Maxsubject=30; //maximum number of subjects in the datafile

const int databasesize=1000; //maximun number of databse size

const int subjectname=8; //maxiun length of subject name

struct subject
{
	char year[5];    //the year of subject
		
	char session[2]; //the session of subject
	
	char code[subjectname+1];   //the subject code
	
	char Mark[4];    //the subject mark and status
	
	char credit[3]; //subject credit
		
};

struct student
{
	char name[MaxName+1];//student name
		
	char ID[8];// student ID
	
	char CourseName[Maxcourse+1]; //Course Name
	
	subject sul[Maxsubject+1];  //Subject information
	
	float GPA;//student GPA
	
	int cs;	//the number of courses;
}; 

int getData(student stl[],int &);//importdata	

int transint(char[]);//transfer to intenger

void gpa(student stl[],int[],int[],int,int);//calculate the GPA

void exportdata(student stl[],int rec);//export data

const int BUFMAX=30;

void getCString(char [], unsigned int MAX, bool allowNULL);

char getChar(const char [], int);

float getInt();//get float number only

int getint();//get intenger only

void searchmenu(int &,student stl[]);

char gpasearch(student stl[],int,int &,int[],int &);

char displaymenu(int &,char,student stl[]);

char namesearch(student stl[],int ,int &,int[],int &);

char subjectsearch(student stl[],int ,int &,int [],int &);

const char validcommanD[]={'y','n'};

void display(student stl[],int &page,int result[],int);

char del(student stl[],int ,int [],int &);

int getPositiveInt(int, int);

char edit(student stl[],int ,int []);

