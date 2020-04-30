#include <iostream>
#include <cstdio>
using namespace std;
//���ݽṹ��r[i]Ϊ i ���ϲ�Ԫ�أ�n Ϊ�������m Ϊ������ 
int r[20001];
int n,m,u,v;
//���Һ��� find() 
int find(int u)
{
	//�����˴���Ԫ�أ������� r ֵΪ�䱾����ص�
	//���ϵݹ飬��������������ص�������ݹ� 
	if(r[u]!=u)
	{
		r[u]=find(r[u]);
	}
	return r[u];
}
//�ϲ����� uni()
void uni(int u,int v)
{
	//�ҵ� r1�� r2���ڼ��ϵĴ���Ԫ�أ����� 
	int r1=find(u);
	int r2=find(v);
	//�ж��Ƿ���ͬһ�����ڣ���ǿ³���ԣ� 
	if(r1!=r2)
	{
		//�� r2���� r1���ڼ��ϵ����棨���ĸ���Ԫ�����飩 
		r[r2]=r1;
	}
}
//�ж� u �� v �Ƿ���ͬһ������ 
bool judge(int u,int v)
{
	//�ж���Ԫ�����ڼ��ϵĴ���Ԫ�أ������Ƿ�һ�� 
	int r1=find(u);
	int r2=find(v);
	return (r1==r2);
}
//������ 
int main()
{
	scanf("%d%d",&n,&m);
	//��ʼ����Ĭ�����н�㵥����һ�����ϣ���˴���Ԫ�أ�r ֵ���������Լ� 
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
