#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	char c;
	cin>>a>>b;
	cin>>c;
	if(b==0&&c=='/')
	{
		cout<<"Divided by zero!"<<endl;
		return 0;
	}
	if(c=='+')
		cout<<a+b<<endl;
	else if(c=='-')
		cout<<a-b<<endl;
	else if(c=='*')
		cout<<a*b<<endl;
	else if(c=='/')
		cout<<a/b<<endl;

	else
		cout<<"Invalid operator!"<<endl;
	return 0;
}
