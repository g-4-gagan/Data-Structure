#include<iostream>
using namespace std;

class node
{
	node* prev;
	int val;
	node* next;
	
	public:
		node(node* ptr=0,int a=0,node* ptr1=0)
		{
			prev=ptr;
			val=a;
			next=ptr1;
			return;
		}
		friend class DLL;
};

class DLL
{
	node* head;
	node* tail;
	
	public:
		DLL()
		{
			head = new node(0,0,tail);
			tail= new node(head,0,0);
			head->next = tail;
			return;
		}
		void add(node* ptr,int a);
		void insertathead(int a);
		void insertatpos(int a,int pos);
		void insertattail(int a);
		int remove(node* ptr);
		int removefromhead();
		int removefrompos(int pos);
		int removefromtail();
		int removenode(int a);
		node* search(int a);
		void concatenate(DLL& d);
		void print();
};

void DLL::add(node* ptr,int a)
{
	node* current=ptr->prev;
	current->next=ptr->prev=new node(current,a,ptr);
	return;
}

void DLL::insertathead(int a)
{
	add(head->next,a);
	return;
}

void DLL::insertatpos(int a,int pos)
{
	node* current = head->next;
	for(int i=1;current!=tail&&i<pos;i++)
	{
		current=current->next;
	}
	add(current,a);
	return;
}

void DLL::insertattail(int a)
{
	add(tail,a);
	return;
}

int DLL::remove(node* ptr)
{
	node* current=ptr->prev;
	ptr->next->prev=current;
	current->next=ptr->next;
	int temp=ptr->val;
	delete ptr;
	return temp;
}

int DLL::removefromhead()
{
	if(head->next!=tail)
	{
		return remove(head->next);
	}
	return -1;
	
}

int DLL::removefrompos(int pos)
{
	if(head->next!=tail)
	{
		node*current = head->next;
		int i=1;
		for(;current->next!=tail&&i<pos;i++,current=current->next);
		if(i==pos)
		{
			return remove(current);
		}
	}
	return -1;	
}

int DLL::removefromtail()
{
	if(head->next!=tail)
	{
		return remove(tail->prev);
	}
	return -1;
}

int DLL::removenode(int a)
{
	if(search(a)->next!=0)
	{
		return(remove(search(a)));
	}
	return -1;	
}

node* DLL::search(int a)
{
	node* current=head->next;
	while(current!=tail)
	{
		if(current->val==a)
		{
			return current;
		}
		current=current->next;
	}
	return new node();
}

void DLL::concatenate(DLL& d)
{
	node* current=tail->prev;
	node* temp=d.head->next;
	current->next=temp;
	temp->prev=current;
	d.tail->prev->next=tail;
//	d.head = new node(0,0,d.tail);
//	d.tail= new node(d.head,0,0);
	d.head->next = d.tail;
	d.tail->prev = d.head;
	return;
}

void DLL::print()
{
	if(head->next!=tail)
	{
		node* current=head->next;
		while(current!=tail)
		{
			cout<<current->val<<" ";
			current=current->next;
		}
		cout<<endl;
	}
	return;
}

int main()
{
	DLL ob1,ob2;
	ob1.insertathead(5);
	ob1.insertathead(4);
	ob1.insertathead(4);
	ob1.insertathead(8);
	ob1.insertathead(5);
	ob1.insertathead(9);
	ob1.insertatpos(2,1);
	ob1.insertatpos(7,8);
	ob1.insertattail(3);
	ob1.print();
	ob1.removefromhead();
	ob1.removefrompos(4);
	ob1.removefrompos(8);
	ob1.removefromtail();
	ob1.print();
	cout<<ob1.removenode(8)<<" "<<ob1.removenode(12)<<endl;
	ob1.print();
	ob2.insertathead(5);
	ob2.insertathead(7);
	ob2.concatenate(ob1);
	ob2.print();
	ob1.print();
	
}
