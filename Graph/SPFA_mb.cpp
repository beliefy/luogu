#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxx = 1e3 + 100;
const int N = 2e6 + 10;
typedef long long ll;
int m, n, q;
int dis[maxx];
int sto[maxx];
int pre[maxx];
int head[2 * N];
bool vis[maxx];
int a[maxx][maxx];
struct point
{
    int to;
    int next;
    int vaule;
}e[2 * N];
void add(int u, int v, int val)
{
    e[q].next = head[u];
    e[q].to = v;
    e[q].vaule = val;
    head[u] = q++;
}
void print(int x)
{
    if (pre[x] == -1)
    {
        printf("%d", x);
        return;
    }
    print(pre[x]);
    printf("-->%d", x);
    return;
}
void spfa(int st)
{
    queue<int> q;
    int w, v;
    memset(dis, inf, sizeof(dis));
    memset(pre, -1, sizeof(pre));
    memset(vis, false, sizeof(vis));
    q.push(st);
    dis[st] = 0;
    vis[st] = true;
    pre[st] = -1;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        vis[v] = false;
        for (int i = head[v]; i != -1; i = e[i].next)
        {
            w = e[i].vaule;
            if (w + dis[v] < dis[e[i].to])
            {
                dis[e[i].to] = w + dis[v];
                pre[e[i].to] = v;
                if (!vis[e[i].to])
                {
                    vis[e[i].to] = true;
                    q.push(e[i].to);
                }
            }
        }
    }
}
int main()
{
    int k, u, v, val;
    // cin >> n >> m >> k;
    cin>>n>>m;
    memset(head, -1, sizeof(head));
    q = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> val;
        add(u, v, val);
        add(v, u, val);
    }
    spfa(1);
    print(n); //打印从一到K
    return 0;
}