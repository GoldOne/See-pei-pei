/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
struct molecules;

typedef molecules *mol;

struct molecules
{
	float position;
	
	float speed;
	
	int energy;
	
	mol next;
};
	
int import(mol &,int &);

void report(mol &,int);
