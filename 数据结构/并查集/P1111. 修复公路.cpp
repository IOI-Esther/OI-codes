#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN=1005;
const int MAXM=100005;
struct Edge
{
	int u;
	int v;
	int t;
};
Edge e[MAXM];
int r[MAXN];
int n,m,tot;
bool cmp(Edge x,Edge y)
{
	return x.t<y.t;
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
	int r1=find(u);
	int r2=find(v);
	return (r1==r2);
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		r[i]=i;
	}
	tot=n;
}
int main()
{
	int x,y,t;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&t);
		e[i].u=x;
		e[i].v=y;
		e[i].t=t;
	}
	init();
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u;
		int v=e[i].v;
		int t=e[i].t;
		if(judge(u,v))
		{
			continue ;
		}
		uni(u,v);
		tot--;
		if(tot==1)
		{
			printf("%d\n",t);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
