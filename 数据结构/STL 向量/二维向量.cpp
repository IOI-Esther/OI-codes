#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector< vector<int> > v(5);//声明二维向量，空格必须加 
	for(int i=0;i<v.size();i++)
	{
		v[i]=vector<int>(i+1);//为每一行设置不同的长度 
		for(int j=0;j<v[i].size() ;j++)
		{
			v[i][j]=10*i+j;//赋值 
		}
	}
	for(int i=0;i<v.size() ;i++)
	{
		for(int j=0;j<v[i].size() ;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
