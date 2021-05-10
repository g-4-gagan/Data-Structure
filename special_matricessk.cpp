#include<iostream>
#include<stdio.h>
#include<stdexcept>
#include<iomanip>
using namespace std;

class illegalParameterValue
{
	public:
		illegalParameterValue(string msg)
		{
			cout<<"\nError: "<<msg;
		}
};
class matrixIndexOutOfBounds
{
	public:
		matrixIndexOutOfBounds(string msg)
		{
			cout<<"\nError: "<<msg;
		}
};
class incorrect_position{
	public:
		incorrect_position(string msg)
		{
			cout<<"\nError: "<<msg;
		}
};
template<class T>
class symmetric_matrix
{
	public: 
	symmetric_matrix(int theN=10);
	symmetric_matrix(){delete [] element;}
	void input();
	void display2D();	
	T get(int,int)const;
	void set(int,int,const T&);
private:
	int n;
	T *element;
};
template<class T>
class  diagonalmatrix
{
	public:
		diagonalmatrix(int theN=10);
		~diagonalmatrix()
		{
			delete[] element;
		}
		T get(int,int)const;
		void set(int,int,const T&);
		int theN;
		T* element;
		void display2D();
		void display1D();
		void input(T theN);
		
};
template<class T>
class upperTriangularMatrix
{
public: 
	upperTriangularMatrix(int theN=10);
	~upperTriangularMatrix(){delete [] element;}
	void input();
	void display2D();
	void display1D();	
	T get(int,int)const;
	void set(int,int,const T&);
private:
	int n;
	T *element;
};
template<class T>
class lowerTriangularMatrix
{
public: 
	lowerTriangularMatrix(int theN=10);
	~lowerTriangularMatrix(){delete [] element;}
	void input();
	void display2D();
	void display1D();	
	T get(int,int)const;
	void set(int,int,const T&);
private:
	int n;
	T *element;
};
template<class T>
T diagonalmatrix<T>::get(int i, int j) const						// Return (i,j)th element of matrix
{															// validate i and j
	if (i < 1 || j < 1 || i > theN || j > theN)
	throw matrixIndexOutOfBounds("Invalid dimensions");
	
	if (i == j)
	 	return element[i-1]; 					  // diagonal element		
	else
	 	return 0;								 // nondiagonal element
}
template<class T>
diagonalmatrix<T>::diagonalmatrix(int theN)
{
     if (theN<1)
		throw illegalParameterValue("Size must be greater than equal to 1");
	this->theN=theN;
	 element=new T[theN];
	 for(int i=0;i<theN;i++)
	   element[i]=0;
}

template<class T>
void diagonalmatrix<T>:: set(int i,int j,const T& newValue)
{
	if(i<1||j<1||i>theN||j>theN)
	  throw matrixIndexOutOfBounds("Invalid dimension");
	if(i==j)
	   element[i-1]=newValue;
	else
	  if(newValue!=0)
	    throw illegalParameterValue("Non diagonal element must be zero");  
}
template<class T>
void diagonalmatrix<T>::display2D()   
{	 
     cout<<"\nThe entered matrix is: \n";			 														     
	 for(int i=1;i<=theN;i++)
	 {
	   for(int j=1;j<=theN;j++)
	   {
	 	 if(i==j)
	 	  cout<<element[i-1]<<" ";
		 else
		  cout<<"0"<<" ";	 	
	   }
	 	cout<<endl;
	 }
} 
template<class T>
void diagonalmatrix<T>::display1D()   
{	
    cout<<"\nThe element  matrix in 1D (with diagonal elements only): ";
	cout<<"{";		 														     
	for(int i=0;i<theN;i++)
	 	if(i == theN-1)
	 		cout<<element[i]<<"}";
	 	else
	 		cout<<element[i]<<" , ";
}
template<class T>
void diagonalmatrix<T>:: input(T theN)
{	
    cout<<"\nEnter elements for diagonal only:\n ";
	this->theN = theN;
	for(int i=0;i<theN;i++)
	cin>>this->element[i];
	cout<<endl;
}

