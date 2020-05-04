using namespace std;
const int MAXN=100005;
struct Node
{
	int ch[2];
	int size,cnt;
	int val;
	int fa;
};
Node t[MAXN<<1];
int n,m,tot,rt;

int newNode(int val)
{
	tot++;
	t[tot].ch[0]=0;
	t[tot].ch[1]=0;
	t[tot].cnt=1;
	t[tot].fa=0;
	t[tot].size=1;
	t[tot].val=val;
	return tot;
}

void update(int id)
{
	t[id].size=t[t[id].ch[0]].size+t[t[id].ch[1]].size+t[id].cnt;
	t[t[id].ch[0]].fa=id;
	t[t[id].ch[1]].fa=id;
} 

int build(int l,int r)
{
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
 
 int kth(int id,int k)
 {
 	if(!id || k<=0 || t[id].size<k)
 	{
 		return -1;
	 }
 	int lsize=t[t[id].ch[0]].size;
 	if(k<=lsize)
 	{
 		if(!t[id].ch[0])
 		{
 			return kth(t[id].ch[0],k);
		 }
	 }
	 else if(k>lsize+t[id].cnt)
	 {
	 	if(!t[id].ch[1])
	 	{
	 		return kth(t[id].ch[1],k-lsize-t[id].cnt);
		 }
	 }
	else
	{
		return id;
	}
}

int split(int id,int k)
{
	splay(kth(id,k),id);
	int x=t[id].ch[1];
	t[x].fa=0;
	t[id].ch[1]=0;
	update(id);
	return x;
 } 

void merge(int id1,int id2)
{
	splay(kth(id1,t[id1].size),id1);
	t[id2].fa=id1;
	t[id1].ch[1]=id2;
	update(id1);
}

int main()
{
	
	return 0;
}
