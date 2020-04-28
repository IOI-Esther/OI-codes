#include <cstdio>
#include <iostream> 
using namespace std;
int top=0;
int main()
{
	char ch;
	while(scanf("%c",&ch))
	{
		if(ch=='@')
		{
			break;
		}
		else if(ch=='(')
		{
			top++;
		}
		else if(ch==')')
		{
			top--;
		}
		cout<<top<<" "<<ch<<endl;
		if(top<0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(top!=0)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
	}
	return 0;
}
