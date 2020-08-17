#include <bits/stdc++.h>
using namespace std;
struct notes
{
    int u, v, w;
} edge[100005];
int n, m, tot, maxn, p[305];
int find(int u)
{
    return p[u] == u ? u : p[u]=find(p[u]);
}
bool cmp(notes u, notes v)
{
    return u.w < v.w;
}
int main()
{
    for (int i = 1; i <= 300; i++)
        p[i] = i;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    sort(edge + 1, edge + m + 1, cmp);
    for (int i = 1; i <= m; i++)
        if (find(edge[i].u) != find(edge[i].v))
        {
            p[find(edge[i].u)] = find(edge[i].v);
            tot++;
            maxn = edge[i].w;
            if (tot == n - 1)
                break;
        }
    cout << n - 1 << " " << maxn << endl;
    return 0;
}
