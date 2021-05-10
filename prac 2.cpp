#include<iostream>
using namespace std;

void print(int ar[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<ar[i]<<" ";		
	}	
}

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x);
			 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return -1; 
} 

int main()
{
	int *ar;
	int size,search,pos;
	cout<<"please enter size: ";
	cin>>size;
	ar = new int[size];
	cout<<"please enter the values \n";
	for(int i = 0;i<size;i++)
	{
		int a;
		bool flag=true;
		cin>>a;
		for(int j=i-1;j>=0;j--)
		{
			if(a==ar[j])
			{
				i--;
				cout<<"entered value is duplicate hence not considered!!\n";
				flag=false;
				break;
			}
		}
		if(i>0 && a < ar[i-1])
		{
			i--;
			cout<<"entered value is lower hence not considered!!\n";
			flag=false;
		}
		if(flag)
		{
			ar[i]=a;
		}
	}
	cout<<"The entered values are: \n";
	print(ar,size);
	cout<<endl;
	cout<<"Enter the integer to be searched: ";
	cin>>search;
	pos= binarySearch(ar, 0, size-1, search);
	cout<<"The searched element ia at index: "<<pos<<endl;
}
