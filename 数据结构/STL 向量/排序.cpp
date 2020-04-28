#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
void output(vector<int> v); 
int main()
{
	srand(time(0));
	vector<int> v(10);
	for(int i=0;i<v.size() ;i++)
	{
		v[i]=rand(); //²åÈë 
	}
	output(v);
	sort(v.begin() ,v.end() ); 
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
