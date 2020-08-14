#include <bits/stdc++.h>
#define N 250000
using namespace std;
struct Edge
{
    int next, to;
} edge[N * 100]; 
int n, t, head[N * 100], cnt, low[N], dfn[N], sta[N];
int sa, ans = 0x3f3f3f3f, tot, num;
bool insta[N];
 void add(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++tot;
    sta[++num] = u, insta[u] = true;
    for (int i = head[u]; i; i = edge[i].next)
    {
        if (!dfn[edge[i].to])
        {
            tarjan(edge[i].to);
            low[u] = min(low[u], low[edge[i].to]);
        }
        else if (insta[edge[i].to])
            low[u] = min(low[u], dfn[edge[i].to]);
    }
    if (low[u] == dfn[u])
    {
        sa = 0;
        do
        {
            sa++;
            insta[sta[num--]] = false;
        } while (u != sta[num + 1]);
        if (sa == 2)
        {
            puts("2");
            exit(0);
        } //到2就没必要继续了

        if (sa > 1)
            ans = min(ans, sa); //取最小值
    }
}
int main()
{
    cin >> n;
    for (register int i = 1; i <= n; i++)
    {
        cin >> t;
        add(i, t);
    }
    for (register int i = 1; i <= n; i++)
        tarjan(i);
    printf("%d\n", ans);
    return 0;
}