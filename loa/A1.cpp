#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cctype>
#include"loa.h"
using namespace std;

int main(int argc,char *argv[])
{
	cout<<"Waiting..."<<endl;
	
	int count=0,cnt=0;
	do
	{
		string  temp,substr;
		char Temp[256];		
		cin.getline(Temp,256,'\n');
		temp=Temp;
		substr=temp.substr(0,6);
		if(temp==""||substr=="wtmp b"||substr=="reboot"||temp[11]=='s'||temp[42]=='s')
			continue;
		else
			count++;
	}while(!cin.eof()&&cin.good());
	
	string *record=new string[count];
	import(record,count);
	cnt=count;
	string* tmp=new string[cnt];
	
	for(int i=0;i<count;i++)
		tmp[i]=record[i];
	
	if(strcmp(argv[1],"options")==0)
	{
		cout<<"User Commands                                                   LOA"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"NAME"<<endl;
		cout<<"     -u [username] "<<endl;
		cout<<endl;
		cout<<"      Provide a report on the usage of the user specified by the username"<<endl;
		cout<<endl;
		cout<<"     -t <terminal_number1> [terminal_number2]"<<endl;
		cout<<endl;
		cout<<"      Provide a report on the usage of the terminal specified by terminal_number1, or, if a terminal_number2 is provided."<<endl;
		cout<<endl;
		cout<<"     -d <day>"<<endl;
		cout<<endl;
		cout<<"     Provide a report on the usage for a specified day of the week."<<endl;
		cout<<endl;
		cout<<"     -m "<<endl;
		cout<<endl;
		cout<<"     Provide a report on the usage by time."<<endl;
	}

	for(int i=1;i<argc;i++)
	{
		switch(argv[i][1])
		{
			case 'm':
				rotate(record,count);
				break;
			case 'u':
				if(argv[i][0]=='-'&&argv[i+1]!=NULL)
					if(strcmp(argv[i+1],"-t")==0||strcmp(argv[i+1],"-d")==0||strcmp(argv[i+1],"-m")==0)
					userrank(record,count);
				else
					username(record,count,argv[i+1]);
				if(argv[i][0]=='-'&&argv[i+1]==NULL)
					userrank(record,count);
				break;
			case 'd':
				if(argv[i+1]==NULL)
				{
					cout<<"Usage: "<<argv[0]<<" options"<<endl;
					break;
				}
					
				if(strcmp(argv[i+1],"Mon")==0||strcmp(argv[i+1],"Tue")==0||strcmp(argv[i+1],"Wed")==0||strcmp(argv[i+1],"Thu")==0||strcmp(argv[i+1],"Fri")==0||strcmp(argv[i+1],"Sat")==0||strcmp(argv[i+1],"Sun")==0)
					date(tmp,cnt,argv[i+1]);
				else
					cout<<"Usage: "<<argv[0]<<" options"<<endl;
				break;	
			case 't':
				if(argv[i+2]!=NULL&&isdigit(argv[i+2][0]))
					term(record,count,argv[i+1],argv[i+2]);
				else if(argv[i+1]!=NULL)
					terminal(record,count,argv[i+1]);
				else
					cout<<"Usage: "<<argv[0]<<" options"<<endl;
				break;
		}
	}

	delete [] record;
	delete [] tmp;

	return 0;
}

void import(string record[],int &count)
{
	count=0;
	ifstream fin;
	fin.open("last_data.txt");
	
	do
	{
		string temp,substr;
		char Temp[256];		
		fin.getline(Temp,256,'\n');
		temp=Temp;
		substr=temp.substr(0,6);
		if(temp==""||substr=="wtmp b"||substr=="reboot"||temp[11]=='s'||temp[42]=='s')
			continue;
		else
		{
			int static i=0;
			record[i]=temp;
			i++;
			count++;
		}
		
	}while(!fin.eof()&&fin.good());

	fin.close();
}

