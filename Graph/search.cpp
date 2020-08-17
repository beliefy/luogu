#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
bool maps[55][55], visted[MAXN][55][55];
int step[MAXN], direct[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void dfs(int dep, int x, int y)
{
    if (visted[dep][x][y])
        return;
    visted[dep][x][y] = 1;
    if (dep == 0)
        return;
    while (1)
    {
        x += direct[step[dep]][0];
        y += direct[step[dep]][1];
        if (!maps[x][y])
            break;
        dfs(dep - 1, x, y);
    }
}
int main()
{
    int n, m, sx, sy;
    cin >> n >> m;
    char c;
    string s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            if (c == '.')
                maps[i][j] = 1;
            if (c == '*')
                maps[i][j] = 1, sx = i, sy = j;
        }

    int k;
    cin >> k;
    for (int i = k; i > 0; i--)
    {
        cin >> s;
        if (s[0] == 'S')
            step[i] = 0;
        if (s[0] == 'E')
            step[i] = 1;
        if (s[0] == 'N')
            step[i] = 2;
        if (s[0] == 'W')
            step[i] = 3;
    }
    dfs(k, sx, sy);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char t;
            if (visted[0][i][j])
                t = '*';
            else
            {
                if (maps[i][j])
                    t = '.';
                else
                    t = 'X';
            }
            cout << t;
        }
        cout << endl;
    }
    return 0;
}