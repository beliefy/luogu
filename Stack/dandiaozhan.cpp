#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
const int maxsize = 3000050;
long long nums[maxsize],ans[maxsize];
stack<int> s;
stack<int> a;

int main()
{
    int n;
    cin>>n;
    // n=read();
    for(int i = 1;i<=n;++i)
    {
        // cin>>nums[i];
        // nums[i]=read();
        scanf("%d",&nums[i]);
    }
    for( int i =n;i>=1;--i)
    {
        while(!s.empty()&&s.top()<nums[i])
        {
            s.pop();
            a.pop();
        }
        ans[i]=a.empty()?0:a.top();
        s.push(nums[i]);
        a.push(i);
    }
    for(int i = 1;i<=n;++i)
    {
        // cout<<ans[i]<<" ";
        printf("%d ",ans[i]);
    }
    return 0;
}