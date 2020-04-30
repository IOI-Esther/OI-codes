#include <iostream> 
#include <map>
#include <string>
using namespace std;
map<string,string> r;
string find(string u)
{
	if(r[u]!=u)
	{
		r[u]=find(r[u]);
	}
	return r[u];
}
void unionn(string u,string v)
{
	string r1=find(u);
	string r2=find(v);
	if(r1!=r2)
	{
		r[r1]=r2;
	}
}
int main()
{
	string s,fa;
	while(cin>>s)
	{
		int l=s.length();
		if(s[0]=='$')
		{
			break;
		}
		if(s[0]=='#')
		{
			s=s.substr(1,l-1);
			fa=s;
			if(r[s]=="")
			{
				r[s]=s;
			}
		}
		else if(s[0]=='+')
		{
			s=s.substr(1,l-1);
			if(r[s]=="")
			{
				r[s]=s;
			}
			unionn(s,fa);
		}
		else if(s[0]=='?')
		{
			s=s.substr(1,l-1);
			cout<<s<<" "<<find(s)<<endl;
		}
	}
	return 0;
}
