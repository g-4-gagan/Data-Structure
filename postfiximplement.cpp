#include<iostream>
#include<stack>
#include<string>
#include<math.h>
#include<ctype.h> 
#include <bits/stdc++.h>
using namespace std;

int convert(string s)
{  
  
   int x= 0;
 

	for(int i=0;i<s.length();i++)
	{
		 x =x*10 + (int)(s[i]-'0');
	
	}
	return x;
}

int main()
{
	stack <int> s;
	string str,t;
	int n,x;
	cout<<"Input the postfix expression with spaces between different terms: \n";
	getline(cin,str);
	stringstream X(str);
	n = str.length();
	while(getline(X,t,' '))
	{
		int temp = 0;
		int num=0;
		if(isdigit(t[0]))
		{
			num = convert(t);
			s.push(num);
		}
		else
		{
			switch(t[0])
		   {
			case '+':
				temp = s.top();
				s.pop();
				temp += s.top();
				s.pop();
				s.push(temp);
				break;
			case '-':
				temp = s.top();
				s.pop();
				temp = s.top()-temp;
				s.pop();
				s.push(temp);
				break;
			case '/':
				temp = s.top();
				s.pop();
				temp = s.top()/temp;
				s.pop();
				s.push(temp);
				break;
			case '*':
				temp = s.top();
				s.pop();
				temp *= s.top();
				s.pop();
				s.push(temp);
				break;
			case '^':
				temp = s.top();
				s.pop();
				temp = pow(s.top(),temp);
				s.pop();
				s.push(temp);
				break;
			default:
			    cout<<"Undefined character";
			    return -1;
				break;			
		   }
		}
		
	}
	cout<<"The Result of the Expression is: "<<s.top();	
	return 0;
}
