#include <bits/stdc++.h>
using namespace std;

int n, m;
int maps[1010][1010];
int dp[1010][1010];
int ans;
const int inf = -0xffff;
int direct[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int x, int y)
{
    if (dp[x][y] > 1)
        return dp[x][y];
    for (int i = 0; i < 4; i++)
    {
        int xx = x + direct[i][0];
        int yy = y + direct[i][1];
        if (maps[xx][yy]!=inf && maps[x][y] > maps[xx][yy])
        {
            dp[x][y] = max(dp[x][y], dfs(xx, yy) + 1);
        }
    }
    return dp[x][y];
}

int main()
{
    memset(maps,inf,sizeof(maps));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> maps[i][j], dp[i][j] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}
