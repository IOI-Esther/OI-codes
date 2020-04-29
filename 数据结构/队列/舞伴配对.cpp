#include <iostream>
#include <queue>
using namespace std; 
int main()
{
	queue<int> male;
	queue<int> female;
	int m,n,k;
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++)
	{
		male.push(i) ;
	}
	for(int i=1;i<=n;i++)
	{
		female.push(i); 
	}
	for(int i=0;i<k;i++)
	{
		int maleno=male.front() ;
		int femaleno=female.front() ;
		cout<<maleno<<" "<<femaleno<<endl;
		male.pop() ;
		female.pop() ;
		male.push(maleno);
		female.push(femaleno);  
	}
	return 0;
}
