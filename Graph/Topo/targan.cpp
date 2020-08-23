#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, x, y, top = 0, cnt = 0, t, col;
int ans1 = -1, ans2 = -1, ans3 = -1;
int head[N];
int dfn[N], low[N], sta[N];
bool insta[N];

struct edge
{
    int u, v, w, next;
} e[1000020];

void add(int u, int v, int w)
{
    e[top].u = u;
    e[top].v = v;
    e[top].w = w;
    e[top].next = head[u];
    head[u] = top++;
}

void tarjan(int now)
{
    dfn[now] = low[now] = ++cnt;
    sta[++t] = now;
    insta[now] = 1;
    for (int i = head[now]; ~i; i = e[i].next)
        if (!dfn[e[i].v])
        {
            tarjan(e[i].v);
            low[now] = min(low[now], low[e[i].v]);
        }
        else if (insta[e[i].v])
            low[now] = min(low[now], dfn[e[i].v]);
    int cur;
    if (dfn[now] == low[now])
    {
        do
        {
            cur = sta[t--];
            insta[cur] = false;
            printf("%d ", cur);
        } while (now != cur);
        printf("\n");
    }
}

int main()
{
    cin >> n >> m;
    memset(head, -1, sizeof head);
    for (int i = 1; i <= m; ++i)
        cin >> x >> y, add(x, y, 0);
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i);
    return 0;
}
// 4 5
// 1 2 2 4 3 2 4 3 5 1