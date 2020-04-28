//栈：
//只能在某一段插入和删除的特殊线性表
//  进行删除和插入的一端成为栈顶
//  插入成为进栈（PUSH）
//  删除称为退栈（POP）
//栈也称后进先出表（LIFO表） 

//栈的模拟：数组
//用top指针指向栈顶

#include <iostream>
using namespace std;
const int N=10000;
int s[N+1];
int top=-1;
void stpush(int x)
{
	if(top>=N)
	{
		cout<<"ERROR!"<<endl;
		return ;
	}
	top++;
	s[top]=x;
}
int stpop()
{
	if(top<0)
	{
		cout<<"ERROR!"<<endl;
		return -2147483647;
	}
	int x;
	x=s[top];
	top--;
	return x;
}
void stoput()
{
	if(top==-1)
	{
		cout<<"empty"<<endl;
	}
	for(int i=0;i<=top;i++)
	{
		cout<<s[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int pu,po,x;
	stoput();
    cout<<"-----push------"<<endl;
    cin>>pu; 
	for(int i=0;i<pu;i++)
	{
		cin>>x;
		stpush(x);	
	}	
	stoput();
	cout<<"-----pop-------"<<endl;
	cin>>po;
	for(int i=0;i<po;i++)
	{
		int x=stpop();
		cout<<x<<endl;
	}
	stoput();
	return 0;
} 
