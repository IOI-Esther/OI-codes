#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
const int MAXN=100005;
struct Node
{
	int ch[2];
	int size,cnt;
	int rnd,val;
};
Node tree[MAXN<<1];
int n,tot,root;
int newnode(int val)
{
	tot++;
	tree[tot].val=val;
	tree[tot].cnt=1;
	tree[tot].size=1;
	tree[tot].rnd=rand();
	tree[tot].ch[0]=0;
	tree[tot].ch[1]=0;
	return tot;
}
void update(int id)
{
	tree[id].size=tree[tree[id].ch[0]].size+tree[tree[id].ch[1]].size+tree[id].cnt;
}
void rotate(int &id,int k)
{
	int x=tree[id].ch[k];
	tree[id].ch[k]=tree[x].ch[k^1];
	tree[x].ch[k^1]=id;
	update(id);
	update(x);
	id=x;
}
void insert(int &id,int val)
{
	if(!id)
	{
		id=newnode(val);
		return ;
	}
	if(tree[id].val==val)
	{
		tree[id].cnt++;
	}
	else
	{
		int k=val>tree[id].val;
		insert(tree[id].ch[k],val);
		if(tree[id].rnd>tree[tree[id].ch[k]].rnd)
		{
			rotate(id,k);
		}
	}
	update(id);
}
void del(int &id,int val)
{
	if(!id)
	{
		return ;
	}
	if(tree[id].val==val)
	{
		if(tree[id].cnt>1)
		{
			tree[id].cnt--;
			tree[id].size--;
		}
		else
		{
			int k=tree[tree[id].ch[1]].rnd<tree[tree[id].ch[0]].rnd;
			if(!tree[id].ch[0] || !tree[id].ch[1])
			{
				id=tree[id].ch[0]+tree[id].ch[1];
			}
			else
			{
				rotate(id,k);
				del(id,val);
			}
		}
	}
	else
	{
		tree[id].size--;
		int k=tree[id].val<val;
		del(tree[id].ch[k],val);
	}
}
int kth(int id,int k)
{
	if(!id || k<=0 || tree[id].size<k)
	{
		return 0;
	}
	int lsize=tree[tree[id].ch[0]].size;
	if(k<=lsize)
	{
		return kth(tree[id].ch[0],k);
	}
	else if(k>lsize+tree[id].cnt)
	{
		return kth(tree[id].ch[1],k-lsize-tree[id].cnt);
	}
	else
	{
		return tree[id].val;
	}
}
int rnk(int id,int val)
{
	if(!id)
	{
		return 1;
	}
	int lsize=tree[tree[id].ch[0]].size;
	if(val<tree[id].val)
	{
		return rnk(tree[id].ch[0],val);
	}
	else if(val==tree[id].val)
	{
		return lsize+1;
	}
	else
	{
		return rnk(tree[id].ch[1],val)+lsize+tree[id].cnt; 
	}
}
int pre(int id,int val)
{
	int k=id;
	int ans=0;
	while(k>0)
	{
		if(tree[k].val<val)
		{
			ans=k;
			k=tree[k].ch[1];
		}
		else
		{
			k=tree[k].ch[0];
		}
	}
	return tree[ans].val;
}
int nxt(int id,int val)
{
	int k=id;
	int ans=0;
	while(k>0)
	{
		if(tree[k].val>val)
		{
			ans=k;
			k=tree[k].ch[0];
		}
		else
		{
			k=tree[k].ch[1];
		}
	}
	return tree[ans].val;
}
void output(int n)
{
	for(int i=0;i<=tot;i++)
	{
		cout<<"node no. "<<i<<":\t( val:"<<tree[i].val<<" cnt:"<<tree[i].cnt<<" rnd:"<<tree[i].rnd<<" size:"<<tree[i].size<<" lson:"<<tree[i].ch[0]<<" rson:"<<tree[i].ch[1]<<")"<<endl;
	}
	cout<<endl;
}
int main()
{
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
//	srand(time(0));
	scanf("%d",&n);
	int opt,x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&opt,&x);
//		printf(">>");
		if(opt==1)
		{
			insert(root,x);
		}
		else if(opt==2)
		{
			del(root,x);
		}
		else if(opt==3)
		{
			printf("%d\n",rnk(root,x));
		}
		else if(opt==4)
		{
			printf("%d\n",kth(root,x));
		}
		else if(opt==5)
		{
			printf("%d\n",pre(root,x)); 
		}
		else if(opt==6)
		{
			printf("%d\n",nxt(root,x)); 
		}
//		printf("\n");
//		output(root);
	}
	return 0;
}
