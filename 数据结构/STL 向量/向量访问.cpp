#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v(10);
	for(int i=0;i<v.size();i++)
	{
		v[i]=i; 
	}
	vector<int>::iterator t;
	for(t=v.begin();t!=v.end();t++)
	{
		cout<<*t<<" ";
	}
	cout<<*(v.begin()+3)<<" ";
	return 0;
}
