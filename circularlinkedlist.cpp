#include<iostream>
using namespace std;

class node
{
	int val;
	node* next;
	
	public:
		node(int a=0,node* ptr=0)
		{
			val=a;
			next=ptr;
		}
		friend class CLL;
};

class CLL
{
	node* tail;
	
	public:
		CLL(node* ptr=0)
		{
			tail=ptr;
		}
		void insertatfront(int a);
		void insertafter(int x,int y);
		void insertatback(int a);
		int removefromfront();
		int removefromback();
		int removeelement(int x);
		node* search(int a);
		void concatenate(CLL& c);
		void print();
};

void CLL::insertatfront(int a)
{
	if(tail)
	{
		tail->next=new node(a,tail->next);
		return;
	}
	tail = new node(a,0);
	tail->next=tail;
}

void CLL::insertafter(int x,int y)
{
	node* curr=search(y);
	if(curr)
	{
		curr->next=new node(x,curr->next);
		return;
	}
	insertatback(x);
}

void CLL::insertatback(int a)
{
	if(tail)
	{
		tail = tail->next=new node(a,tail->next);
		return;
	}
	tail = new node(a,0);
	tail->next=tail;
}

int CLL::removefromfront()
{
	if(tail)
	{
		node* curr=tail->next;
		int a = curr->val;
		if(curr==tail)
		{
			tail=0;			
		}
		else
		{
		    tail->next=curr->next;
		}
		delete curr;
		return a;
	}
	return -1;	
}

int CLL::removefromback()
{
	if(tail)
	{
		node* curr=tail;
		int a=curr->val;
		if(tail->next==tail)
		{
			tail=0;			
		}
		else
		{
			node* temp=tail->next;
			for( ;temp->next!=tail;temp=temp->next);
		    temp->next=tail->next;
			tail=temp;		    
		}
		delete curr;
		return a;
	}
	return -1;
	
}

int CLL::removeelement(int x)
{
	node* curr=tail->next;
	node* prev=tail;
	do{
		if(curr->val==x)
		{
			prev->next=curr->next;
			int a=curr->val;
			delete curr;
			return a;
		}
		prev=curr;
		curr=curr->next;		
	}while(curr!=tail);
	return -1;
}

node* CLL::search(int a)
{
	node* temp=tail->next;
	do
	{
		if(temp->val==a)
		{
			return temp;
		}
		temp=temp->next;		
	}
	while(temp!=tail);
	return 0;
}

void CLL::concatenate(CLL& c)
{
	node* curr=tail->next;
	tail->next=c.tail->next;
	c.tail->next=curr;
	tail=c.tail;
	c.tail=0;	
}

void CLL::print()
{
	if(tail)	
	{
		node* curr = tail->next;
		do{
			cout<<curr->val<<" ";
			curr=curr->next;
		}
		while(curr!=tail->next);
		cout<<endl;
	}
	return;
}

int main()
{
	CLL c,s;
	c.insertatback(5);
	c.insertatback(6);
	c.insertatback(7);
	c.insertatback(9);
	c.insertatback(2);
	c.insertatback(3);
	c.print();
	cout<<endl<<c.removefromfront()<<endl;
	c.print();
	cout<<endl<<c.removefromback()<<endl;
	c.print();
	s.insertatback(10);
	s.insertatback(11);
	s.insertatback(17);
	s.insertatback(19);
	s.insertatback(12);
	s.insertatback(13);
	s.print();
	c.concatenate(s);
	c.print();
	s.print();
	c.insertafter(20,22);
	c.removeelement(17);
	c.print();
//	cout<<c.search(7)<<c.search(10);
	
}
