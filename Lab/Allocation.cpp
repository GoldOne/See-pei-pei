#include"Allocation.h"
using namespace std;

Allocation::Allocation(int num,std::string id,std::string code)
{
	Number=num;
	LabID=id;
	SubjectCode=code;
}

Allocation::Allocation()
{
	Number=0;
	LabID="";
	SubjectCode="";
}

AllocationList::AllocationList()
{
	head=NULL;
	tail=NULL;
}

AllocationList::~AllocationList()
{
	while(head!=NULL)
	{
		AllocationNode* temp=head->getNext();
		delete head;
		head=temp;
	}
	tail=NULL;
}

bool AllocationList::find(const Allocation & from)
{
	Allocation result;
	AllocationNode* current;
	current=head;
	while(current!=NULL)
	{
		if(current->getObject().getNum()==from.getNum()&&current->getObject().getID()==from.getID()&&current->getObject().getCode()==from.getCode())
		{
			result=current->getObject();
			return true;
		}
		current=current->getNext();
	}
	return false;
}

void AllocationList::push_back( const Allocation & from)
{
	int aim;

	if(find(from))
		aim=from.getNum();

	if(from.getNum()==aim)
	{
		cout<<"Duplicated Allocation record found!!! Push back failed!!!"<<endl;
        	return;
    	}

	if(from.getCode().length()==0)
		return;
	AllocationNode* temp=new AllocationNode;
	temp->setObject(from);
	temp->setNext(NULL);
	if(head==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		tail->setNext(temp);
		tail=temp;
	}
}