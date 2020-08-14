#include <bits/stdc++.h>
using namespace std;
const int maxsize = 501;
int n;
int mp[maxsize][maxsize];
int fa[maxsize * maxsize];
int ans = 0;
int siz[maxsize * maxsize];
struct node
{
    int u, v, w;
    node() {}
    node(int uu, int vv, int ww)
    {
        u = uu;
        v = vv;
        w = ww;
    }
} edge[maxsize * maxsize * 4];
bool cmp(const node &a, const node &b)
{
    return a.w < b.w;
}
int find(int x)
{
    return fa[x] == x ? x : find(fa[x]);
}
int tran(int i, int j)
{
    return (i - 1) * n + j;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n * n; i++)
    {
        fa[i] = i;
        siz[i] = 1;
    }
    int idx = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i > 1)
            {
                edge[idx] = node(tran(i, j), tran(i - 1, j), abs(mp[i - 1][j] - mp[i][j]));
                idx++;
            }
            if (j > 1)
            {
                edge[idx] = node(tran(i, j), tran(i, j - 1), abs(mp[i][j - 1] - mp[i][j]));
                idx++;
            }
            if (i < n)
            {
                edge[idx] = node(tran(i, j), tran(i + 1, j), abs(mp[i + 1][j] - mp[i][j]));
                idx++;
            }
            if (j < n)
            {
                edge[idx] = node(tran(i, j), tran(i, j + 1), abs(mp[i][j + 1] - mp[i][j]));
                idx++;
            }
        }
    }
    sort(edge + 1, edge + idx, cmp);
    for (int i = 1; i < idx; i++)
    {
        int x = edge[i].u;
        int y = edge[i].v;
        int w = edge[i].w;
        x = find(x);
        y = find(y);
        if (x != y)
        {
            fa[x] = y;
            siz[y] += siz[x];
            if (siz[y] >= (n * n + 1) / 2)
            {
                cout << w << endl;
                return 0;
            }
        }
    }
}