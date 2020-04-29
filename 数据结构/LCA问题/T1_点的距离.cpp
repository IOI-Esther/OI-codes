#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=500010;
int n,q,tot;
int f[MAXN][21],h[MAXN],dep[MAXN];
struct Edge
{
	int v;
	int nxt;
};
Edge edge[MAXN<<1];
bool vis[MAXN];
void addedge(int u,int v)
{
	tot++;
	edge[tot].v=v;
	edge[tot].nxt=h[u];
	h[u]=tot;
}
void dfs(int u)
{
	vis[u]=1;
	for(int i=1;i<=20;i++)
	{
		if(dep[u]<(1<<i))
		{
			break;
		}
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=h[u];i;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(vis[v])
		{
			continue;
		}
		dep[v]=dep[u]+1;
		f[v][0]=u;
		dfs(v);
	}
}
int lca(int u,int v)
{
	if(dep[v]>dep[u])
	{
		swap(u,v);
	}
	int t=dep[u]-dep[v];
	int sum=0;
	for(int i=0;i<=20;i++)
	{
		if(t&(1<<i))//t的第i位（二进制）是否是零
		{
			u=f[u][i];
		 } 
	}
	sum+=t;
	if(u==v)
	{
		return sum;
	}
	for(int i=20;i>=0;i--)
	{
		if(f[u][i]!=f[v][i])
		{
			u=f[u][i];
			v=f[v][i];
			sum+=2*(1<<i);
		}
	}
	return sum+2;
}
void query()
{
	int a,b;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
}
int main()
{
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1);
	query();
	return 0;
}
