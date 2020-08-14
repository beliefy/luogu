#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
const int N = 105;
int p[N], dis[N][N], sum;
int n, l, r;
using namespace std;
int main()
{
    cin >> n;
    memset(dis, inf, sizeof(dis));
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
        cin >> p[i];
        cin >> l >> r;
        dis[i][l] = dis[l][i] = dis[i][r] = dis[r][i] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            if (i != k)
                for (int j = 1; j <= n; j++)
                    if (i != j && k != j)
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i != j && dis[i][j] != -1)
                sum += p[j] * dis[i][j];
        }
        ans = min(sum, ans);
    }
    cout << ans << endl;
    return 0;
}