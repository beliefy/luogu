#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int p[N], w[N];
int ans, u, v, c, n, m, cnt;
int find(int x)
{
    return p[x] == x ? x : find(p[x]);
}
struct node
{
    int u, v, c;
} e[N];
bool cmp(node a, node b)
{
    return a.c < b.c;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        cnt++;
        e[cnt].u = 0;
        e[cnt].v = i;
        e[cnt].c = w[i];
        e[cnt].u = i;
        e[cnt].v = 0;
        e[cnt].c = w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> u;
            cnt++;
            e[cnt].u = i;
            e[cnt].v = j;
            e[cnt].c = u;
        }
    }
    sort(e, e + cnt + 1, cmp);
    for (int i = 0; i <= cnt; i++)
    {
        int x = find(e[i].u), y = find(e[i].v);
        if (x != y)
        {
            p[x] = y;
            ans += e[i].c;
        }
    }
    cout << ans;
    return 0;
}