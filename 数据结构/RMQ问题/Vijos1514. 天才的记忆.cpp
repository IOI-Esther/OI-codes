#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN=1000005;
const int MAXLOG=105;
int n,m;
int d[MAXN][MAXLOG];
int a[MAXN];
void st()
{
	for(int i=1;i<=n;i++)
	{
		d[i][0]=a[i];
	}
	int l=log2(n);
	for(int j=1;j<=l;j++)
	{
		for(int i=n;i>=1;i--)
		{
			d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	 } 
	 st();
	scanf("%d",&m);
	int l,r;
	for(int j=1;j<=m;j++)
	{
		scanf("%d%d",&l,&r);
		int k=log2(r-l+1);
		printf("%d\n",max(d[l][k],d[r-(1<<k)+1][k]));
	}
	return 0;
}
