#ifndef DMM_H
#define	DMM_H
#include<cstring>
#include<cstdlib>
#include<iostream>
typedef unsigned int WORD;

enum Policy{eFirstFit,eNextFit,eBestFit,eWorstFit};

class DMM
{
    private:
        WORD* memory;
	int size;
	Policy type;
	int TotBytes;
	int TotCompares;
	int TotBlocks;
	void Merge(int &head, int &tail);
	int DMMAlgorithem(Policy type, int Size);
	int firstfit(int Size);
	int nextfit(int Size);
	int bestfit(int Size);
	int worstfit(int Size);
        int next;
    public:
        DMM(WORD* Memory,int Words,Policy type);
        char* New(int size);
        void Delete(char* Address);
        void GetStats(int &TotalMemory, int &NumCompares,int &TotalBlocks);
        int getBy(){return TotBytes;}
        int getCom(){return TotCompares;}
        int getBlocks(){return TotBlocks;}
        Policy getType(){return type;}
};

#endif	/* DMM_H */

