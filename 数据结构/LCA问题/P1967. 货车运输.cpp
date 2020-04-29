#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF=2147483647;
const int MAXN=10010;
int n,m,s,tot,tot2;
int f[MAXN][21],h[MAXN],dep[MAXN],r[MAXN],d[MAXN][21];
struct Edge
{
	int u;
	int v;
	int w;
	int nxt;
};
Edge edge[MAXN<<1],edge2[1000001];
bool vis[MAXN];
void addedge(int u,int v,int w)
{
	tot++;
	edge[tot].u=u;
	edge[tot].v=v;
	edge[tot].w=w;
	edge[tot].nxt=h[u];
	h[u]=tot;
}
bool cmp(Edge x,Edge y)
{
	return x.w>y.w;
}
void init()
{
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		edge2[i].u=u;
		edge2[i].v=v;
		edge2[i].w=w;
	}
	sort(edge2+1,edge2+m+1,cmp);
	memset(d,0x7f,sizeof(d));
}
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
//	cout<<u<<" "<<v<<" ";
	int r1=find(u);
//	cout<<r1<<" ";
	int r2=find(v);
//	cout<<r2<<endl;
	return (r1==r2);
}
int kruskal()
{
	for(int i=1;i<=n;i++)
	{
		r[i]=i;
	}
	int mst=0,cnt=0;
	for(int i=1;i<=m;i++)
	{
		int u=edge2[i].u;
		int v=edge2[i].v;
		int w=edge2[i].w;
		if(judge(u,v))
		{
			continue;
		}
		uni(u,v);
		cnt++;
		addedge(u,v,w);
		addedge(v,u,w);
		mst+=w;
		if(cnt==n-1)
		{
			break;
		}
	}
	return mst;
}
void dfs(int u)
{
	vis[u]=true;
	for(int i=1;i<=20;i++)
	{
		if(dep[u]<(1<<i))
		{
			break;
		}
		f[u][i]=f[f[u][i-1]][i-1];
		d[u][i]=min(d[u][i-1],d[f[u][i-1]][i-1]);
	}
	for(int i=h[u];i;i=edge[i].nxt)
	{
		int v=edge[i].v;
		int w=edge[i].w;
		if(vis[v])
		{
			continue;
		}
		dep[v]=dep[u]+1;
		f[v][0]=u;
		d[v][0]=w;
		dfs(v);
	}
}
int lca(int u,int v)
{
	if(dep[v]>dep[u])
	{
		swap(u,v);
	}
	int t=dep[u]-dep[v],val=INF;
	for(int i=0;i<=20;i++)
	{
		if(t&(1<<i))//t的第i位（二进制）是否是一 
		{
			//cout<<u<<" "<<v<<endl;
			//cout<<val<<endl;
			val=min(val,d[u][i]);
			u=f[u][i];
		}
	}
	if(u==v)
	{
		return val;
	}
	for(int i=20;i>=0;i--)
	{
		if(f[u][i]!=f[v][i])
		{
	//		cout<<u<<" "<<v<<endl;
			val=min(val,d[u][i]);
			val=min(val,d[v][i]);
			u=f[u][i];
			v=f[v][i];
		}
	}
	val=min(val,d[u][0]);
	val=min(val,d[v][0]);
	u=f[u][0];
	//cout<<u<<" "<<v<<endl; 
	return val;
}
void query()
{
	int a,b,q;
	scanf("%d",&q);
	//cout<<"-----------------------"<<endl;
	//cout<<lca(1,3)<<endl;
	//cout<<"-----------------------"<<endl;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		if(!judge(a,b))
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",lca(a,b));
	}
}
int main()
{
	init();
//	cout<<1<<endl;
	kruskal();
//	cout<<2<<endl;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
//	for(int i=1;i<=tot;i++)
//	{
//		cout<<edge[i].u<<" "<<edge[i].v<<endl;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=20;j++)
//		{
//			cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<d[i][j]<<endl;
//		}
//	 } 
//	cout<<3<<endl;
	query();
	return 0;
}
