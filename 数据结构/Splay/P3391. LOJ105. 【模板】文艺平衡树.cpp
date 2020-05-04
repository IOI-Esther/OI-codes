#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

int read()
{
	int num=0,f=1;char ch;
	while(1){ch=getchar();	if(ch=='-' || isdigit(ch)) break;}
	if(ch=='-')	f=-1;else num=ch-'0';
	while(1){ch=getchar();	if(!isdigit(ch)) break; num*=10;	num+=ch-'0';}
	return num*f;
}

const int MAXN=100005;
struct Node
{
	int ch[2];
	int size,cnt;
	int val;
	int fa;
	bool flip;
};
Node t[MAXN<<2];
int tot,rt;

int newNode(int val)
{
	tot++;
//	cout<<val<<" "<<tot<<endl;
	t[tot].ch[0]=0;
	t[tot].ch[1]=0;
	t[tot].cnt=1;
	t[tot].fa=0;
	t[tot].size=1;
	t[tot].flip=false;
	t[tot].val=val;
	return tot;
}

void update(int id)
{
	t[id].size=t[t[id].ch[0]].size*(bool)(t[id].ch[0])+t[t[id].ch[1]].size*(bool)(t[id].ch[1])+t[id].cnt;
	t[t[id].ch[0]].fa=id*(bool)(t[id].ch[0]);
	t[t[id].ch[1]].fa=id*(bool)(t[id].ch[1]);
} 

int build(int l,int r)
{
//	cout<<l<<" "<<r<<endl;
//	if(l==r)
//	{
//	    return 0;
//	}
	if(l>r)
	{
		return 0;
	}
	int mid=(l+r)>>1;
	int id=newNode(mid);
	t[id].ch[0]=build(l,mid-1);
	t[id].ch[1]=build(mid+1,r);
	update(id);
	return id;
}

int leftOrRight(int id)
{
	return t[t[id].fa].ch[1]==id;
 } 
 
void rotate(int x,int k)
{
	int f=t[x].fa;
	int ff=t[f].fa;
	int lORF=leftOrRight(f); 
	t[f].ch[k]=t[x].ch[k^1];
	t[x].ch[k^1]=f;
	update(f);
	update(x);
	t[ff].ch[lORF]=x;
	update(ff);
	if(!ff)
	{
		rt=x;
	}
}
void splay(int id,int rt)
{
	if(id==rt)
	{
		return ;
	}
	while(t[id].fa!=rt)
	{
		int f=t[id].fa;
		if(t[f].fa!=rt)
		{
			if(leftOrRight(id)==leftOrRight(f))
			{
				rotate(f,leftOrRight(f));
			}
			else
			{
				rotate(id,leftOrRight(id));
			}
		 }
		rotate(id,leftOrRight(id));
	}
	rotate(id,leftOrRight(id));
 } 
 
void pushdown(int id)
{
	t[t[id].ch[0]].flip^=t[id].flip;
	t[t[id].ch[1]].flip^=t[id].flip;
	if(t[id].flip)
	{
		swap(t[id].ch[0],t[id].ch[1]);
	}
	t[id].flip=false;
}
 
 int kth(int id,int k)
 {
// 	cout<<id<<" "<<t[id].val<<" "<<k<<endl;
 	if(!id || k<=0 || t[id].size<k)
 	{
 		return -1;
	 }
	pushdown(id); 
 	int lsize=(bool)(t[id].ch[0])*t[t[id].ch[0]].size;
 	if(k<=lsize)
 	{
 		return kth(t[id].ch[0],k);
	}
	if(k>lsize+t[id].cnt)
	{
		return kth(t[id].ch[1],k-lsize-t[id].cnt);
	 }
	if(k>lsize && k<=lsize+t[id].cnt)
	{
		return id;
	}
	return -1;
}

void outputTree(int n)
{
	for(int id=1;id<=n;id++)
	{
		cout<<"node id:"<<id<<" value:"<<t[id].val
		<<" flip:"<<t[id].flip<<" father:"<<t[id].fa
		<<" leftChild:"<<t[id].ch[0]<<" rightChild:"<<t[id].ch[1]
		<<" count:"<<t[id].cnt<<" subtreeSize:"<<t[id].size<<endl;
	}
}

void flip(int id,int l,int r,int n)
{
	if(l==1 && r==n)
	{
		t[id].flip^=1;
		return ;
	}
	int lId=kth(id,l-1);
//	cout<<l-1<<" "<<r+1<<endl;
	int rId=kth(id,r+1);
//	cout<<lId<<" "<<rId<<endl;
	if(lId!=-1)
	{
		splay(lId,id);
	 } 
	if(rId!=-1)
	{
		if(lId==-1)
		{
//			cout<<1<<endl;
//			cout<<endl;
//			outputTree(rt);
//			cout<<endl;
//			cout<<rId<<" "<<id<<endl;
			splay(rId,id);
//			outputTree(rt);
//			cout<<endl;
		}
		else
		{
			splay(rId,t[lId].ch[1]);
		}
	}
	if(rId==-1)
	{
		t[t[lId].ch[1]].flip^=true;
		return ;
	}
	t[t[rId].ch[0]].flip^=true;
}

void output(int id)
{
	if(!id)
	{
		return ;
	}
	pushdown(id);
//	cout<<t[id].val<<" "<<t[id].flip<<endl;
	output(t[id].ch[0]);
	for(int i=1;i<=t[id].cnt;i++)
	{
		cout<<t[id].val<<" ";
	}
	output(t[id].ch[1]);
}

int main()
{
	int n=read(),m=read();
//	cout<<n<<" "<<m<<endl;
	rt=build(1,n);
//	cout<<kth(rt,1)<<endl;
//	cout<<kth(rt,2)<<endl;
//	cout<<kth(rt,3)<<endl;
//	cout<<kth(rt,4)<<endl;
//	cout<<kth(rt,5)<<endl;
//	return 0; 
	int l,r;
	for(int i=1;i<=m;i++)
	{
		l=read();
		r=read();
//		cout<<l<<" "<<r<<endl;
		flip(rt,l,r,n);
//		if(i==3)
//		{
//			cout<<"------------"<<endl;
//			cout<<kth(rt,5)<<endl;
//			return 0;
//		 } 
//		output(rt);
//		cout<<endl;
//		outputTree(n);
	}
	output(rt);
	cout<<endl;
	return 0;
}
