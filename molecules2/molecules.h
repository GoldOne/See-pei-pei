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
	
	char finger[9];
	
	mol left;
	
	mol right;
};
	
struct buffer
{
	float position;
	
	float speed;
	
	int energy;
	
	char finger[9];
};
	
int import(mol &,int &);

void report(mol &,int);

int insert(mol &,buffer);

bool find(mol ,buffer);

void inorder(mol,molecules [],int &);