template<class T>
symmetric_matrix<T>::symmetric_matrix(int theN)
{
	if(theN<1)
		throw incorrect_position("Matrix size must be greater than 0 ");
	n=theN;
	element=new T[(n*(n+1))/2];
	int l = (n*(n+1))/2;
	for(int i=0;i<l;i++)
		element[i]=0;
}
template<class T>		
void symmetric_matrix<T>::set(int i, int j, const T& newValue)
    {
        if(i<0 || j<0 || i>n || j>n)
        {
            throw matrixIndexOutOfBounds("Invalid input \n");
        }
	 else
        {
            if(i>=j)
            element[ (i*(i-1))/2+ (j-1)]=newValue;
        }
}
template<class T>
T symmetric_matrix<T>::get(int i,int j)const
{
	  if(i<=0 || j<=0 || i>n || j>n)
        {
            throw matrixIndexOutOfBounds("\nOut of bounds!\n");
        }
        else
        {
            if(i>=j)
                cout<<"\nValue= "<<element[ (i*(i-1))/2+ (j-1)];
            else if(i<j)
            {
                swap(i,j);
                cout<<"\nValue= "<<element[ (i*(i-1))/2+ (j-1)];
            }
            else
                cout<<"incorrect position";
        }
}

template<class T>
void symmetric_matrix<T>:: display2D()
{
	  int i=1, j=1;
        while(i<=n)
        {
            j=1;
            while(j<=n)
            {
                if(i>=j)
                    cout<<setw(2)<<element[ (i*(i-1))/2+ (j-1)]<<" ";
                else if(i<j)
                {
                    swap(i,j);
                    cout<<setw(2)<<element[ (i*(i-1))/2+ (j-1)]<<" ";
                    swap(i,j);
                }
                else
                    cout<<setw(2)<<"0";
                j++;
            }
            cout<<endl;
            i++;
        }
}
template<class T>
void symmetric_matrix<T>:: input()
 {
 	cout<<"Enter the elements for symmetric matrix :\n";
 	for(int i=0;i<(n*(n+1)/2);i++)
 		cin>>element[i];
 }

template<class T>
upperTriangularMatrix<T>::upperTriangularMatrix(int theN)
{
	if(theN<1)
		throw incorrect_position("Matrix size must be greater than 0 ");
	n=theN;
	element=new T[(n*(n+1))/2];
}		
template<class T>
T upperTriangularMatrix<T>::get(int i,int j)const
{
if(i<1||j<1||i>n||j>n)
	throw matrixIndexOutOfBounds("Invalid argument \n");
if(i<=j)
	return element[((j*(j-1))/2)+(i-1)];
else 
	return 0;
}
template<class T>
void upperTriangularMatrix<T>::set(int i,int j,const T& newValue)
{
	if(i<1||j<1||i>n||j>n)
		throw matrixIndexOutOfBounds("Invalid input \n");
	if(i<=j)
		element[((j*(j-1))/2)+(i-1)]=newValue;
	else
		if(newValue!=0)
			throw incorrect_position("non upper Triangular elements must be 0");
}
 template<class T>
 void upperTriangularMatrix<T>:: display2D()
 {
 	for (int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=n;j++)
 		{
 			if(i<=j)
 				cout<<this->element[((j*(j-1))/2)+(i-1)]<<" ";
 			else
 				cout<<"0 ";
		 }
		 cout<<endl;
	 }
 	
 	cout<<endl;
 }
template<class T>
void upperTriangularMatrix<T>::display1D()   
{	
	int l;
	l = n*(n+1)/2;
    cout<<"\nThe element  matrix in 1D (with upper diagonal elements only):\n";
	cout<<"{";		 														     
	for(int i=1;i<=l;i++)
	 	if(i>=l)
	 		cout<<element[i-1]<<"}";
	 	else
	 		cout<<element[i-1]<<",";
	 		cout<<endl;
}
template<class T>
void upperTriangularMatrix<T>:: input()
 {
 	cout<<"Enter the elements for upper triangular matrix :\n";
 	for(int i=0;i<(n*(n+1)/2);i++)
 		cin>>element[i];
 }
 
