#include <iostream>
#include <algorithm>
using namespace std;
void put(int heap[],int& heap_size,int x)
{
	heap_size++;
	heap[heap_size]=x;
	int cur=heap_size;
	while(cur>1)
	{
		int fa=cur>>1;//cur/2
		if(heap[cur]>=heap[fa])
		{
			break;
		}
		swap(heap[cur],heap[fa]);
		cur=fa;
	}
}
int get(int heap[],int& heap_size)
{
	int res=heap[1];
	heap[1]=heap[heap_size];
	heap_size--;
	int cur=1;
	while(cur*2<=heap_size)
	{
		int son=cur*2;
		if(son<heap_size&&heap[son+1]<heap[son])
		{
			son++;
		}
		if(heap[cur]<=heap[son])
		{
			break;
		}
		swap(heap[cur],heap[son]);
		cur=son;
	}
	return res;
}
int main()
{
	int h[1001],size=0;
	int tmp;
	while(cin>>tmp)
	{
		put(h,size,tmp);
	}
	while(size)
	{
		cout<<get(h,size)<<endl;
	}
	return 0;
}
