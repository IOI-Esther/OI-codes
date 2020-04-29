//Blah数集
//中心思想：改变指针，设置2x+1和3x+1两个队尾指针 
//伪代码： 
/*IF q[two]*2+1<=q[three] *3+1
    IF q[two]*2+1!=q[rear-1]  
        q[rear]++=q[two]*2+1;two++; 
    IF q[two]*2+1==q[rear+1];
        ONLY two++;
IF q[two]*2+1>q[three]*3+1:
    IF q[three]*3+1!=q[rear-1];
	      q[rear++]=q[three]*3+1;three++;
    IF q[three]*3+1==q[rear-1]
        ONLY three++;*/
#include <iostream>
using namespace std;
const int N=10000;
int q[N+1]; 
int main()
{
	int a,n;
	while(cin>>a>>n)
	{
		for(int i=0;i<=N;i++)
		{
			q[i]=0;
		}
		int rear=1,two=0,three=0,i=0;
		q[0]=1;
		while(i<=n)
		{
			if(q[two]*2+1<=q[three]*3+1)
			{
				if(q[two]*2+1!=q[rear-1])
				{
					q[rear++]=q[two]*2+1;
					two++;
				}
				else
				{
					two++;
				}
			}
			if(q[two]*2+1>q[three]*3+1)
			{
				if(q[three]*3+1!=q[rear-1])
				{
					q[rear++]=q[three]*3+1;
					three++;
				}
				else
				{
					three++;
				}
			}
			i++;
		}
		cout<<q[rear]<<endl;
	}
	return 0;
}
