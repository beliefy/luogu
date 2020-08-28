#include <bits/stdc++.h>
using namespace std;
const int mod = 80112002;
int n, m, first[5005], indeg[5005], outdeg[5005], f[5005], ans;
struct node
{
    int u, v, nxt;
} e[5000005];
queue<int> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin>>u>>v;
        e[i].u = u, e[i].v = v;
        e[i].nxt = first[u];
        first[u] = i;
        outdeg[u]++;
        indeg[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            f[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int k = first[u]; k; k = e[k].nxt)
        {
            int v = e[k].v;
            f[v] += f[u];
            // f[v] %= mod;
            indeg[v]--;
            if (indeg[v] == 0)
            {
                if (outdeg[v] == 0)
                {
                    ans += f[v];
                    // ans %= mod;
                }
                else
                    q.push(v);
            }
        }
    }
    cout << ans << endl;
    return 0;
}