void username(string record[],int count,char *name)
{
	int length=strlen(name);
	bool find=false;

	int num=0;
	
	for(int i=0;i<count;i++)
	{
		string temp=record[i].substr(0,length);
		if(temp==name)
		{
			find=true;
			num++;
		}
	}
	
	if(find)
	{
		string *result=new string[num];

		for(int i=0;i<count;i++)
		{
			string temp=record[i].substr(0,length);
			if(temp==name)
			{
				int static j=0;
				result[j]=record[i];
				j++;
			}
		}	

		cout<<"The first recorded login by "<<name<<endl;
		cout<<result[num-1]<<endl;
		cout<<"The last recorded login by "<<name<<endl;
		cout<<result[0]<<endl;
		cout<<"The total number logins by "<<name<<": "<<num<<endl;
		caltime(result,num,name);
		delete [] result;
		cout<<">>>End of -u<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	}
	else
		cout<<"LOA: -u: "<<name<<": no such user found!!!"<<endl;
}

void caltime(string result[],int num,char *name)
{
	string *time=new string[num];
	for(int i=0;i<num;i++)
		time[i]=result[i].substr(49,7);
	int hour=0,min=0,day=0;
	int h=0,m=0,d=0;
	for(int i=0;i<num;i++)
	{
		if(isdigit(time[i][0]))
		{
			string temp=time[i].substr(0,1);
			d=atoi(temp.c_str());
			day+=d;
			temp=time[i].substr(2,2);
			h=atoi(temp.c_str());
			hour+=h;
			temp=time[i].substr(5,2);
			m=atoi(temp.c_str());
			min+=m;
		}
		else
		{
			string temp=time[i].substr(1,2);
			h=atoi(temp.c_str());
			hour+=h;
			temp=time[i].substr(4,2);
			m=atoi(temp.c_str());
			min+=m;
		}
	}

	delete [] time;

	hour+=min/60;
	min%=60;
	day+=hour/24;
	hour%=24;
	
	int length=strlen(name);

	if(length>2)
		cout<<"The total time "<<name<<" has spent logged in: "<<day<<" day(s) "<<hour<<" hour(s) "<<min<<" minute(s). "<<endl;
	else
		cout<<"The total time pts/"<<name<<" has spent logged in: "<<day<<" day(s) "<<hour<<" hour(s) "<<min<<" minute(s). "<<endl;
}

void terminal(string record[],int count,char *name)
{	
	bool find=false;
	int goal=atoi(name);
	int num=0,j=0;
	
	for(int i=0;i<count;i++)
	{
		string temp=record[i].substr(14,2);
		int data=atoi(temp.c_str());

		if(goal==data)
		{
			find=true;
			num++;
		}
	}
	if(find)
	{
		string *result=new string[num];
		
		for(int i=0;i<count;i++)
		{
			string temp=record[i].substr(14,2);
			int data=atoi(temp.c_str());

			if(goal==data)
			{
				result[j]=record[i];
				j++;
			}
		}	
		
		cout<<"The first recorded login by pts/"<<name<<endl;
		cout<<result[num-1]<<endl;
		cout<<"The last recorded login by pts/"<<name<<endl;
		cout<<result[0]<<endl;
		cout<<"The total number logins by pts/"<<name<<": "<<num<<endl;
		caltime(result,num,name);
		delete [] result;
		cout<<">>>End of -t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	}
	else
		cout<<"LOA: -t: pts/"<<name<<": no such user found!!!"<<endl;
}

void term(string record[],int count, char *from,char *to)
{
	int turns=atoi(to)-atoi(from)+1;
	int temp;

	do
	{
		terminal(record,count,from);
		temp=atoi(from)+1;
		sprintf(from,"%d",temp);
		turns--;
	}while(turns>0);
}

void date(string record[],int count,char *name)
{
	bool find=false;
	int num=0;
	
	for(int i=0;i<count;i++)
	{
		string temp=record[i].substr(23,3);
		if(temp==name)
		{
			find=true;
			num++;
		}
	}

	if(find)
	{
		int logins=0,days=1;
		float average=0;
		
		string *result=new string[num];

		for(int i=0;i<count;i++)
		{
			string temp=record[i].substr(23,3);
			if(temp==name)
			{
				int static j=0;
				result[j]=record[i];
				j++;
			}
		}	

		for(int i=0;i<num;i++)
		{
			string temp,Temp;
		
			if(i<num-1)
			{
				temp=result[i].substr(27,6);
				Temp=result[i+1].substr(27,6);
				if(temp.compare(Temp)==0)
					logins++;
				else
				{
					logins++;
					days++;
					if(i<num)
						cout<<"The number of logins of "<<temp<<" is "<<logins<<"."<<endl;
					else
						cout<<"The number of logins of "<<Temp<<" is 1."<<endl;
					logins=0;
				}
			}	
		}
		
		cout<<"The average number of logins per day of "<<name<<" is "<<num/days<<"."<<endl;

		cout<<">>>End of -d<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
		delete [] result;
	}
	else
		cout<<"LOA: -d: "<<name<<": no such user found!!!"<<endl;
}

void rotate(string record[],int count)
{
	for(int i=0;i<96;i++)
	{
		string start=duration[i].substr(0,5);
		string end=duration[i].substr(6,5);
		int login=0,logout=0;
		for(int j=0;j<count;j++)
		{
			string from=record[j].substr(34,5);
			string to=record[j].substr(42,5);
			if(from>start&&from<end)
				login++;
			if(to>start&&to<end)
				logout++;
		}

		cout<<"The number of logins within "<<duration[i]<<" is "<<login<<"."<<endl;
		cout<<"The number of logouts within "<<duration[i]<<" is "<<logout<<"."<<endl;
	}
	cout<<">>>End of -m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
}

void userrank(string record[],int count)
{
	int users,logins=0,j=0,temp;
	string Temp;

	sort(record,record+count);

	string previous=record[0].substr(0,8);
        users=1;
        for(int i=1;i<count;i++)
        {
                string current=record[i].substr(0,8);
                if(current!=previous)
                {
                        users++;
                        previous=current;
                }
        }
        
        int* numOflogins=new int[users];
        
        string* userlist=new string[users];
        
        for(int i=1;i<count;i++)
        {
        	string current=record[i].substr(0,8);
                if(current!=previous)
                {
                        userlist[j]=previous;
                        previous=current;
                        j++;
                }
        }
        
        j=0;
        
        for(int i=1;i<count;i++)
        {
        	string current=record[i].substr(0,8);
                if(current==previous)
                	logins++;
                else
                {
                	logins++;
                	previous=current;
                	numOflogins[j]=logins;
                	logins=0;
                	j++;
                }
        }
        
        for(int i=0;i<users;i++)
        {
        	for(int j=0;j<users-i-1;j++)
        	{
        		if(numOflogins[j+1]>numOflogins[j])
        		{
        			temp=numOflogins[j+1];
        			numOflogins[j+1]=numOflogins[j];
        			numOflogins[j]=temp;
        			Temp=userlist[j+1];
        			userlist[j+1]=userlist[j];
        			userlist[j]=Temp;
        		}
        	}
        }
        
        cout<<">>>>>>>>>>>>>>>>>>>>Top 10 User logins<<<<<<<<<<<<<<<<<<<<"<<endl;
        
      	for(int i=0;i<10;i++)
      	{
      		cout<<"No."<<i+1<<endl;
      		cout<<userlist[i]<<endl;
      		cout<<numOflogins[i]<<endl;
        }
        
        cout<<">>>End of -u<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
        
        delete [] numOflogins;
        delete [] userlist;
}	
