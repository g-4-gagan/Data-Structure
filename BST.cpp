#include<iostream>
#include<queue>
using namespace std;

class node
{
	int value;
	node*left,*right;
	
	public:
		node(node* ptr1=0,int val=0,node* ptr2=0)
		{
			left=ptr1;
			value=val;
			right=ptr2;
			return;
		}
		friend class BST;
};

class BST
{
	node* root;
	
	public:
		BST(node* ptr=0)
		{
			root=ptr;
			return;
		}
		void insert(int val);
		void findand_deletebymerge(int x);
		void findand_deletebycopy(int x);
		void deletebymerge(node *&curr);
		void deletebycopy(node *&curr);
		void preorderdisplay(node *ptr);
		void inorderdisplay(node *ptr);
		void postorderdisplay(node *ptr);
		void displaylevel();
		int height(node* ptr);
		node* Root();
};

void BST::insert(int val)
{
	if(root)
	{
		node* current = root;
		while(true)
		{
			if(val>current->value)
			{
				if(current->right==0)
				{
					current->right=new node(0,val,0);
					return;
				}
				else
				{
					current=current->right;
				}
			}
			else
			{
				if(current->left==0)
				{
					current->left=new node(0,val,0);
					return;
				}
				else
				{
					current=current->left;
				}
			}
		}
				
	}
	root = new node(0,val,0);
	return;
}

void BST::findand_deletebymerge(int x)
	{
		if(root)
		{
		    node *curr=root,*prev=0;
				while(curr!=0)
				{
					if(curr->value==x)
						break;
					prev=curr;
					if(x<curr->value)
						curr=curr->left;
					else
						curr=curr->right;
				}
				if(curr!=0 && curr->value==x)
				{
					if(curr==root)
						deletebymerge(root);
					else if(prev->left==curr)
						deletebymerge(prev->left);
					else
						deletebymerge(prev->right);
				}
				else
					cout<<"Element not present in the tree";
			}
			else
				cout<<"The tree is empty";
		}
		
void BST::deletebymerge(node *&curr)
		{
			node *temp=curr;
			if(curr->right==0)
				curr=curr->left;
			else if(curr->left==0)
				curr=curr->right;
			else
			{
				temp=curr->left;
				while(temp->right!=0)
					temp=temp->right;
				temp->right=curr->right;
				temp=curr;
				curr=curr->left;
			}
			delete temp;
		}
		
void BST::findand_deletebycopy(int x)
		{
			if(root)
			{
				node *curr=root,*prev=0;
				while(curr!=0)
				{
					if(curr->value==x)
						break;
					prev=curr;
					if(x<curr->value)
						curr=curr->left;
					else
						curr=curr->right;
				}
				if(curr!=0 && curr->value==x)
				{
					if(curr==root)
						deletebycopy(root);
					else if(prev->left==curr)
						deletebycopy(prev->left);
					else
						deletebycopy(prev->right);
				}
				else
					cout<<"Element not present in the tree";
			}
			else
				cout<<"The tree is empty";
		}
		
void BST::deletebycopy(node *&curr)
{
	node *prev,*temp=curr;
	if(curr->right==0)
		curr=curr->left;
	else if(curr->left==0)
		curr=curr->right;
	else
	{
		temp=curr->left;
		prev=curr;
		while(temp->right!=0)
		{
			prev=temp;
			temp=temp->right;
		}
		curr->value=temp->value;
		if(prev==curr)
			prev->left=temp->left;
		else
			prev->right=temp->left;
	}
}

void BST::displaylevel()
{
	if(root)
	{
		node* curr=root;
		queue<node*> q;
		q.push(curr);
		while(!q.empty())
		{
			curr=q.front();
		    q.pop();
		    if(curr->left!=0)
		    {
		    	q.push(curr->left);
			}
			if(curr->right!=0)
			{
				q.push(curr->right);
			}
			cout<<curr->value<<" ";
		}
	}
	cout<<endl;
}

void BST::preorderdisplay(node *ptr)
{
	if(ptr)
	{
		cout<<ptr->value<<" ";
		preorderdisplay(ptr->left);
		preorderdisplay(ptr->right);
	}
	return;
}

void BST::inorderdisplay(node *ptr)
{
	if(ptr)
	{
		inorderdisplay(ptr->left);
		cout<<ptr->value<<" ";
		inorderdisplay(ptr->right);
	}
	return;
}

void BST::postorderdisplay(node *ptr)
{
	if(ptr)
	{
		postorderdisplay(ptr->left);
		postorderdisplay(ptr->right);
		cout<<ptr->value<<" ";
	}
	return;
}

int BST::height(node* ptr)
{
	if(!ptr)
	{
		return 0;
	}
	int l=height(ptr->left);
	int r=height(ptr->right);
	
	if(l>r)
	{
		return l+1;
	}
	else
	{
		return r+1;
	}
}

node* BST::Root()
{
	if(root!=0)
	{
		return (root);
	}
	else
	{
		return 0;
	}
}

int main()
{
	BST b;
	b.insert(15);
	b.insert(8);
	b.insert(18);
	b.insert(12);
	b.insert(17);
	b.insert(5);
	b.insert(3);
	b.insert(9);
	b.insert(16);
	b.insert(21);
	b.displaylevel();
	b.preorderdisplay(b.Root());
	cout<<endl;
	b.inorderdisplay(b.Root());
	cout<<endl;
	b.postorderdisplay(b.Root());
	cout<<endl;
	b.findand_deletebycopy(12);
	b.findand_deletebycopy(8);
	b.findand_deletebymerge(9);
	b.findand_deletebymerge(21);
	b.displaylevel();
	cout<<"Height of tree: "<<b.height(b.Root());	
}
