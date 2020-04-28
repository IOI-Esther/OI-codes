#include <iostream>
using namespace std;
const int N=100;
class stack
{
	private:
		int top;
		int s[N+1];
	public:
		stack();
		bool push(int value);
		bool pop(int &valude);
		int size();
		bool empty();
};
stack::stack()
{
	top=0;
	for(int i=0;i<=N;i++)
	{
		s[i]=0;
	}
}
int stack::size()
{
	return top;
}
bool stack::empty()
{
	return (top==0);
}
bool stack::push(int value)
{
	if(top>=N)
	{
		return false;
	}
	top++;
	s[top]=value;
	return true;
}
bool stack::pop(int &value)
{
	if(top<=0)
	{
		return false;
	}
	value=s[top];
	top--;
	return true;
}
int main()
{
	stack sta;
	cout<<sta.size() <<endl;
	sta.push(1);
	sta.push(2);
	cout<<sta.size() <<endl;
	while(!sta.empty() )
	{
		int value=0;
		sta.pop(value);
		cout<<value<<" "<<sta.size() <<endl; 
	  }  
	  return 0;
}
