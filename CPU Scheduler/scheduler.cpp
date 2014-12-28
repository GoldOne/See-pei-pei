/* 
 * File:   scheduler.cpp
 * Author: Yi Jin
 * ID: yj742
 * Created on 9 August 2014, 11:55 AM
 */
#include<cmath>
#include<deque>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<iostream>

using namespace std;

struct process
{
	int number;//process number
	int atime;//arrival time
	int btime;//burst time
	int wtime;//waiting time
	int rtime;//running time
	int ftime;//finish time
	bool vip1;//pre-empted for queue1
	bool vip2;//pre-empted for queue2
	int priority;//priority for ready queue
};

int check_arrival(process proc[],int size)
{
	for(int i=0;i<size;i++)
	{
		if(proc[i].atime==0)
			return i;
	}
	return -1;
}

bool complete(process proc[],int size)
{
	for(int i=0;i<size;i++)
	{
		if(proc[i].btime!=0)
			return false;
	}
	return true;
}

/*
 CSCI330 Spring 2014 Ass1 
 */
int main(int argc, char* argv[])
{
	int size,slice,etime=0;//etime=elapsed time
	
	if(argc!=2)
	{
		cout<<"Usage: scheduler <inputfile>"<<endl;
		exit(0);
	}
	
	ifstream fin;
	
	fin.open(argv[1]);
	
	if(!fin.good())
	{
		cout<<"File no exist or Reading error!!!"<<endl;
		exit(0);
	}
	
	fin>>size;
	
	if(size<1)
	{
		cout<<"Incorrect number of processes!!!"<<endl;
		exit(0);
	}
	
	fin>>slice;
	
	if(slice<1)
	{
		cout<<"Incorrect time slice for RR!!!"<<endl;
		exit(0);
	}
	
	process* proc=new process[size];
	
	for(int i=0;i<size;i++)
	{
		fin>>proc[i].atime;
		
		if(i>1&&proc[i].atime<proc[i-1].atime)
		{
			cout<<"Incorrect order of arrival time in process list!!!"<<endl;
			delete [] proc;
			exit(0);
		}
		
		fin>>proc[i].btime;
		
		if(proc[i].btime*1.0/slice<0.1)
		{
			cout<<"Not appropriate multiples of the time slice"<<endl;
			delete [] proc;
			exit(0);
		}
		
		proc[i].number=i;
	}
	
	fin.close();	
	
	process* rrproc=new process[size];//copy to and prepare to RR 
	for(int i=0;i<size;i++)
	{
		rrproc[i].atime=proc[i].atime;
		rrproc[i].btime=proc[i].btime;
		rrproc[i].number=proc[i].number;
		rrproc[i].wtime=0;
		rrproc[i].rtime=0;
		rrproc[i].ftime=0;
	}
	
	int temp=slice;
	int tgr=0;//time growth rate
	
	do
	{
		temp/=10;
		if(temp!=0)
			tgr++;
	}while(temp>9);//calculate the time growth rate
	
	deque<process> rrqueue;//RR readyqueue
	
	int position;
	
	process wproc;//working process
	
	wproc.number=-1;
	wproc.atime=0;
	wproc.btime=0;
	wproc.wtime=0;
	wproc.rtime=0;
	wproc.ftime=0;//Initialization
	
	position=check_arrival(rrproc,size);
	
	if(position!=-1)
		rrqueue.push_back(rrproc[position]);//put the arrival process into readyqueue
	
	wproc=rrqueue.front();//copy to the working process 
	rrqueue.pop_front();
	
	vector<int> gant;
	
	do
	{
		gant.push_back(wproc.number);
		
		etime+=pow(10.0,tgr*1.0);//add running time
		
		for(int i=0;i<size;i++)
			rrproc[i].atime-=pow(10.0,tgr*1.0);//deduct time for those processes which have not arrive
		if(!rrqueue.empty())
		{
			for(int i=0;i<rrqueue.size();i++)
				rrqueue[i].wtime+=pow(10.0,tgr*1.0);//add waiting time for those process in the ready queue
		}
		
		position=check_arrival(rrproc,size);//check arrival process

		if(position!=-1)
			rrqueue.push_back(rrproc[position]);//put arrival process into ready queue
		
		wproc.btime-=pow(10.0,tgr*1.0);//deduct brust time for current process
		wproc.rtime+=pow(10.0,tgr*1.0);//add running time fo current process
		
		if(wproc.btime==0)
		{
			for(int i=0;i<size;i++)
			{
				if(wproc.number==rrproc[i].number)//record wait time and clean the brust time
				{
					rrproc[i].wtime=wproc.wtime;
					rrproc[i].ftime=etime;
					rrproc[i].btime=0;
				}
			}
			wproc=rrqueue.front();//copy to the working process 
			rrqueue.pop_front();
		}
		else if(wproc.rtime%slice==0)//arrive at time slice to switch the process
		{
			rrqueue.push_back(wproc);
			wproc=rrqueue.front();//copy to the working process 
			rrqueue.pop_front();
		}	
	}while(!complete(rrproc,size));	
	
	float avgwtime=0;//average waiting time
	float avgttime=0;//average turnaround time
	
	for(int i=0;i<size;i++)
		avgwtime+=rrproc[i].wtime;
	
	cout<<"          Round Robin "<<"("<<slice<<"ms)"<<endl;
	cout<<endl<<"Gantt Chart: ";
	vector<int>::iterator i=gant.begin();
	while(i!=gant.end())
	{
		cout<<*i;
		i++;
	}
	cout<<endl;
	cout<<endl<<"          BT          WT          TT"<<endl;
	for(int i=0;i<size;i++)
		cout<<"P"<<rrproc[i].number<<": "<<setw(8)<<proc[i].btime<<setw(12)<<rrproc[i].wtime<<setw(12)<<rrproc[i].ftime-proc[i].atime<<endl;
	for(int i=0;i<size;i++)
		avgttime+=rrproc[i].ftime-proc[i].atime;
	
	cout<<"Average:"<<setw(16)<<avgwtime/size<<setw(12)<<avgttime/size<<endl;
	
	gant.clear();
	rrqueue.clear();
	delete [] rrproc;
	/*
	 End of RR scheduler 
	 */
	deque<process> mq[3];
	
	process* mfq=new process[size];
	
	for(int i=0;i<size;i++)//copy to multi feedback queue
	{
		mfq[i].atime=proc[i].atime;
		mfq[i].btime=proc[i].btime;
		mfq[i].number=proc[i].number;
		mfq[i].ftime=0;
		mfq[i].rtime=0;
		mfq[i].wtime=0;
		mfq[i].vip1=false;
		mfq[i].vip2=false;
		mfq[i].priority=0;
	}
	
	wproc.number=-1;
	wproc.atime=0;
	wproc.btime=0;
	wproc.wtime=0;
	wproc.rtime=0;
	wproc.ftime=0;//Initialization
	etime=0;
	avgwtime=0;
	avgttime=0;//reset time
	
	int slice1=slice*2;
	int slice2=slice*4;//initial for other 2 queues' slice time
	
	position=check_arrival(mfq,size);
	
	if(position!=-1)
		mq[0].push_back(mfq[position]);//put the arrival process into first readyqueue
	
	wproc=mq[0].front();//copy to the working process 
	mq[0].pop_front();
	
	do
	{		
                gant.push_back(wproc.number);
		etime+=pow(10.0,tgr*1.0);//add running time
		
		for(int i=0;i<size;i++)
			mfq[i].atime-=pow(10.0,tgr*1.0);//deduct time for those processes which have not arrive
		
		for(int i=0;i<3;i++)
		{
			if(!mq[i].empty())
				for(int j=0;j<mq[i].size();j++)
					mq[i][j].wtime+=pow(10.0,tgr*1.0);//add waiting time for those process in the ready queue
		}
		
		position=check_arrival(mfq,size);//check arrival process

		if(position!=-1)
		{
			mq[0].push_back(mfq[position]);//put arrival process into first ready queue
			wproc.btime-=pow(10.0,tgr*1.0);//deduct brust time for current process
			wproc.rtime+=pow(10.0,tgr*1.0);//add running time fo current process
				
			if(wproc.priority>0)//check the current working process is at level0 or not
			{
				switch(wproc.priority)//pre-empted has half slice time of current queue level
				{
					case 1:
						wproc.vip1=true;
						break;
					case 2:
						wproc.vip2=true;
						break;
				}

				mq[wproc.priority].push_front(wproc);//put it into its own queue level
				wproc=mq[0].front();//copy first level to the working process 
				mq[0].pop_front();
			}
			
			
		}
		else
		{
			wproc.btime-=pow(10.0,tgr*1.0);//deduct brust time for current process
			wproc.rtime+=pow(10.0,tgr*1.0);//add running time fo current process
		}
		
		if(wproc.btime==0)
		{
			for(int i=0;i<size;i++)
			{
				if(wproc.number==mfq[i].number)//record wait time and clean the brust time
				{
					mfq[i].wtime=wproc.wtime;
					mfq[i].ftime=etime;
					mfq[i].btime=0;
				}
			}
			
			for(int i=0;i<3;i++)
			{
				if(!mq[i].empty())
				{
					wproc=mq[i].front();//copy to the working process 
					mq[i].pop_front();
					break;
				}
			}
		}
		else 
		{
			switch(wproc.priority)
			{
				case 0:
					if(wproc.rtime%slice==0&&wproc.rtime>0)
					{
						wproc.priority++;
						mq[wproc.priority].push_back(wproc);//put the process to the next level queue
						
						for(int i=0;i<3;i++)
						{
							if(!mq[i].empty())
							{
								wproc=mq[i].front();//copy to the working process 
								mq[i].pop_front();
								break;
							}
						}
					}
					break;
				case 1:
					if(!wproc.vip1)
					{
						if((wproc.rtime-slice)%slice1==0&&wproc.rtime>0)
						{
							wproc.priority++;
							mq[wproc.priority].push_back(wproc);//put the process to the next level queue
							
							for(int i=0;i<3;i++)
							{
								if(!mq[i].empty())
								{
									wproc=mq[i].front();//copy to the working process 
									mq[i].pop_front();
									break;
								}
							}	
						}
					}
					else
					{
						if((wproc.rtime-slice)%slice==0&&wproc.rtime>0)
						{
							wproc.vip1=false;
							wproc.priority++;
							mq[wproc.priority].push_back(wproc);//put the process to the next level queue
							for(int i=0;i<3;i++)
							{
								if(!mq[i].empty())
								{
									wproc=mq[i].front();//copy to the working process 
									mq[i].pop_front();
									break;
								}
							}
						}
					}
					break;
				case 2:
					if(!wproc.vip2)
					{
						if((wproc.rtime-slice-slice1)%slice2==0&&wproc.rtime>0)
						{
							mq[wproc.priority].push_back(wproc);//put the process to the next level queue
							for(int i=0;i<3;i++)
							{
								if(!mq[i].empty())
								{
									wproc=mq[i].front();//copy to the working process 
									mq[i].pop_front();
									break;
								}
							}
						}
					}
					else
					{
						if((wproc.rtime-slice-slice1)==0&&wproc.rtime>0)
						{
							wproc.vip2=false;
							mq[wproc.priority].push_back(wproc);//put the process to the next level queue
							
							for(int i=0;i<3;i++)
							{
								if(!mq[i].empty())
								{
									wproc=mq[i].front();//copy to the working process 
									mq[i].pop_front();
									break;
								}
							}
						}
					}
					break;
			}
		}
	}while(!complete(mfq,size));
        
	for(int i=0;i<size;i++)
		avgwtime+=mfq[i].wtime;
	
	cout<<endl<<"          Multi Feedback Queue "<<"("<<slice<<"ms)"<<endl;
	cout<<endl<<"Gantt Chart: ";
	vector<int>::iterator it=gant.begin();
	while(it!=gant.end())
	{
		cout<<*it;
		it++;
	}
	cout<<endl;
	cout<<endl<<"          BT          WT          TT"<<endl;
	for(int i=0;i<size;i++)
		cout<<"P"<<mfq[i].number<<": "<<setw(8)<<proc[i].btime<<setw(12)<<mfq[i].wtime<<setw(12)<<mfq[i].ftime-proc[i].atime<<endl;
	for(int i=0;i<size;i++)
		avgttime+=mfq[i].ftime-proc[i].atime;
	
	cout<<"Average:"<<setw(16)<<avgwtime/size<<setw(12)<<avgttime/size<<endl;
	
	delete [] mfq;
	delete [] proc;
	
	return 0;
}

