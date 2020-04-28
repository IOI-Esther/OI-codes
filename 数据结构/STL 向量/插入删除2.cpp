#include <iostream>
#include <vector>
using namespace std;
void output(vector<int> v); 
int main()
{
	vector<int> v;
	for(int i=0;i<5;i++)
	{
		v.push_back(i); //插入 
	}
	vector<int>::iterator t=v.begin() +3;//设置迭代器位置 
	v.insert(t,100);//在第t个位置插入100 
	output(v);
	v.erase(t);//删除第t个元素 
	output(v);
	return 0;
}
void output(vector<int> v)
{
	for(int i=0;i<v.size() ;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
