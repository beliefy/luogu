#include<bits/stdc++.h>

using namespace std;

stack<pair<int,int>> s;
long long ans= 0;
int main()
{
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
    {
        int x;
        cin>>x;
        pair<int,int> p(x,1);
        while(!s.empty()&&s.top().first<=x)
        {
            ans+=s.top().second;
            if(s.top().first==x) p.second+=s.top().second;
            s.pop();
        }
        if(!s.empty()) ans++;
        s.push(p);
    }
    cout<<ans<<endl;
    return 0;
}