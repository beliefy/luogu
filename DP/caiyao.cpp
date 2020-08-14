#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
int dp[N], val[N], cost[N];
int main()
{
    int c, n;
    cin >> c >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> cost[i] >> val[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = c; j >= 0; --j)
        {
            if (j >= cost[i])
            {
                dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
            }
        }
    }
    cout << dp[c] << endl;
    return 0;
}