#include <iostream>
using namespace std;
int n,m;
struct Point
{
	int x;
	int y;
};
Point r[201][201];
bool oper(Point u,Point v)
{
	return u.x==v.x && u.y==v.y;
}
bool notoper(Point u,Point v)
{
	return u.x!=v.x || u.y!=v.y;
}
Point find(Point u)
{
	if(notoper(r[u.x][u.y],u))
	{
		r[u.x][u.y]=find(r[u.x][u.y]);
	}
	return r[u.x][u.y];
}
void uni(Point u,Point v)
{
	Point r1=find(u);
	Point r2=find(v);
	if(notoper(r1,r2))
	{
		r[r2.x][r2.y]=r1;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			r[i][j]=(Point){i,j};
		}
	}
	int u,v;
	char ch;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>ch;
		Point gcj;
		if(ch=='D')
		{
			gcj.x=u+1;
			gcj.y=v;
		}
		else
		{
			gcj.x=u;
			gcj.y=v+1;
		}
		if(oper(find((Point){u,v}),find(gcj)))
		{
			cout<<i<<endl;
			return 0;
		}
		uni((Point){u,v},gcj);
	}
	cout<<"draw"<<endl;
	return 0;
}
