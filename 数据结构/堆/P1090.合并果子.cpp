#include<iostream>
#include<algorithm>
using namespace std;
int heap[10001];
int size=0;
int main()
{
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		size++;
		heap[size]=x;
		push_heap(heap+1,heap+size+1,greater<int>());
	}
	int res=0;
	for(int i=1;i<n;i++)
	{
		
		pop_heap(heap+1,heap+size+1,greater<int>());
		int top1=heap[size];
		size--;
		
		pop_heap(heap+1,heap+size+1,greater<int>());
		int top2=heap[size];
		
		heap[size]=top1+top2;
		res+=heap[size];
		push_heap(heap+1,heap+size+1,greater<int>());
	}
	cout<<res<<endl;
	return 0;
 } 
