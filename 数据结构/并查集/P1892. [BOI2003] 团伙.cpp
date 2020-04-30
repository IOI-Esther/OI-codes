#include <iostream>
#include <string>
using namespace std;
const int N=1005;
int r[2*N];
int n,m;
string str;
int find(int u)
{
	if(r[u]!=u)
	{
		r[u]=find(r[u]);
	}
	return r[u];
}
void unionn(int u,int v)
{
	int r1=find(u);
	int r2=find(v);
	if(r1!=r2)
	{
		r[r2]=r1;
	}
}
void init()
{
	for(int i=1;i<=2*n;i++)
	{
		r[i]=i;
	}
}
int main()
{
	cin>>n>>m;
	init();
	int u,v;
	for(int i=1;i<=m;i++)
	{
		cin>>str>>u>>v;
		if(str[0]=='F')
		{
			unionn(u,v);
		}
		else if(str[0]=='E')
		{
			unionn(u,v+n);
			unionn(v,u+n);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(r[i]==i)
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
