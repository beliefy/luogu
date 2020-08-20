#include<bits/stdc++.h>
using namespace std;
int n;
string str[55];
string s;
bool flag[40];
int main()
{
    cin>>n;
	for(int i=1;i<=n;++i)		
	{
		cin>>str[i];
	}
	cin>>s;
	int len=s.length();
	for(int i=1;i<=n;++i)
	{
		if(s==str[i].substr(0,len))
		{
			flag[str[i][len]-'A'+4]=1;
		}
	}
	for(int i=1;i<=32;++i)		
	{
		if(flag[i]==0)		
		{
			cout<<'*';
		}
		else				
		{
			cout<<char(i-4+'A');	
		}
		if(i%8==0)			
			cout<<endl;
	}
	return 0;
}
