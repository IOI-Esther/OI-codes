#include <iostream>
#include <stack>
using namespace std;
stack<bool> op;
stack<unsigned long long> val;
char ch;
//*:0 ; +:1;
void calc()
{
	bool noop=op.top();
	op.pop();
	unsigned long long va1=val.top();
	val.pop();
	unsigned long long va2=val.top();
	val.pop();
	if(noop)
	{
		val.push((va1+va2)%10000);
	}
	else
	{
		val.push((va1*va2)%10000);
	}
}
int main()
{
	unsigned long long t=0;
	while(cin>>ch)
	{
		if(ch=='+')
		{
			val.push(t);
			t=0;
			while(!op.empty())
			{
				calc();
			}	
			op.push(1);
		}
		else if(ch=='*')
		{
			val.push(t);
			t=0;
			while(!op.empty()&&!op.top())
			{
				calc();
			}
			op.push(0);
		}
		else
		{
			t*=10;
			t+=ch-'0';
		}
		//cout<<op.size()<<endl;
	}
	val.push(t);
	while(!op.empty())
	{
		calc();
	}
	cout<<val.top()%10000<<endl;
	return 0;
}
