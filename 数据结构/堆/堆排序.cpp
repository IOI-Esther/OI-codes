#include <iostream>
#include <algorithm>
using namespace std;
//put():将 root插入堆 
//从小到大：建大根堆 
void put(int heap[],int size,int root)
{
	int x=heap[root];//取值 
	int i=root;
	int j=2*i;//i的最大的孩子 
	while(j<=size)
	{
		if(j<size&&heap[j]<heap[j+1])
		{
			j++;
		}
		if(x>=heap[j])
		{
			break;//满足堆的性质，停止 
		}
		swap(heap[i],heap[j]);//交换 
		i=j;
		j=2*i;//刷新 
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
	 //建堆，n/2以后都是叶节点，不用管 
	for(int i=n/2;i>=1;i--)
	{
		put(a,n,i);
	}
	//每一次取出最大的节点插到最后并将他之前的建堆 
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
//STL函数：sort_heap(a+1,a+n+1) 
