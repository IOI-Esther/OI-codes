#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
string str;
stack<long long> sta;
long long jisuan(long long a,long long b,char o)
{
	switch(o)
	{ 
	case '+':
		return a+b;
	case '-':
		return a-b;
	case '*':
		return a*b;
	case '/':
		return a/b;
	} 
}
long long work()
{
	int len=str.length() ;
	long long n=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]=='.')
		{
			sta.push(n); 
			n=0;
			continue;
		}
		else if(str[i]<='9'&&str[i]>='0')
		{
			n*=10;
			n+=str[i]-'0';
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			long long v1=sta.top() ;
			sta.pop() ;
			long long v2=sta.top() ;
			sta.pop() ;
			sta.push(jisuan(v2,v1,str[i]));
		}
	} 
	return sta.top() ;
}
int main()
{
	cin>>str;
    long long value=work();
    cout<<value<<endl;
	return 0;
}
