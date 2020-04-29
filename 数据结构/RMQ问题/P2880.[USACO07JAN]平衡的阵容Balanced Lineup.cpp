#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m;
int a[100001];
int ax[100001][101];
int in[100001][101];
void first()
{
	for(int i=1;i<=n;i++)
	{
		ax[i][0]=a[i];
	}
	memset(in,0x7f,sizeof(in));
	for(int i=1;i<=n;i++)
	{
		in[i][0]=a[i];
	}
}
void dp()
{
	int l=log2(n);
	for(int j=1;j<=l;j++)
	{
		for(int i=n;i>=1;i--)
		{
			ax[i][j]=max(ax[i][j-1],ax[i+(1<<(j-1))][j-1]);
		}
	}
	for(int j=1;j<=l;j++)
	{
		for(int i=n;i>=1;i--)
		{
			in[i][j]=min(in[i][j-1],in[i+(1<<(j-1))][j-1]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	first();
	dp();
	int l,r;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		int k=log2(r-l+1);
		printf("%d\n",max(ax[l][k],ax[r-(1<<k)+1][k])-min(in[l][k],in[r-(1<<k)+1][k]));
	}
	return 0;
}
