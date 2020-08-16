#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn = 500005;
//保存图结构
struct node
{
    int to;
    int nxt;
} e[2 * maxn];
int head[maxn];
int cnt;
void add(int a, int b)
{
    e[++cnt].to = b;
    e[cnt].nxt = head[a];
    head[a] = cnt;
}
bool vis[maxn];
int main()
{
    int n, u, v;
    cin >> n;
    while (n--)
    {
        int w;
        cin >> u >> v;
        add(u, v);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        printf("%d ", u);
        for (int i = head[u]; i; i = e[i].nxt)
        {
            if (!vis[e[i].to])
                q.push(e[i].to);
        }
    }
    return 0;
}