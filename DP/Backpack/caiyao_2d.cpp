#include <bits/stdc++.h>
using namespace std;
int cost[105], val[105];
int dp[105][1005];
int main()
{
    int c, n;
    cin >> c >> n;
    for (int i = 1; i <= n; i++)
        cin >> cost[i] >> val[i];
    for (int i = 1; i <= n; i++)
        for (int j = c; j >= 0; j--)
        {
            if (j >= cost[i])
                dp[i][j] = max(dp[i - 1][j - cost[i]] + val[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    cout << dp[n][c] << endl;
    return 0;
}