#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;
struct node
{
    int start, end, w;
} a[5005];
bool vis[N];

bool cmp(node a,node b)
{
    return a.end<b.end;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i =1;i<=m;++i)
        cin>>a[i].start>>a[i].end>>a[i].w;

    sort(a+1,a+m+1,cmp);
    int ans = 0;
    for(int i= 1;i<=m;++i)
    {
        int havt=0;
        for(int j = a[i].start;j<=a[i].end;++j) 
            if(vis[j]) havt++;

        if(havt>=a[i].w) continue;

        for(int j = a[i].end;j>=a[i].start;j--)
        {
            if(!vis[j]) 
            {
                vis[j]=1;
                havt++;
                ans++;
            }
            if(havt>=a[i].w) break;
        }
    }

    cout<<ans<<endl;
    return 0;
}