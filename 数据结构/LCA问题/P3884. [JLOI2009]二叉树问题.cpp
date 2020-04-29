#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=101;
const int MAXK=21;
struct Edge
{
	int u;
	int v;
	int nxt;
};
Edge edge[MAXN<<1];
int h[MAXN],f[MAXN][MAXK],dep[MAXN],buc[MAXN],n,tot,distu,distv;
bool vis[MAXN];
void addedge(int u,int v,int pos)
{
	edge[pos].u=u;
	edge[pos].v=v;
	edge[pos].nxt=h[u];
	h[u]=pos;
}
void init()
{
	cin>>n;
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		addedge(u,v,++tot);
		addedge(v,u,++tot);
	}
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
		//cout<<u<<" "<<v<<" "<<dep[v]<<endl;
		f[v][0]=u;
		dfs(v);
	}
}
void found()
{
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<" "<<dep[i]<<endl;
		buc[dep[i]]++;
		maxx=max(dep[i],maxx);
	}
	cout<<maxx+1<<endl;
	int mmax=0;
	for(int i=0;i<=maxx;i++)
	{
		mmax=max(buc[i],mmax);
	}
	cout<<mmax<<endl;
}
void lca(int u,int v)
{
	if(dep[v]>dep[u])
	{
		swap(u,v);
	}
	int t=dep[u]-dep[v];
	for(int i=0;i<=20;i++)
	{
		if(t&(1<<i))//t的第i位（二进制）是否是零
		{
			u=f[u][i];
			distu+=(1<<i);
		 } 
	}
	if(u==v)
	{
		return ;
	}
	for(int i=20;i>=0;i--)
	{
		if(f[u][i]!=f[v][i])
		{
			u=f[u][i];
			v=f[v][i];
			distu+=(1<<i);
			distv+=(1<<i);
		}
	}
	distu++;
	distv++;
}
int main()
{
	init();
	dfs(1);
	found();
	int a,b;
	cin>>a>>b;
	lca(a,b);
	if(dep[a]>dep[b])
	{
		cout<<distu*2+distv<<endl;
	}
	else
	{
		cout<<distv*2+distu<<endl;
	}
	return 0;
}
