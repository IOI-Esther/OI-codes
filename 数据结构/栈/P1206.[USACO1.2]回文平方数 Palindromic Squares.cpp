#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;
int b;
char Change(int k)
{
	if(k<10)
	{
		return k+'0';
	}
	return k-10+'A';
}
string Convert(int n)
{
	string num;
	stack<int> tmp;
	while(n)
	{
		tmp.push(n%b);
		n/=b;
	}
	while(!tmp.empty())
	{
		num.push_back(Change(tmp.top()));
		tmp.pop();
	}
	return num;
}
bool Palind(string s)
{
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin>>b;
	for(int i=1;i<=300;i++)
	{
		string squ=Convert(i*i);
		if(Palind(squ))
		{
			cout<<Convert(i)<<" "<<squ<<endl;
		}
	}
	return 0;
}
