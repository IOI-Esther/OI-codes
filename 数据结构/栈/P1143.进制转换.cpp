#include <iostream>
#include <string>
#include <stack>
using namespace std;
string num;
int convert(string num,int r)
{
	int n=0,s=1;
	int len=num.length();
	for(int i=len-1;i>=0;i--)
	{
		if(num[i]<='F'&&num[i]>='A')
		{
			n+=(num[i]-'A'+10)*s;
			s*=r;
		}
		else
		{
			n+=(num[i]-'0')*s;
			s*=r;
		}
	}
	return n;
}
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
	int oldr,newr;
	cin>>oldr;
	cin>>num;
	cin>>newr;
	int n=convert(num,oldr);
	//cout<<n<<endl; 
	int lenn=num.length();
	work(n,newr);
	return 0;
}
