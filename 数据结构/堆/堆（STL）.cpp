#include <iostream>
#include <algorithm>
using namespace std;
const int N=100000;
int heap[N+1];
int main()
{
	int h_size=0;
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		h_size++;
		heap[h_size]=x;
		push_heap(heap+1,heap+h_size+1,greater<int>());//小根，大根则是less<int>() 
	}
	for(int i=1;i<=n;i++)
	{
		pop_heap(heap+1,heap+h_size+1,greater<int>());
		x=heap[h_size];
		h_size--;
		cout<<x<<" ";
	}
	return 0;
 } 
