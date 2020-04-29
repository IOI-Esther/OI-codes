//队列 
//队列是限定在一端进行删除的特殊线性表。
//删除-出队；插入-入队。 
//出队-队头；入队-队尾。 
//先进先出（FIFO）表。 
//front-队头指针；rear-队尾指针，指向队尾元素的下一个位置； 
//循环队列：避免“假溢出”。
#include <iostream>
using namespace std;
const int N=100;
class queue
{
	private:
		int front;
		int rear;
		int n;
		int q[N+1];
	public:
		queue();
		bool push(int value);
		bool pop(int &valude);
		int size();
		bool empty();
		bool full();
};
queue::queue()
{
	front=0;
	rear=0;
	n=0; 
	for(int i=0;i<=N;i++)
	{
		q[i]=0;
	}
}
int queue::size()
{
	return n;
}
bool queue::empty()
{
	return (front==rear&&n==0);
}
bool queue::full()
{
	return (front==rear&&n==N);
}
bool queue::push(int value)
{
	if(full())
	{
		return false;
	}
	q[rear]=value;
	rear=(rear+1)%N;
	n++;
	return true;
}
bool queue::pop(int &value)
{
	if(empty())
	{
		return false;
	}
	value=q[front];
	front=(front+1)%N;
	n--;
	return true;
}
int main()
{
	queue que;
	cout<<que.size() <<endl;
	que.push(100); 
	que.push(1500); 
	cout<<que.size() <<endl;
	while(!que.empty() )
	{
		int value=0;
		que.pop(value);
		cout<<value<<" "<<que.size() <<endl; 
	  }  
	  return 0;
} 
