#include <bits/stdc++.h>

using namespace std;
const int MAXN = 105;
int n, m;
int  dir[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, -1, -1, -1, 1, 1, 1, 1, -1};
char a[MAXN][MAXN];
void dfs(int x, int y)
{
    a[x][y] = '.';
    for (int i = 0; i < 8; ++i)
    {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx <1 || xx > n || yy <1 || yy > m||a[xx][yy]=='.')
            continue;
        dfs(xx, yy);
    }
}
int main()
{
    int ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == 'W')
            {
                ans++;
                dfs(i, j);
            }
        }
    cout << ans << endl;
    return 0;
}