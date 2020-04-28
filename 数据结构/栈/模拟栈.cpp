//ջ��
//ֻ����ĳһ�β����ɾ�����������Ա�
//  ����ɾ���Ͳ����һ�˳�Ϊջ��
//  �����Ϊ��ջ��PUSH��
//  ɾ����Ϊ��ջ��POP��
//ջҲ�ƺ���ȳ���LIFO�� 

//ջ��ģ�⣺����
//��topָ��ָ��ջ��

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
