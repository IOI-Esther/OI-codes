#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;//����ջ 
	s.push(5);//ѹ��Ԫ��1 
	s.push(100);//ѹ��Ԫ��2 
	while(!s.empty() )//�ж�ջ�� 
	{
		cout<<s.top() ;//��ջ��Ԫ�� 
		cout<<' '<<s.size() <<endl;
		s.pop() ;//����ջ��Ԫ�� 
	  }  
	  return 0;
 } 
