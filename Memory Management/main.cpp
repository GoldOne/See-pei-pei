#include"dmm.h"
#include<list>
#include<iomanip>
using namespace std;

list<char*> List;

void test(DMM ins,WORD* mmu,int Size,int Seed,int Max,int N)
{
	int Sd=Seed;
        int bits=0;
        int comps=0;
        int blocks=0;
	
	for(int i=0;i<N;i++)
	{
		srand(Sd++);
		while(1)
		{
			int NumChars=(rand()%Max+1)*4;
			char* Addr=ins.New(NumChars);
			if(Addr==NULL)
				break;
			List.push_back(Addr);
		}
		srand(++Sd);
		int M=List.size()/2;
		for(int j=0;j<M;j++)
		{
			int pos=rand()%List.size();
                        list<char*>::iterator it=List.begin();
                        advance(it,pos);
                        List.erase(it);
			ins.Delete((char*)mmu[pos]);
		}
	}
	
	ins.GetStats(bits,comps,blocks);
        
	switch (ins.getType())
	{
		case eFirstFit:
			cout<<"FirstFit:"<<setw(15)<<bits<<setw(15)<<comps*1.0/bits<<setw(15)<<blocks<<setw(15)<<comps*1.0/blocks<<endl;
			break;
		case eNextFit:
			cout<<"NextFit: "<<setw(15)<<bits<<setw(15)<<comps*1.0/bits<<setw(15)<<blocks<<setw(15)<<comps*1.0/blocks<<endl;
			break;
		case eBestFit:
			cout<<"Best_Fit:"<<setw(15)<<bits<<setw(15)<<comps*1.0/bits<<setw(15)<<blocks<<setw(15)<<comps*1.0/blocks<<endl;
			break;
		case eWorstFit:
			cout<<"WorstFit:"<<setw(15)<<bits<<setw(15)<<comps*1.0/bits<<setw(15)<<blocks<<setw(15)<<comps*1.0/blocks<<endl;
	}	
}

int main(int argc, char* argv[])
{
	if(argc!=5)
	{
		cout<<"Usage: "<<argv[0]<<" <Size> <Seed> <Max> <N>"<<endl;
		exit(0);
	}
	
	WORD *tmp=new WORD[atoi(argv[1])];
	DMM FF(tmp,atoi(argv[1]),eFirstFit);
	DMM NF(tmp,atoi(argv[1]),eNextFit);
	DMM BF(tmp,atoi(argv[1]),eBestFit);
	DMM WF(tmp,atoi(argv[1]),eWorstFit);
	
	cout<<"Size: "<<argv[1]<<setw(10)<<"Seed: "<<argv[2]<<setw(10)<<"Max: "<<argv[3]<<setw(10)<<"N: "<<argv[4]<<endl;
	cout<<endl<<setw(25)<<"Tot Bytes"<<setw(15)<<"Ave Cmps Per"<<setw(15)<<"Tot Blocks"<<setw(18)<<"Ave Cmps Per"<<endl;
	cout<<setw(25)<<"Allocated"<<setw(16)<<"Byte Allocated"<<setw(14)<<"Allocated"<<setw(18)<<"Block Allocated"<<endl;
	cout<<endl;
	test(FF,tmp,atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
	test(NF,tmp,atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
	test(BF,tmp,atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
	test(WF,tmp,atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
	
	delete[] tmp;
	
	return 0;
}
