#include <bits/stdc++.h>

using namespace std;
const int N = 20;
int m[N][N];
int a, b;
int ans = 0;
void dfs(int x, int y)
{
    if (x == a && y == b)
    {
        ans++;
        return;
    }
    else if (m[x][y] != -1)
    {
        dfs(x + 1, y);
        dfs(x, y + 1);
    }
}
int main()
{
    memset(m, -1, sizeof(m));
    cin >> a >> b;
    int n;
    cin >> n;
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
            m[i][j] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        m[x][y] = -1;
    }
    dfs(1, 1);
    cout<<ans<<endl;
    return 0;
}