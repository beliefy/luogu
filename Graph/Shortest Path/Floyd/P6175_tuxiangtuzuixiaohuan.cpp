#include <bits/stdc++.h>

using namespace std;
const int MAXN = 105;
const int inf = 0x3f3f3f3f;
int dis[MAXN][MAXN], d[MAXN][MAXN];

int ans = inf;
int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                dis[i][j] = d[i][j] = inf;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <k; ++i)
            for (int j = i+1; j <k; ++j)
                ans = min(ans, dis[i][j] + d[i][k] + d[k][j]);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    if (ans == inf)
        cout << "No solution." << endl;
    else
    {
        cout << ans << endl;
    }
    return 0;
}