#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;                                                                         
int n, x, y, u, v, t, head[maxn], to[maxn], nxt[maxn], cnt, dep[maxn], ans, f[maxn], p[maxn]; 
void add(int x, int y)
{
    to[cnt] = y;
    nxt[cnt] = head[x];
    head[x] = cnt++;
}
void build(int x) 
{
    for (int j = head[x]; ~j; j = nxt[j])
        if (!dep[to[j]])
        {
            dep[to[j]] = dep[x] + 1;
            p[to[j]] = x;
            build(to[j]);
        }
}
int main()
{
    memset(head, -1, sizeof head); 
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    cin >> u >> v;
    t = u;
    dep[1] = 1;
    p[1] = 1;
    build(1); //建树
    for (int i = 1; i <= n; i++)
        ans = max(ans, dep[i]), f[dep[i]]++;
    cout << ans << endl;
    ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);

    cout << ans << endl;
    ans = 0;
    if (dep[u] > dep[v])
        swap(u, v);
    int low = dep[v] - dep[u];
    while (low--)
        v = p[v], ans++;
    while (u != v)
        u = p[u], v = p[v], ans += 2; //现在u==v且为初始u,v的LCA
    while (t != v)
        t = p[t], ans++;
    cout << ans << endl;
    return 0;
}