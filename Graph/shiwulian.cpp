#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2E5 + 5;
struct node
{
    int u, v, nxt;
} e[MAXN];

int first[100005], inde[MAXN], outde[MAXN];
int f[MAXN];
int ans = 0;
queue<int> q;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        e[i].u = u, e[i].v = v, e[i].nxt = first[u], first[u] = i;
        inde[v]++, outde[u]++;
    }

    for(int i = 1;i<=n;++i)
    {
        if(inde[i]==0)
        {
            f[i]=1;
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int k = first[u];k;k=e[k].nxt)
        {
            int v = e[k].v;
            f[v]+=f[u];
            inde[v]--;
            if(inde[v]==0)
            {
                if(outde[v]==0)
                {
                    ans+=f[v];
                }
                else
                {
                    q.push(v);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}