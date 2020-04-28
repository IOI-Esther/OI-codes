#include<iostream>
#include<stack>
using namespace std;
void output(stack<int> s)
{
	while(!s.empty() )
	{
		if(s.top() <10)
			cout<<s.top() ;
		else if(s.top() >=10)
		    cout<<(char)(s.top() +'A'-10);
		s.pop() ;
	}
	cout<<endl;
}
void work(int n,int r)
{
	stack<int> s;
	while(n>0)
	{
		s.push(n%r);
		n/=r;
	}
	output(s);
}
int main()
{
	int n,r;
	cin>>n>>r;
	work(n,r);
	return 0; 
}
 
