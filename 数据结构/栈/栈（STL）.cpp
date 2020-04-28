#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;//声明栈 
	s.push(5);//压入元素1 
	s.push(100);//压入元素2 
	while(!s.empty() )//判断栈空 
	{
		cout<<s.top() ;//求栈顶元素 
		cout<<' '<<s.size() <<endl;
		s.pop() ;//弹出栈顶元素 
	  }  
	  return 0;
 } 
