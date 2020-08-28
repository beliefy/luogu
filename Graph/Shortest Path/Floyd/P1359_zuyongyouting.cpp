#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 205;
int a[N][N];
int dis[N][N] = {inf};
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i == j)
                dis[i][j] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
            cin >> dis[i][j];
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    cout << dis[1][n] << endl;
    return 0;
}