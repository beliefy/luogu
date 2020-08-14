#include<bits/stdc++.h>

using namespace std;

int main()
{
    // double a,b;
    // cin>>a>>b;
    // // cout.unsetf(ios::fixed);
    // cout<<fixed<<setprecision(2)<<a<<"/"<< a/b<<"="<<b<<endl;
    // return 0;
    string s;
    int t;
    cin>>s;
    string ss[100];
    int i = 0;
    cin>>t;
    while(1)
    {
        cin>>t;
        if(t==-1)
            break;
        ss[i++]=to_string(t);
    }
    for(int j = 0;j<i;j++)
    {
        if(s.length()!=ss[j].length())
        {
            cout<<"No"<<endl;
        }
        int sum=0;
        for(int k = 0;k<s.length();k++)
        {
            if(ss[j][k]!=s[k])
            {
                sum++;
            }
        }
        if(sum>1)
        {
            cout<<"No"<<endl;
        }
        else
        {
                       cout<<"Yes"<<endl;

        }
        
    }
    return 0;
}