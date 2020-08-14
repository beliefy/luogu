#include <bits/stdc++.h>
using namespace std;

const int maxsize = 5000 + 5;

int n, m;
bool dis[maxsize][maxsize];
int  ans[maxsize], cnt;
bool b[maxsize];

void dfs(int now)
{
    ans[++cnt] = now;
    b[now] = true;
    for (int i = 1; i <= n; i++)
    {
        if (b[i])
            continue;
        if (!dis[now][i])
            continue;
        b[i] = true;
        dfs(i);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        dis[x][y] = dis[y][x] = true;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}