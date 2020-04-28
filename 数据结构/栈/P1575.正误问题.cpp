#include <iostream>
#include <stack>
#include <string>
//#include <fstream>
using namespace std;
stack<int> op;
stack<bool> va;
//0:or||; 1:and&&; 2:not!
bool calc()
{
	int noop=op.top();
	op.pop();
	bool va1,va2; 
	switch(noop)
	{
		case 0:
			if(va.size()<2)
			{
				return false;
			}
			va1=va.top();
			va.pop();
			va2=va.top();
			va.pop();
			va.push(va1||va2);
			return true;
		case 1:
			if(va.size()<2)
			{
				return false;
			}
			va1=va.top();
			va.pop();
			va2=va.top();
			va.pop();
			va.push(va1&&va2);
			return true;
		case 2:
			if(va.empty())
			{
				return false;
			}
			va1=va.top();
			va.pop();
			va.push(!va1);
			return true;
	}
}
int toValue(string _s)
{
		if(_s=="and") 
			return 1;
		if(_s=="not")
			return 2;
		if(_s=="or")
			return 0;
		if(_s=="true")
			return 1;
		if(_s=="false")
			return 0;
}
int main()
{
	//freopen("tst1.in.txt","r",stdin);
	string s;
	while(cin>>s)
	{
		if(s=="true")
		{
			va.push((bool)(toValue(s)));
		}
		if(s=="false")
		{
			va.push((bool)(toValue(s)));
		}
		if(s=="or")
		{
			while(!op.empty())
			{
				if(!calc())
				{
					cout<<"error"<<endl;
					return 0;
				}
			}
			op.push(toValue(s));
		}
		if(s=="and")
		{
			while(!op.empty()&&op.top()>=1)
			{
				if(!calc())
				{
					cout<<"error"<<endl;
					return 0;
				}
			}
			op.push(toValue(s));
		}
		if(s=="not")
		{
			op.push(toValue(s));	
		}
		//cout<<s<<endl;	
	}
	while(!op.empty())
	{
		if(!calc())
		{
			cout<<"error"<<endl;
			return 0;
		}
	}
	if(va.size()!=1)
	{
		cout<<"error"<<endl;
		return 0;
	}
	if(va.top())
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	//fclose(stdin);
	return 0;
}
