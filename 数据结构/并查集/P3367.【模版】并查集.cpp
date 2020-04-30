#include <iostream>
#include <cstdio>
using namespace std;
//数据结构：r[i]为 i 的上层元素；n 为结点数；m 为边数； 
int r[20001];
int n,m,u,v;
//查找函数 find() 
int find(int u)
{
	//利用了代表元素（根）的 r 值为其本身的特点
	//不断递归，如果不满足上述特点则继续递归 
	if(r[u]!=u)
	{
		r[u]=find(r[u]);
	}
	return r[u];
}
//合并函数 uni()
void uni(int u,int v)
{
	//找到 r1与 r2所在集合的代表元素（根） 
	int r1=find(u);
	int r2=find(v);
	//判断是否在同一集合内（增强鲁棒性） 
	if(r1!=r2)
	{
		//将 r2挂在 r1所在集合的下面（更改父亲元素数组） 
		r[r2]=r1;
	}
}
//判定 u 与 v 是否在同一集合里 
bool judge(int u,int v)
{
	//判断两元素所在集合的代表元素（根）是否一样 
	int r1=find(u);
	int r2=find(v);
	return (r1==r2);
}
//主函数 
int main()
{
	scanf("%d%d",&n,&m);
	//初始化：默认所有结点单属于一个集合，因此代表元素（r 值）就是他自己 
	for(int i=1;i<=n;i++)
	{
		r[i]=i;
	}
	int tmp;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&tmp,&u,&v);
		if(tmp==1)
		{
			uni(u,v);
		}
		if(tmp==2)
		{
			if(judge(u,v))
			{
				printf("Y\n");
			}
			else
			{
				printf("N\n");
			}
		}
	}
	return 0;
}
