#include <bits/stdc++.h>
#define inf -0x3f3f3f3f
using namespace std;
int n, m, s, x, y, z, out, fh, cnt, top, head[1510], w[1510];
bool inque[1510];
deque<int> q;
struct Edge
{
    int to, next, w;
} e[100010];

void add(int x, int y, int z) 
{
    cnt++, e[cnt].next = head[x], e[cnt].to = y, e[cnt].w = z, head[x] = cnt;
}
void spfa(int s)
{
    for (int i = 1; i <= n; i++)
        w[i] = inf;
    w[s] = 0, inque[s] = 1;
    q.push_back(s);
    while (!q.empty())
    {
        x = q.front();
        q.pop_front();
        for (int i = head[x]; i; i = e[i].next)
        {
            y = e[i].to;
            if (w[y] < w[x] + e[i].w)
            {
                w[y] = w[x] + e[i].w;
                if (!inque[y])
                {
                    inque[y] = 1;
                    if (!q.empty())
                    {
                        if (w[y] < w[q.front()])
                            q.push_back(y);
                        else
                            q.push_front(y);
                        
                    }
                    else
                        q.push_back(y);
                }
            }
        }
        inque[x] = 0;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        add(x, y, z);
    }
    spfa(1);
    printf("%d", (w[n] == inf ? -1 : w[n])); 
    return 0;
}