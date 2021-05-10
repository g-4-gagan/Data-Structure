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
		void insertathead(int a);
		void insertatpos(int a,int pos);
		int removefromhead();
		int removefrompos(int pos);
		node* search(int a);
		void concatenate(SLL& s);
		void print();
};

void SLL::insertathead(int a)
{
	head = new node(a,head);
	return;
}

void SLL::insertatpos(int a,int pos)
{
	if(head)
	{
		node* current = head;
		for(int i=1;i<pos-1;i++)
		{
			if(!current->next)
			{
				break;
			}
			current = current->next;
		}
		if(pos==1)
		{
			insertathead(a);
		}
		else
		{
			current->next = new node(a,current->next);
		}
	}
	else
	{
		insertathead(a);
	}
	return;
}

int SLL::removefromhead()
{
	if(head)
	{
		node* current = head;
		head = head->next;
		int a=current->val;
		delete current;
		return a;
	}
	else
	{
		return -1;
	}
}

int SLL::removefrompos(int pos)
{
	if(head)
	{
		node* current = head;
		for(int i=1;i<pos-1;i++)
		{
			if(!current->next)
			{
				cout<<"Position not exist\n";
				return -1;
			}
			current = current->next;
		}
		node* temp = current->next;
		current->next = temp->next;
		int a = temp->val;
		delete temp;
		return a;
		
	}
	else
	{
		return -1;
	}	
}

node* SLL::search(int a)
{
	if(head)
	{
		node* current= head;
	    for(;current;current=current->next)
	    {
	    	if(current->val==a)
			{
				return current;
			}	    	
		}
		return new node();
	}
	else
	{
		return new node();
	}
}

void SLL::concatenate(SLL& s)
{
	if(head)
	{
		node* current=head;
		for(;current->next;current=current->next);
		current->next=s.head;
	}
	else
	{
		head=s.head;
	}
	s.head=0;
	return;
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
	SLL s1,s2;
	s1.insertathead(2);
	s1.insertathead(4);
	s1.insertatpos(5,1);
	s2.insertatpos(4,3);
	s1.insertatpos(5,3);
	s1.insertathead(6);
	s1.insertatpos(3,8);
	s1.print();
	cout<<s1.removefromhead()<<endl;
	s1.print();
	cout<<s1.removefrompos(3)<<endl;
    cout<<s1.search(3)<<endl;
    s2.insertathead(5);
    s2.insertathead(6);
    s2.print();
    s2.concatenate(s1);
    s2.print();
	s1.print();	
}
