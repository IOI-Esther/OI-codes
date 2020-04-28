#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
int n,s,sum;
char Change(int k)
{
	if(k<10)
	{
		return k+'0';
	}
	return k-10+'A';
}
string Convert(int b,int n)
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
	cin>>n>>s;
	for(int i=s+1;sum<n;i++)
	{
		int cnt=0;
		for(int j=2;j<=10;j++)
		{
			if(Palind(Convert(j,i)))
			{
				cnt++;
			}
			if(cnt>=2)
			{
				sum++;
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
