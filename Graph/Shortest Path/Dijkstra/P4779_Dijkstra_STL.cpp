#include <bits/stdc++.h>
#define N 100001
#define M 200001
#define INF 0x7fffffff
using namespace std;

int n, m, s, head[N], to[M], w[M], nxt[M], dis[N], cnt;
bool visit[N];
struct da
{
    int u, s;
    bool operator<(const da &a) const
    {
        return s > a.s;
    }
} now;
priority_queue<da> q;

void adde(int u, int v, int wi)
{
    cnt++;
    to[cnt] = v;
    w[cnt] = wi;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

void dijkstra()
{
    memset(dis, 127, sizeof(dis));
    q.push((da){s, 0});
    while (!q.empty())
    {
        now = q.top();
        q.pop();
        if (visit[now.u])
            continue;
        visit[now.u] = true;
        dis[now.u] = now.s;
        for (int i = head[now.u]; i; i = nxt[i])
        {
            if (!visit[to[i]] && now.s + w[i] < dis[to[i]])
            {
                q.push((da){to[i], now.s + w[i]});
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adde(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}