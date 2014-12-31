#include"dmm.h"
using namespace std;

DMM::DMM(WORD *Memory,int Words,Policy Type)//constructor
{
	memory=Memory;
	size=Words;
	next=0;
	type=Type;
	memory[0]=size;
	memory[size-1]=size;
	TotBytes=0;
	TotCompares=0;
	TotBlocks=0;
}

char* DMM::New(int Size)
{
	TotBytes+=Size;
	TotBlocks++;
	size=Size/4;
	char* addr;
	int pos=0;
	pos=DMMAlgorithem(type,size);
	if(pos==-1)
		return NULL;//not suitable whole for the memory 
	addr=(char*)&memory[pos];
	return addr;
}
void DMM::Delete(char *Address)
{
	int head=0;
	int tail=0;
	WORD *Mem=(WORD*)Address;
	for(int i=0;i<size;i++)
	{
		if(&memory[i]==Mem)
		{
			head=i;
			break;
		}
	}
	int length=(memory[head]<<1)>>1;
	if(memory[head]>>31!=1||memory[head+length+1]!=memory[head])
	{
		cerr<<"The memory is invalid to free!!!"<<endl;
		exit(1);
	}
	memory[head]=((memory[head]<<1)>>1);
	tail=head+memory[head]+1;
	memory[tail]=((memory[head]<<1)>>1);
	Merge(head,tail);
}

void DMM::Merge(int &head, int &tail)//Merge the free blocks for memory
{
	if(tail+1<size)
		if(memory[tail+1]>>31==0)
		{
			memory[head]+=memory[tail+1]+2;
			memory[tail]=0;
			memory[tail+1]=0;
			tail=head+memory[head]+1;
			memory[tail]=memory[head];
		}

	if(head>0)
		if(memory[head-1]>>31==0)
		{
			memory[tail]+=memory[head-1]+2;
			memory[head]=0;
			memory[head-1]=0;
			head=tail-memory[tail]-1;
			memory[tail]=memory[head];
		}
}

void DMM::GetStats(int &TotalMemory,int &NumCompares,int &NumBlocks)
{
	TotalMemory=TotBytes;
	NumCompares=TotCompares;
	NumBlocks=TotBlocks;
}

int DMM::DMMAlgorithem(Policy Type, int Size)
{
	int index=0;
	switch (Type)
	{
		case eFirstFit:
			index=firstfit(Size);
			break;
		case eNextFit:
			index=nextfit(Size);
			break;
		case eBestFit:
			index=bestfit(Size);
			break;
		case eWorstFit:
			index=worstfit(Size);
			break;
	}
	return index;
}


int DMM::firstfit(int Size)
{
	int index=0;
	while(index<size)
	{
		if((memory[index]>>31)!=0)
		{
                        TotCompares++;
			index+=((memory[index]<<1)>>1)+2;
			continue;
		}
		else if(memory[index]<Size)
		{
                        TotCompares++;
			index+=memory[index]+2;
			continue;
		}
		else//find the hole
		{
			TotCompares++;
			int end=index+memory[index]+1;
			if((memory[index]-Size)>2)
			{
				int tail=index+Size+1;
				memory[tail+1]=memory[index]-Size-2;
				memory[end]=memory[index]-Size-2;
				memory[index]=Size;
				memory[index]=memory[index]|(1<<31);
				memory[tail]=memory[index];
			}
			else
			{
				memory[index]=memory[index]|(1<<31);
				memory[end]=memory[index];
			}
			return index;
		}
	}
	return -1;
}

int DMM::nextfit(int Size)
{
	int index=next;
	while(index<size+next)
	{
		if(index>=size)
			index-=size;
		
		if((memory[index]>>31)!=0)
		{
			TotCompares++;
			index+=((memory[index]<<1)>>1)+2;
			continue;
		}
		else if(memory[index]<Size)
		{
			TotCompares++;
			index+=memory[index]+2;
			continue;
		}
		else//find the whole
		{
			TotCompares++;
			int end=index+memory[index]+1;
			if((memory[index]-Size)>2)
			{
				int tail=index+Size+1;
				memory[tail+1]=memory[index]-Size-2;
				memory[end]=memory[index]-Size-2;
				memory[index]=Size;
				memory[index]=memory[index]|(1<<31);
				memory[tail]=memory[index];
			}
			else
			{
				memory[index]=memory[index]|(1<<31);
				memory[end]=memory[index];
			}
			next=index+1;
			return index;
		}
	}
	return -1;
}

int DMM::bestfit(int Size)
{
	int index=0;
	int disparity=9999;
	int position=-1;
	while(index<size)
	{
		if((memory[index]>>31)!=0)
		{
			TotCompares++;
			index+=((memory[index]<<1)>>1)+2;
			continue;
		}
		else if(memory[index]<Size)
		{
			TotCompares++;
			index+=memory[index]+2;
			continue;
		}
		else if(disparity>memory[index]-Size)//find the best whole fit the size
		{
			TotCompares++;
			disparity=memory[index]-Size;
			int end=index+memory[index]+1;
			if((memory[index]-Size)>2)
			{
				int tail=index+Size+1;
				memory[tail+1]=memory[index]-Size-2;
				memory[end]=memory[index]-Size-2;
				memory[index]=Size;
				memory[index]=memory[index]|(1<<31);
				memory[tail]=memory[index];
				position=index;
				index=tail+1;
			}
			else
			{
				memory[index]=memory[index]|(1<<31);
				memory[end]=memory[index];
				position=index;
				index=end+1;
			}
		}
		else
		{
			index+=memory[index]+2;
			continue;
		}
	}
	return position;
}

int DMM::worstfit(int Size)
{
	int index=0;
	int disparity=0;
	int position=-1;
	while(index<size)
	{
		if((memory[index]>>31)!=0)
		{
			TotCompares++;
			index+=((memory[index]<<1)>>1)+2;
			continue;
		}
		else if(memory[index]<Size)
		{
			TotCompares++;
			index+=memory[index]+2;
			continue;
		}
		else if(disparity<=memory[index]-Size)//find the worse size of the whole
		{
			TotCompares++;
			disparity=memory[index]-Size;
			int end=index+memory[index]+1;
			if((memory[index]-Size)>2)
			{
				int tail=index+Size+1;
				memory[tail+1]=memory[index]-Size-2;
				memory[end]=memory[index]-Size-2;
				memory[index]=Size;
				memory[index]=memory[index]|(1<<31);
				memory[tail]=memory[index];
				position=index;
				index=tail+1;
			}
			else
			{
				memory[index]=memory[index]|(1<<31);
				memory[end]=memory[index];
				position=index;
				index=end+1;
			}
		}
		else
		{
			index+=memory[index]+2;
			continue;
		}
	}
	return position;
}

