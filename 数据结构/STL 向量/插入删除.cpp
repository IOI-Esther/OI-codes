#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	cout<<v.empty() <<endl;//�п� 
	cout<<v.size() <<endl; //Ԫ����Ŀ 
	for(int i=0;i<5;i++)
	{
		v.push_back(i); //ĩβ��� 
	}
	cout<<v.size() <<endl;
	v.pop_back() ;//ĩβɾ�� 
	for(int i=0;i<v.size() ;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	v.clear() ;//ȫ��ɾ�� 
	cout<<v.size() <<endl;
	return 0;
}
