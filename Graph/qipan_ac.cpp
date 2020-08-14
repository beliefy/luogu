#include<bits/stdc++.h>

using namespace std;

#define MAX 1e9

int m, n;
int Chess[1001][1001]; //棋盘，0表示无色

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int f[1001][1001]; //记忆化：f[i][j]表示到(i, j) 的最小花费

void dfs(int a, int b, int sum, bool can_flog)
{ //坐标(a,b), 花费-sum, 能否使用魔法-can_flog
    if (a < 1 || a > m || b < 1 || b > m)
        return;
    if (sum >= f[a][b])
        return; //根据记忆化 剪枝
    f[a][b] = sum;
    if (a == m && b == m)
        return;
    for (int i = 0; i < 4; i++)
    {
        int next_x = a + dir[i][0];
        int next_y = b + dir[i][1];
        if (next_x < 1 || next_x > m || next_y < 1 || next_y > m)
            continue;
        if (Chess[next_x][next_y] == 0)
        {
            if (!can_flog)
                continue;
            Chess[next_x][next_y] = Chess[a][b]; //把下一个格子变为当前格子的颜色
            dfs(next_x, next_y, sum + 2, false); //不能再用魔法了，can_flog = false
            Chess[next_x][next_y] = 0;           //记得回溯
        }
        else
        {
            if (Chess[next_x][next_y] != Chess[a][b])
                dfs(next_x, next_y, sum + 1, true);
            else if (Chess[next_x][next_y] == Chess[a][b])
                dfs(next_x, next_y, sum, true);
        }
    }
}
int main()
{
    int x, y, color;
    cin >> m >> n;
    memset(f,MAX,sizeof f);
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> color;
        Chess[x][y] = color + 1;
    }
    dfs(1, 1, 0, true);
    if (f[m][m] == MAX)
        f[m][m] = -1; //无法到达
    cout << f[m][m] << endl;
    return 0;
}