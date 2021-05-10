/*
Name:- Gagan kumar Soni
Roll no:- (0814) 19035570036
Paper Name:- Data Structures
Course and semester:- Bsc Computer science Hons. sem-3
Set no:- 
Question:-2. Implement a Queue efficiently using a Singly Linked List (access using Head and 
Tail pointers).
Include the following operations: enqueue(), dequeue(), clear(), isEmpty. Write a function(not 
a part of the class queue) that extracts the minimum element of the queue. The function may use 
additional queues only.
*/

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
		friend class SLL;
		friend class queue;
};

class SLL
{
	node* head;
	node* tail;
	
	public:
		SLL(node* ptr1 = 0, node* ptr2 = 0)
		{
	        head = ptr1;
	        tail = ptr2;
	        return;
        }
        ~SLL()
		{
			if(head)
			{
				for(;head;)
				{
					removefromhead();					
			    }
				
			}
		}
		void insertattail(int a);
		int removefromhead();
		void print();
		friend class queue;
};

void SLL::insertattail(int a)
{
	if(!head)
	{
		head = new node(a,0);
		tail=head;
	}
	else
	{
		tail=tail->next = new node(a,0);		
	}
	return;
}

int SLL::removefromhead()
{
	if(head)
	{
		node* current = head;
	    int a=current->val;
		if(head==tail)
		{
			head = 0;
			tail = 0;			
		}
		else
		{
		    head = head->next;
		}
		delete current;
		return a;
	}
	else
	{
		return -1;
	}
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

class queue
{
	SLL s;
	
	public:
		queue()
		{
			s.head=0;
			s.tail=0;			
		}
		void enqueue(int a);
		int dequeue();
		bool isempty();
		void clear();
		void print();	
};

void queue::enqueue(int a)
{
	s.insertattail(a);
}

int queue::dequeue()
{
	return s.removefromhead();
}

bool queue::isempty()
{
	return !s.head;
}

void queue::clear()
{
	s.~SLL();	
}

void queue::print()
{
	s.print();
}

int extractmin(queue& q)
{
	queue temp;
	int min = -1;
	if(!q.isempty())
	{
		int a=q.dequeue();
		min=a;
		temp.enqueue(a);
		for(;!q.isempty();)
		{
			a = q.dequeue();
			temp.enqueue(a);
			if(a<min)
			{
				min = a;
			}
		}
		for(;!temp.isempty();)
		{
			a = temp.dequeue();
			q.enqueue(a);
		}		
	}
	return min;
}

int main()
{
	queue q;
	int choice; int flag = 1;   int x;
    cout << "----- Menu -----\n"
         << "1.Enqueue\n"
         << "2.Dequeque\n"
         << "3.Clear\n"
         << "4.Check Empty\n"
		 << "5.Extract minimum\n"
		 << "6.Print queue\n"
         << "7.Exit\n";
    while(flag){
        cout << "Enter your choice : ";
        cin >> choice;
        
        switch (choice)
        {
        	case 1:
        		cout << "Enter data : ";
                cin >> x;
                q.enqueue(x);
                break;
            case 2:
            	cout<<"Dequeued element is: "<<q.dequeue()<<endl;
            	break;
            case 3:
            	q.clear();
            	cout<<"The queue has been cleared\n";
            	break;
            case 4:
            	cout<<"The empty status of queue is: "<<q.isempty()<<endl;
            	break;
            case 5:
            	cout<<"The minimum element of queue is: "<<extractmin(q)<<endl;
            	break;
            case 6:
            	q.print();
            	break;
            case 7:
            	flag = false;
                break;
            default:
            	cout<<"Please enter a valid choice!!!\n";            	
            	
		}
    }
    return 0;
	
}

