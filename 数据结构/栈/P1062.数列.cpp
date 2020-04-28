#include <iostream>
#include <stack>
using namespace std;
void DectoBin(int n,stack<bool> &s)
{
	while(n)
	{
		s.push(n%2);
		n/=2;
	}
}
long long RtoDec(stack<bool> s,int r)
{
	long long decn=0;
	while(!s.empty())
	{
		bool w=s.top();
		s.pop();
		decn*=r;
		decn+=w;
	}
	return decn;
}
int main()
{
	int k,n;
	cin>>k>>n;
	stack<bool> s;
	DectoBin(n,s);
	cout<<RtoDec(s,k)<<endl;
	return 0;
}
