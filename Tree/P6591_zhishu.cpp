#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+5,M=10005;
int siz[N];
int ans[N], cnt, n, c, head[N << 1];
struct node
{
    int next, v;
} e[N << 1];

void add(int u, int v)
{
    e[++c].next = head[u];
    e[c].v = v;
    head[u] = c;
}

void pre(int u, int fa)
{
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        pre(v, u), siz[u] += siz[v];
    }
}

void dfs(int u, int fa)
{
    int child_siz = siz[e[head[u]].v], flag = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (child_siz != siz[v])
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
        ans[++cnt] = u;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        siz[u] -= siz[v];
        siz[v] += siz[u];
        dfs(v, u);
        siz[v] -= siz[u];//回溯 还原
        siz[u] += siz[v];
    }
}

int main()
{
    cin >> n;
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    pre(1, 1);
    dfs(1, 1);
    sort(ans + 1, ans + cnt + 1);
    for (int i = 1; i <= cnt; i++)
        cout << ans[i] << " ";
    return 0;
}