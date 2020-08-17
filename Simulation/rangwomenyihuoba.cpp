#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, k = 0, head[N], dis[N];
bool vis[N];
struct node
{
    int to, next, w;
} edge[N * 2];
void add(int u, int v, int w)
{
    edge[++k].to = v;
    edge[k].next = head[u];
    edge[k].w = w;
    head[u] = k;
}
void dfs(int id, int val)
{
    dis[id] = val;
    vis[id] = true;
    for (int i = head[id]; i; i = edge[i].next)
        if (!vis[edge[i].to])
            dfs(edge[i].to, val ^ edge[i].w);
}
int main()
{
    cin >> n;
    int u, v, w;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, 0);
    cin >> m;
    while (m--)
    {
        cin >> u >> v;
        cout << (dis[u] ^ dis[v]) << endl;
    }
    return 0;
}