#include<ctime>
#include<cctype>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<iostream>

using namespace std;

struct Tnode;//decleare a binary tree node

struct Tnode
{
	char data[256];

	int count;

	Tnode* left;

	Tnode* right;
};

void clean(Tnode* &root)//clean the whole tree
{
	if(root!=NULL)
	{
		clean(root->left);
		clean(root->right);
		delete root;
		root=NULL;
	}
}

static bool find(Tnode*,char []);
static void insert(Tnode* &,char []);
static void inorder(Tnode* ,char** ,int &);

class Tree
{
	private:
		Tnode* root;
	public:
		Tree(){root=NULL;}
		~Tree(){clean(root);}
		bool Find(char temp[]){return find(root,temp);}
		void Insert(char temp[]){insert(root,temp);}
		void Inorder(char**temp,int &i){inorder(root,temp,i);}
};

static bool find(Tnode* root,char temp[])//find whether the words in the tree or not
{
	if(root==NULL)
		return false;
	else
	{
		if(strcmp(root->data,temp)==0)
		{
			root->count++;//if find then increase the count
			return true;
		}	
		else if(strcmp(root->data,temp)<0)
			return find(root->right,temp);
		else
			return find(root->left,temp);
	}
}

static void insert(Tnode* &root,char temp[])//insert the word by using binary search tree
{
	if(root==NULL)
	{
		Tnode* node=new Tnode;
		strcpy(node->data,temp);
		node->count=1;
		node->left=NULL;
		node->right=NULL;
		root=node;
	}
	else if(strcmp(root->data,temp)<0)//compare by dictionary order		
		insert(root->right,temp);
	else
		insert(root->left,temp);
}

int tcmp(const void*a, const void*b)
{
	return *(reinterpret_cast<const long*>(a))>*(reinterpret_cast<const long*>(b));
}

static void inorder(Tnode* root,char** temp,int &i)//inorder traversal
{		
	if(root!=NULL)
	{
		inorder(root->left,temp,i);
		do
		{
			strcpy(temp[i],root->data);
			i++;
			root->count--;
		}while(root->count>0);
		inorder(root->right,temp,i);
	}
}

int main(int argc,char* argv[])
{
	char word[256];
	int longest=0;//the longest word in the file

	if(argc!=5)
	{
		cerr<<"usage: "<<argv[0]<<" inputfile outputfile timesfile ntests"<<endl;
	}

	ifstream fin(argv[1]);

	if(fin.fail())
	{
		cerr<<"Error: failed to open file "<<argv[1]<<" for input!!!"<<endl;
		exit(EXIT_FAILURE);
	}

	int ntests=atoi(argv[4]);
	int num=0;

	while(fin>>word)
	{
		if(longest<strlen(word))
			longest=strlen(word);
		num++;//get the total number of words
	}

	char** words=new char*[num];
	for(int i=0;i<num;i++)
		words[i]=new char[256];

	fin.clear();
	fin.seekg(0,ios::beg);

	while(fin>>word)
	{
		int static i=0;
		strcpy(words[i],word);//storing all words in array
		i++;
	}

	fin.close();

	char** temp=new char*[num];
	for(int i=0;i<num;i++)
		temp[i]=new char[256];
	/*
	At this point, everything should be in the initial array
	The temporary array should be declared but not filled
	*/
	clockid_t cpu;
	timespec start,end;
	long time[ntests];
	if(clock_getcpuclockid(0,&cpu)!=0)
	{
		cerr<<"Error: could not get cpu clock !!!"<<endl;
		exit(EXIT_FAILURE);
	}	

	Tree* trees=new Tree[longest];

	for(int i=0;i<ntests;i++)
	{
		Tree* forest=new Tree[longest];

		/*start timer*/
		if(clock_gettime(cpu,&start)==-1)
		{
			cerr<<"Error: could not get start time !!!"<<endl;
			exit(EXIT_FAILURE);
		}

		/*copy from initial array to temporary array*/
		for(int j=0;j<num;j++)
			strcpy(temp[j],words[j]);

		/*sort temporary array*/
		if(i==0)
		{
	     		for(int k=0;k<num;k++)
			{
				int len=strlen(temp[k]);//insert the words by same length			
				if(!trees[len-1].Find(temp[k]))//only insert the different words!!!
					trees[len-1].Insert(temp[k]);
			}
		}
		else
		{
			for(int k=0;k<num;k++)
			{
				int len=strlen(temp[k]);			
				if(!forest[len-1].Find(temp[k]))//only insert the different words!!!
					forest[len-1].Insert(temp[k]);
			}
		}
		/*stop timer*/
		if(clock_gettime(cpu,&end)==-1)
		{
			cerr<<"Error: could not get end time !!!"<<endl;
			exit(EXIT_FAILURE);
		}

		/*time per trial in nanoseconds*/
		time[i]=(end.tv_sec-start.tv_sec)*1000000000+end.tv_nsec-start.tv_nsec;

		delete [] forest;
	}

	/*output sorted temporary array*/
     	qsort(time,ntests,sizeof(long),tcmp);

	ofstream fout(argv[2]);

	int count=0;

	for(int i=0;i<longest;i++)
		trees[i].Inorder(temp,count);

	for(int i=1;i<count;i++)
	{
		if(i%10==0)
			fout<<temp[i]<<endl;
		else
			fout<<temp[i]<<" ";
	}		

	/*output time required for test*/
	ofstream ftimes(argv[3]);
	for(int i=0;i<ntests;i++)
		ftimes<<time[i]<<endl;
	
	for(int i=0;i<num;i++)
		delete [] temp[i];

	delete [] temp;

	for(int i=0;i<num;i++)
		delete [] words[i];

	delete [] words;

	delete [] trees;

	return 0;
}
	
