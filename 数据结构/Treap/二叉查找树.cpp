#include <iostream>
using namespace std;
const int N=100005;
struct Node
{
	int val;
	int cnt;
	int left;
	int right;
};
int tot;
Node bt[N+1];
void in_order(int k)
{
	if(!k)
	{
		return ;
	}
	in_order(bt[k].left);
	for(int i=1;i<=bt[k].cnt;i++)
	{
		cout<<bt[k].val<<" ";
	}
	in_order(bt[k].right);
}
int find(int k,int x)
{
	if(!k)
	{
		return 0;
	}
	if(bt[k].val==x)
	{
		return k;
	}
	else if(bt[k].val<x)
	{
		find(bt[k].left,x);
	} 
	else
	{
		find(bt[k].right,x);
	}
}
int find_min(int k)
{
	if(!k)
	{
		return 0;
	 } 
	if(!bt[k].left)
	{
		return k;
	}
	return find_min(bt[k].left);
 } 
int find_max(int k)
{
	if(!k)
	{
		return 0;
	 } 
	if(!bt[k].right)
	{
		return k;
	}
	return find_max(bt[k].right);
} 
int insert(int& k,int x)
{
	if(!k)
	{
		tot++;
		k=tot;
		bt[k].val=x;
		bt[k].left=0;
		bt[k].right=0;
		bt[k].cnt=1;
		return k;
	}
	if(bt[k].val>x)
	{
		return insert(bt[k].left,x);
	}
	if(bt[k].val<x)
	{
		return insert(bt[k].right,x);
	}
	else
	{
		bt[k].cnt++;
		return k;
	}
}
int del_min(int& k)
{
	if(!bt[k].left)
	{
		int tmp=k;
		k=bt[k].right;
		return tmp;
	}
	return del_min(bt[k].left);
}
void del(int& k,int x)
{
	if(!k)
	{
		return ;
	}
	if(bt[k].val==x)
	{
		if(bt[k].cnt>1)
		{
			bt[k].cnt--;
		}
		else if(bt[k].left>0 && bt[k].right>0)
		{
			int tmp=del_min(bt[k].right);
			bt[k].val=bt[tmp].val;
			bt[k].cnt=bt[tmp].cnt;
		}
		else if(bt[k].left>0)
		{
			k=bt[k].left;
		}
		else if(bt[k].right>0)
		{
			k=bt[k].right;
		}
		else
		{
			k=0;
		}
		return;
	}
	if(bt[k].val>x)
	{
		del(bt[k].left,x);
	}
	else if(bt[k].val<x)
	{
		del(bt[k].right,x);
	}
}
void output(int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<"("<<bt[i].val<<" "<<bt[i].cnt<<")"<<endl;
	}
	cout<<endl;
}
int main()
{
	int a[9]={0,6,2,7,1,5,3,4,3};
	int root=0;
	for(int i=1;i<=8;i++)
	{
		insert(root,a[i]);
	}
	output(tot);
	in_order(root);
	cout<<endl;
	int r0=find(root,10);
	int r1=find_min(root);
	int r3=find_max(root);
	cout<<r0<<" "<<bt[r1].val<<" "<<bt[r3].val<<endl;
	del(root,3);
	in_order(root);
	return 0;
}
