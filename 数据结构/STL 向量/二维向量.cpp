#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector< vector<int> > v(5);//������ά�������ո����� 
	for(int i=0;i<v.size();i++)
	{
		v[i]=vector<int>(i+1);//Ϊÿһ�����ò�ͬ�ĳ��� 
		for(int j=0;j<v[i].size() ;j++)
		{
			v[i][j]=10*i+j;//��ֵ 
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
