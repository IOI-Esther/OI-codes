#include <iostream>
#include <cstring>
using namespace std;
int g[1001][1001];
int f[1001][1001];
int n,tmp;
void floyd(int m,int n)
{
	for(int k=m;k<=n;k++)
	{
		for(int i=m;i<=n;i++)
		{
			for(int j=m;j<=n;j++)
			{
				f[i][j]=f[j][i]=f[i][j]||(f[i][k]&&f[j][k]);
			}
		}
	}
}
int main()
{
	cin>>n;
	int v;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		for(int j=1;j<=tmp;j++)
		{
			cin>>v;
			g[i][v]=true;
			g[v][i]=true;
		}
		g[i][i]=true;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=i;k<=n;k++)
			{
				f[i][j]=g[i][j];
			}
		}
		floyd(i+1,n);
		for(int j=i;j<=n;j++)
		{
			for(int k=i;k<=n;k++)
			{
				cout<<f[i][j]<<" ";
			}
			cout<<endl;
		}
		for(int j=i;j<=n;j++)
		{
			for(int k=i;k<=n;k++)
			{
				if(!f[k][j])
				{
					cout<<i-1<<endl;
					return 0;
				}
			}
		} 
	}
	return 0;	
} 
