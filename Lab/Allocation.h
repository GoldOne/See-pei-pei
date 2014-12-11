#include<iostream>
#include<string>
class Allocation
{
	private:
		int Number;
		std::string LabID;
		std::string SubjectCode;
	public:
		int getNum() const {return Number;};
		void setNum(int num) {Number=num;};
		std::string getID() const {return LabID;};
		void setID(std::string id) {LabID=id;};
		std::string getCode() const {return SubjectCode;};
		void setCode(std::string code) {SubjectCode=code;};
		Allocation(int num,std::string id,std::string code);
		Allocation();
};

class AllocationNode
{
	private:
		Allocation node;
		AllocationNode* next;
	public:
		Allocation getObject() {return node;};
		void setObject(Allocation all) {node=all;};
		AllocationNode* getNext() {return next;};
		void setNext(AllocationNode* Next) {next=Next;};
};

class AllocationList
{
	private:
		AllocationNode* head;
		AllocationNode* tail;
	public:
		AllocationList();
		~AllocationList();
		void push_back( const Allocation & from);
		AllocationNode * front() {return head;};
		bool find(const Allocation & from);
};
