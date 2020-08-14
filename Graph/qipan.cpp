#include <bits/stdc++.h>

using namespace std;
const int N = 105, inf = 0x3f3f3f3f;
int maps[N][N];
int direct[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n, m;
int cost[N][N];
int ans = inf;

void dfs(int x, int y, int sum, int flag)
{
    if (x < 1 || x > m || y < 1 || y > m)
        return;
    if (sum >= cost[x][y])
        return;
    cost[x][y] = sum;
    if (x == m && y == m)
    {
        ans = min(ans, sum);
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        int xx = direct[i][0] + x;
        int yy = direct[i][1] + y;
        if (xx < 1 || xx > m || yy < 1 || yy > m)
            continue;
        if (maps[xx][yy] != -1)
        {

            if (maps[xx][yy] == maps[x][y])
            {
                dfs(xx, yy, sum, 0);
            }
            else
            {
                dfs(xx, yy, sum + 1, 0);
            }
        }
        else
        {
            if (flag == 0)
            {
                maps[xx][yy] = maps[x][y];
                dfs(xx, yy, sum + 2, 1);
                maps[xx][yy] = -1;
            }
        }
    }
}

int main()
{
    memset(maps, -1, sizeof maps);
    memset(cost, inf, sizeof cost);

    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        maps[x][y] = z;
    }
    dfs(1, 1, 0, 0);

    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}

/*
12 40
1 1 1
1 3 0
2 6 1
2 1 0
2 4 1
2 3 0
3 8 0
3 6 1
3 3 1
4 4 0
4 1 0
4 3 1
4 8 1
5 3 1
5 4 1
5 2 0
5 9 0
5 6 1
6 5 1
6 9 0
7 9 0
7 5 1
7 1 1
7 3 1
8 8 0
8 12 0
9 7 0
9 10 1
9 3 0
9 12 1
10 6 0
10 7 1
10 12 1
10 11 1
11 5 1
11 8 0
11 10 0
12 8 1
12 10 1
12 12 0
*/