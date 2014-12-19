//Yi Jin,4370673
#include<iostream>
namespace MYLIB
{	
	template<class T>
	class ListNode
	{
		private:
			T data;
			ListNode<T>* previous;
			ListNode<T>* next;
		public:
			ListNode<T>(const T &t){previous=NULL;next=NULL;data=t;};
			void setNext(ListNode<T> *p){next=p;};
			void setPre(ListNode<T> *p){previous=p;};
			T getNode(){return data;};
			ListNode<T>* getNext(){return next;};
			ListNode<T>* getPre(){return previous;};
	};

	template<class T>
	class OrderedList
	{
		private:
			ListNode<T>* head;
			ListNode<T>* tail;
		public:
			class iterator
			{
				private:
					ListNode<T> *p;
				public:
					iterator(ListNode<T> *tmp){p=tmp;};
					iterator operator++();
					iterator operator++(int);
					T operator*(){return p->getNode();};
					bool operator!=(const iterator& it)const{return p!=it.p;};
			};

			iterator begin(){return iterator(head);};
			iterator end(){return iterator(NULL);};
			void insert(const T &);
			OrderedList(){head=NULL;tail=NULL;};
			~OrderedList();	
	};
	
	template<class T>
	OrderedList<T>::~OrderedList()
	{
		ListNode<T>* cur=head;
		while(cur!=NULL)
		{
			ListNode<T>* temp=cur->getNext();
			delete cur;
			cur=temp;
		}
	}

	template<class T>
	void OrderedList<T>::insert(const T &t)
	{
		ListNode<T>* temp=new ListNode<T>(t);

		if(head==NULL)
			head=temp;
		else
		{
			ListNode<T>* current=head;
			ListNode<T>* mark=NULL;
		
			while(current!=NULL)
			{
				if(temp->getNode()<=current->getNode())
					break;
				else
				{
					mark=current;//get the position to insert
					current=current->getNext();
				}
			}

			if(mark==NULL)
			{
				if(temp->getNode()<=current->getNode())//insert into the first node
				{
					temp->setNext(head);
					current->setPre(temp);
					head=temp;
				}
				else//insert into the last node
				{
					temp->setPre(current);
					temp->setNext(current->getNext());
					current->setNext(temp);
				}
			}
			else//insert into the postion between mark and current
			{
				temp->setNext(current);
				mark->setNext(temp);
				temp->setPre(mark);
				if(current!=NULL)
					current->setPre(temp);
			}
		}
	}

	template<class T>
	class OrderedList<T>::iterator OrderedList<T>::iterator::operator++()
	{
		if(p!=NULL)
			p=p->getNext();
		return *this;
	}

	template<class T>
	class OrderedList<T>::iterator OrderedList<T>::iterator::operator++(int)
	{
		iterator temp(NULL);
		temp=*this;

		if(p!=NULL)
			p=p->getNext();
		return temp;
	}
}