template<class T>
lowerTriangularMatrix<T>::lowerTriangularMatrix(int theN)
{
	if(theN<1)
		throw incorrect_position("Matrix size must be greater than 0 ");
	n=theN;
	element=new T[(n*(n+1))/2];
}		
template<class T>
T lowerTriangularMatrix<T>::get(int i,int j)const
{
if(i<1||j<1||i>n||j>n)
	throw matrixIndexOutOfBounds("Invalid argument \n");
if(i<=j)
	return element[((j*(j-1))/2)+(i-1)];
else 
	return 0;
}
template<class T>
void lowerTriangularMatrix<T>::set(int i,int j,const T& newValue)
{
	if(i<1||j<1||i>n||j>n)
		throw matrixIndexOutOfBounds("Invalid input \n");
	if(i<=j)
		element[((j*(j-1))/2)+(i-1)]=newValue;
	else
		if(newValue!=0)
			throw incorrect_position("non lower Triangular elements must be 0");
}
 template<class T>
 void lowerTriangularMatrix<T>:: display2D()
 {
 	for (int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=n;j++)
 		{
 			if(i<=j)
 				cout<<this->element[((j*(j-1))/2)+(i-1)]<<" ";
 			else
 				cout<<"0 ";
		 }
		 cout<<endl;
	 }
 	
 	cout<<endl;
 }
template<class T>
void lowerTriangularMatrix<T>::display1D()   
{	
	int l;
	l = n*(n+1)/2;
    cout<<"\nThe element  matrix in 1D (with lower diagonal elements only):\n";
	cout<<"{";		 														     
	for(int i=1;i<=l;i++)
	 	if(i>=l)
	 		cout<<element[i-1]<<"}";
	 	else
	 		cout<<element[i-1]<<",";
	 		cout<<endl;
}
template<class T>
void lowerTriangularMatrix<T>:: input()
 {
 	cout<<"Enter the elements for lower triangular matrix :\n";
 	for(int i=0;i<(n*(n+1)/2);i++)
 		cin>>element[i];
 }
