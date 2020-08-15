#include <bits/stdc++.h>

using namespace std;
const int N = 105;
char maps[N][N];
int vis[N][N];
int d[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, -1, -1, -1, 1, 1, -1, 1, 1};
int m, n;
void dfs(int r, int c, int id)
{
    if (r >= m || r < 0 || c >= n || c < 0)
        return;
    if (maps[r][c] != '@' || vis[r][c] > 0)
        return;
    vis[r][c] = id;
    for (int i = 0; i < 8; ++i)
    {
        dfs(r + d[i][0], c + d[i][1], id);
    }
}
int main()
{
    while (scanf("%d%d", &m, &n) == 2 && m && n)
    {
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < m; ++i)
            cin >> maps[i];
        int cnt = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (vis[i][j] == 0 && maps[i][j] == '@')
                    dfs(i, j, ++cnt);
            }
        cout << cnt << endl;
    }
    return 0;
}