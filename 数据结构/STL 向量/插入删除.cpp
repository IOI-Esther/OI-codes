#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	cout<<v.empty() <<endl;//ÅÐ¿Õ 
	cout<<v.size() <<endl; //ÔªËØÊýÄ¿ 
	for(int i=0;i<5;i++)
	{
		v.push_back(i); //Ä©Î²Ìí¼Ó 
	}
	cout<<v.size() <<endl;
	v.pop_back() ;//Ä©Î²É¾³ý 
	for(int i=0;i<v.size() ;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	v.clear() ;//È«²¿É¾³ý 
	cout<<v.size() <<endl;
	return 0;
}
