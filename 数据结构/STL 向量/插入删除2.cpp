#include <iostream>
#include <vector>
using namespace std;
void output(vector<int> v); 
int main()
{
	vector<int> v;
	for(int i=0;i<5;i++)
	{
		v.push_back(i); //���� 
	}
	vector<int>::iterator t=v.begin() +3;//���õ�����λ�� 
	v.insert(t,100);//�ڵ�t��λ�ò���100 
	output(v);
	v.erase(t);//ɾ����t��Ԫ�� 
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
