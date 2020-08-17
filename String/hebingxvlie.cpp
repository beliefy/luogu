#include<bits/stdc++.h>

using namespace std;

int main()
{
    string pre ,s[100005];
    int n;
    cin>>n;
    for(int i =0;i<n;++i)
    {
        cin>>s[i];
    }
    cin>>pre;
    sort(s,s+n);
    int l=pre.size();
    for(int i = 0;i<n;++i)
    {
        if(s[i].substr(0,l)==pre)
        cout<<s[i]<<endl;
    }
    return 0;
}