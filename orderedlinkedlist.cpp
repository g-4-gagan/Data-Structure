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
			return;
		}
		friend class SLL;
};

class SLL
{
	node* head;
	
	public:
		SLL(node* ptr = 0)
		{
	        head = ptr;
	        return;
        }
		void insert(int a);
		void print();
};

void SLL::insert(int a)
{
	if(head)
	{
		node* curr = head;
		if(a>head->val)
		{
			for(;curr->next&&a>curr->next->val;curr=curr->next);
			curr->next = new node(a,curr->next);
			return;
		}
	}
	head = new node(a,head);
}

void SLL::print()
{
	if(head)
	{
		node* current=head;
		for(;current;current=current->next)
		{
			cout<<current->val<<" ";
		}
		cout<<endl;
	}
	return;
}

int main()
{
	SLL s;
	s.insert(10);
	s.insert(9);
	s.insert(12);
	s.insert(5);
	s.insert(7);
	s.print();
}
