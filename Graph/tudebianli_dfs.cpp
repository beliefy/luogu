#include<bits/stdc++.h>

using namespace std;
const int maxsize = 1e5+5;
int cnt=1;
struct node
{
    int to;
    int nxt;
}e[maxsize];
int head[maxsize],ans[maxsize];
void add(int u,int v)
{
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
}

void dfs(int cur,int dis)
{
    if(ans[cur]) return;
    ans[cur]=dis;
    for(int i = head[cur];i;i=e[i].nxt)
    {
        dfs(e[i].to,dis);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i =1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        add(y,x);
    }
    for(int i = n;i>=1;--i) dfs(i,i);
    for(int i = 1;i<=n;++i) cout<<ans[i]<<" ";
    return 0;
}