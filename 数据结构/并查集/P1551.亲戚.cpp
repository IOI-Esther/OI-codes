#include <iostream>
#include <cstdio>
using namespace std;
int r[20001];
int n,m,q;
int find(int u)
{
	if(r[u]!=u)
	{
		r[u]=find(r[u]);
	}
	return r[u];
}
void uni(int u,int v)
{
	int r1=find(u);
	int r2=find(v);
	if(r1!=r2)
	{
		r[r2]=r1;
	}
}
bool judge(int u,int v)
{
	int r1=find(u);
	int r2=find(v);
	return (r1==r2);
}
int main()
{
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		r[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		uni(u,v);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&u,&v);
		if(judge(u,v))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
