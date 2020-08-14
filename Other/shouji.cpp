#include<bits/stdc++.h>

using namespace std;
int cnt=0; 
int p[1000];
int main()
{
    string s;
    getline(cin,s);
    int n = s.length();
    int sum=0;
    for(int i = 'a';i<='z';++i)
    {
        p[i]=sum%3+1;
        sum++;
    }
    p['s']=4;
    p['t']=1,p['u']=2,p['v']=3,p['w']=1,p['x']=2,p['y']=3,p['z']=4;
    for(int i = 0;i<n;++i)
    {
        if(s[i]==' ')
        cnt++;
        else
        {
            cnt+=p[s[i]];
        }
    }
    cout<<cnt<<endl;
    return 0;
}