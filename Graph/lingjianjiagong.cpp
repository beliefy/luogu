#include <bits/stdc++.h>
#define MAXN 100010
#define inf 0x3f3f3f3f
using namespace std;
int n, m, q, cnt;
int even[MAXN], odd[MAXN], head[MAXN];

struct node
{
    int to, nxt;
} e[MAXN * 2];

void add(int x, int y)
{
    e[++cnt].to = y;
    e[cnt].nxt = head[x];
    head[x] = cnt;
}

void bfs()
{
    memset(even, inf, sizeof even);
    memset(odd, inf, sizeof odd);
    queue<int> q;
    q.push(1);
    even[1] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].to;
            if (odd[u] + 1 < even[v])
            {
                even[v] = odd[u] + 1;
                q.push(v);
            }
            if (even[u] + 1 < odd[v])
            {
                odd[v] = even[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    memset(head, -1, sizeof head);
    cin >> n >> m >> q;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    bfs();
    for (int i = 1, x, y; i <= q; i++)
    {
        cin >> x >> y;
        if (x == 1 && -1 == head[1])
        {
            cout << "No" << endl;
            continue;
        }
        if (y % 2 == 0 && even[x] <= y || y % 2 == 1 && odd[x] <= y)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}