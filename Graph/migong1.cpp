#include <bits/stdc++.h>
using namespace std;
int maps[101][101];
int ans = 0;
int i, j, n, m, t, sx, sy, x, y, fx, fy;
void dfs(int a, int b)
{
    if (a == fx && b == fy)
    {
        ans++;
        return;
    }
    else
    {
        maps[a][b] = 0;
        if (maps[a - 1][b])
            dfs(a - 1, b), maps[a - 1][b] = 1;
        if (maps[a][b - 1])
            dfs(a, b - 1), maps[a][b - 1] = 1;
        if (maps[a][b + 1])
            dfs(a, b + 1), maps[a][b + 1] = 1;
        if (maps[a + 1][b])
            dfs(a + 1, b), maps[a + 1][b] = 1;
    }
}
int main()
{
    memset(maps, 0, sizeof(maps));
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            maps[i][j] = 1;
    for (i = 1; i <= t; i++)
    {
        cin >> x >> y;
        maps[x][y] = 0;
    }
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}