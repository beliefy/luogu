#include <bits/stdc++.h>
using namespace std;
#define re register
#define il inline
struct Edge
{
    int u, v, w;
} e[200005];
int p[5005], n, m, ans, eu, ev, cnt;
il bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
il int find(int x)
{
    return p[x]==x?x:find(p[x]);
}

il void kruskal()
{
    sort(e, e + m, cmp);
    for (re int i = 0; i < m; i++)
    {
        eu = find(e[i].u), ev = find(e[i].v);
        if (eu == ev)
            continue;
        //若出现两个点已经联通了，则说明这一条边不需要了
        ans += e[i].w;
        //将此边权计入答案
        p[ev] = eu;
        //将eu、ev合并
        if (++cnt == n - 1)
            break;
        //循环结束条件，及边数为点数减一时
    }
}
int main()
{
    cin >> n >> m;
    for (re int i = 1; i <= n; i++)
        p[i] = i;

    for (re int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    kruskal();
    cout<<ans<<endl;
    return 0;
}