int main()
{
	int n,i,j,x,y;
	
	cout<<"\nEnter the size of the matrix: ";
	cin>>n;
	diagonalmatrix<int> m1(n);
	symmetric_matrix<int> obj(n);
	lowerTriangularMatrix<int> ob(n);
	upperTriangularMatrix<int> o(n);
	int choice;
	char ch;
	try
	{
	    do
		{ cout<<"\n========================================================";
		  cout<<"\nMENU ";
		  cout<<"\n========================================================";
		  cout<<"\n1.DIAGONAL MATRIX \n2.SYMMETRIC MATRIX \n3.LOWER TRIANGULAR MATRIX\n4.UPPER TRIANGULAR MATRIX:\n ";
		  cout<<"\n Enter your choice :";
		  cin>>choice;
		  switch(choice)
		 {
			case 1: 
					do{
					m1.input(n);
					m1.display2D();
					m1.display1D();
					char c;
					cout<<"\n MENU \na. Get\nb.Set\n c. Enter your choice :";
					cin>>c;
					switch(c)
					{
					case 'a':
								cout<<"\nget function\n";
		        				cout<<"\nEnter the position for which you want value(i,j): ";
		        				cin>>i>>j;
		        				x=m1.get(i,j);
		       		 			cout<<"\nThe value is:"<<x;
		        			    break;
				    
					case 'b':
								cout<<"\nset function\n";
		      					cout<<"\nIf you want to change any diagonal value enter the (i,j)th position";
		      					cout<<"\n i: ";
		      					cin>>i;
		      					cout<<"\nj: ";
		      					cin>>j;
		     					cout<<"\nNewvalue: ";
		    					cin>>y;
		     					m1.set(i,j,y);
		     					cout<<"\nThe new matrix with changed value is:\n ";
		     					m1.display2D();
			 					m1.display1D();
		     				break;
		     				
		     		default:
								cout<<"Wrong Choice!!\n";	
								exit(0);
							break;
											}
						cout<<"\nPress y to continue:";
		  		 		cin>>ch;
						 }while(ch=='y'); 
		     			break;
		    
		    case 2:
		   				do{
						obj.input();
						obj.display2D();
						char w;
						cout<<"\nMenu:\na.SET\nb.GET\nc.Display\n";
						cout<<"Enter you choice : ";
						cin>>w;
						switch(w)
						{
							case 'a':
										cout<<"\nSET FUNCTION:\n";
										cout<<"Enter position :\n ";
										cin>>i>>j;
										cout<<"Enter the element you want to set at (i,j) :";
										cin>>y;
										obj.set(i,j,y);
										cout<<"\nThe new matrix after changed:\n";
										obj.display2D();
										break;
							case 'b':
										cout<<"\nGET FUNCTION:\n";
										cout<<"Enter the element you want(i,j): ";
										cin>>i>>j;
										x=obj.get(i,j);
										break;
							case 'c':
										cout<<"The matrix is:\n";
										obj.display2D();
										break;
										
							default:
										cout<<"Wrong Choice!!\n";	
										exit(0);
										break;
									}
						cout<<"\nPress y to continue:";
		  		 		cin>>ch;
						 }while(ch=='y'); 
					 break;
					
						
			case 3:
					do{
						ob.input();
						ob.display2D();
						ob.display1D();
						char k;	
						
						cout<<"\nMenu:\na.SET\nb.GET\nc.Display\n";
						cout<<"Enter you choice : ";
						cin>>k;
					switch(k)
					{
						case 'a':
								cout<<"\nSET FUNCTION:";
								cout<<endl;
								cout<<"Enter the element you want to set at (i,j) : ";
								cout<<endl;
								cout<<"Enter position : ";
								cin>>i>>j;
								cout<<"Enter the element : ";
								cout<<endl;
								cin>>y;
								ob.set(i,j,y);
								cout<<"\nThe new matrix after changed:\n";
								ob.display2D();
								ob.display1D();
								break;
						case 'b':
								cout<<"\nGET FUNCTION:\n";
								cout<<"Enter the element you want(i,j): ";
								cin>>i>>j;
								x=ob.get(i,j);
								cout<<"The Element is : "<<x<<endl;
								break;
						case 'c':
								cout<<"the matrix is:\n";
								ob.display2D();
								ob.display1D();
								break;
								
						default:
								cout<<"Wrong Choice!!\n";	
								exit(0);
								break;
					}
								
						cout<<"\nPress y to continue:";
		  		 		cin>>ch;
						 }while(ch=='y'); 
				break;
				
					
			case 4:
					do{
						o.input();
						o.display2D();
						o.display1D();
						char h;
						cout<<"\nMenu:\na.SET \nb.GET \nc.Display \n";
						cout<<"Enter you choice : ";
						cin>>h;
						switch(h)
					{
					case 'a':
								cout<<"\nSET FUNCTION:";
								cout<<endl;
								cout<<"Enter the element you want to set at (i,j) : ";
								cout<<endl;
								cout<<"Enter position : ";
								cin>>i>>j;
								cout<<"Enter the element : ";
								cout<<endl;
								cin>>y;
								o.set(i,j,y);
								cout<<"\nThe new matrix after changed:\n";
								o.display2D();
								o.display1D();
								break;
					case 'b':
								cout<<"\nGET FUNCTION:\n";
								cout<<"Enter the element you want(i,j): ";
								cin>>i>>j;
								x=o.get(i,j);
								cout<<"The Element is : "<<x<<endl;
								break;
					case 'c':
								cout<<"The matrix is:\n";
								o.display2D();
								o.display1D();
								break;
								
					default:
								cout<<"Wrong Choice!!\n";	
								exit(0);
								break;
								}
										
						cout<<"\nPress y to continue:";
		  		 		cin>>ch;
						 }while(ch=='y'); 
						 break;	
							
		    
			default: cout<<"\nWrong choice\n";
		         	 exit(0);
		         	 break;
		 }  
		   		cout<<"\nPress y to continue:";
		  		 cin>>ch;
		 }while(ch=='Y');  
    }
    catch(illegalParameterValue e)
	 {
	 	 exit(0);
	 }
	 catch(matrixIndexOutOfBounds e)
	 {
	 	exit(0);
	 } 
	return 0;
}
