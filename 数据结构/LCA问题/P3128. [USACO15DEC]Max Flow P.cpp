#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int read()
{
	int num=0,f=1;char ch;
	while(1){ch=getchar();	if(ch=='-' || isdigit(ch)) break;}
	if(ch=='-')	f=-1;else num=ch-'0';
	while(1){ch=getchar();	if(!isdigit(ch)) break; num*=10;	num+=ch-'0';}
	return num*f;
}

const int MAXN=100005;
const int TREEROOT=1;
const int ADDVALUE=1;
struct Edge
{
	int v;
	int nxt;
};
struct Node
{
	int fa[101];
	int first;
	int depth;
	int delta;
	bool visID;
	bool visCD;
	int sum;
};
Edge edge[MAXN];
Node node[MAXN];
int tot;

void addEdge(int u,int v)
{
	tot++;
	edge[tot].v=v;
	edge[tot].nxt=node[u].first;
	node[u].first=tot;
 } 

void initDfs(int u)
{
	node[u].visID=true;
	node[u].delta=0;
	for(int i=1;i<=20;i++)
	{
		if(node[u].depth<(1<<i))
		{
			break;
		}
		node[u].fa[i]=node[node[u].fa[i-1]].fa[i-1];
	}
	for(int i=node[u].first;i;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(node[v].visID)
		{
			continue;
		}
		node[v].depth=node[u].depth+1;
		node[v].fa[0]=u;
		initDfs(v);
	}
}

int getLca(int u,int v)
{
	if(node[v].depth>node[u].depth)
	{
		swap(u,v);
	}
	int t=node[u].depth-node[v].depth;
	for(int i=0;i<=20;i++)
	{
		if(t&(1<<i))
		{
			u=node[u].fa[i];
		}
	}
	if(u==v)
	{
		return u;
	}
	for(int i=20;i>=0;i--)
	{
		if(node[u].fa[i]!=node[v].fa[i])
		{
			u=node[u].fa[i];
			v=node[v].fa[i];
		}
	}
	return node[u].fa[0];
}

void diff(int u,int v,int c)
{
	node[u].delta+=c;
	node[v].delta+=c;
	int lca=getLca(u,v);
	node[lca].delta-=c;
	node[node[lca].fa[0]].delta-=c;
}

int countDfs(int u)
{
	node[u].visCD=true;
	int sum=0;
	for(int i=node[u].first;i;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(node[v].visCD)
		{
			continue;
		}
		sum+=countDfs(v);
	}
	return node[u].sum=sum+node[u].delta;
}

int findMax(int n)
{
	int maxFlow=0;
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<" "<<node[i].sum<<endl;
		maxFlow=max(maxFlow,node[i].sum);
	}
	return maxFlow;
}

int main()
{
	int n=read(),k=read();
	int x,y;
	for(int i=1;i<n;i++)
	{
		x=read();
		y=read();
		addEdge(x,y);
		addEdge(y,x);
	}
	initDfs(TREEROOT);
	int s,t;
	for(int i=1;i<=k;i++)
	{
		s=read();
		t=read();
		diff(s,t,ADDVALUE);
	}
	countDfs(TREEROOT);
	cout<<findMax(n)<<endl;
	return 0;
 } 
