#include <iostream>
#include <algorithm>
using namespace std;
//put():�� root����� 
//��С���󣺽������ 
void put(int heap[],int size,int root)
{
	int x=heap[root];//ȡֵ 
	int i=root;
	int j=2*i;//i�����ĺ��� 
	while(j<=size)
	{
		if(j<size&&heap[j]<heap[j+1])
		{
			j++;
		}
		if(x>=heap[j])
		{
			break;//����ѵ����ʣ�ֹͣ 
		}
		swap(heap[i],heap[j]);//���� 
		i=j;
		j=2*i;//ˢ�� 
	}
	heap[i]=x;
}
int a[100001];
int main()
{
	int n;
	cin>>n;
	//input
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	 //���ѣ�n/2�Ժ���Ҷ�ڵ㣬���ù� 
	for(int i=n/2;i>=1;i--)
	{
		put(a,n,i);
	}
	//ÿһ��ȡ�����Ľڵ�嵽��󲢽���֮ǰ�Ľ��� 
	for(int i=n;i>=2;i--)
	{
		swap(a[1],a[i]);
		put(a,i-1,1);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
//STL������sort_heap(a+1,a+n+1) 
