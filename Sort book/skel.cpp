#include <iostream>
#include <ctime>

#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstring>
using namespace std;

void get_max_words(ifstream& fin, int& wordlen, int& numwords);
int cmp(const void* a, const void* b);
int tcmp(const void* a, const void* b);

int main(int argc, char* argv[])
{

	if(argc != 5)
     {
                cerr << "usage: " << argv[0]
                        << " infile outfile timesfile ntests" << endl;
			exit(EXIT_FAILURE);
     }
/*
	deal with commandline args
	do any preprocessing (max 1 pass over file, space O(1))
	read words into initial array (1 pass over file)
*/
	int ntests = atoi(argv[4]);

/*
	At this point, everything should be in the initial array
	A temporary data structure should be declared but not filled
*/

	/*set up the timer*/	
	clockid_t cpu;
	timespec start, end;
	long* times = new long[ntests];
	if(clock_getcpuclockid(0, &cpu) != 0)
	{
		cerr << "Error: could not get cpu clock" << endl;
		exit(EXIT_FAILURE);
	}
		
	for(int i=0; i<ntests; i++)
	{
		/*start the timer*/
		if(clock_gettime(cpu, &start) == -1)
		{
			cerr << "Error: could not get start time" << endl;
			exit(EXIT_FAILURE);
		}

		/*copy from initial array to temporary data structure*/
		/*sort data in temporary structure*/

		/*stop timer*/
		if(clock_gettime(cpu, &end) == -1)
		{
			cerr << "Error: could not get end time" << endl;
			exit(EXIT_FAILURE);
		}

		/*time per test in nanoseconds*/
		times[i] = (end.tv_sec - start.tv_sec)*1000000000 + 
                        end.tv_nsec - start.tv_nsec;
	}
	/*output sorted temporary array*/
	/*sort times array and output it*/
	delete[] times;
}
