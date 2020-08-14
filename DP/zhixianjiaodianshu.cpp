#include <bits/stdc++.h>
using namespace std;

int n, ans = 0, mp;
bool dp[30][400];

int main()
{
    cin >> n;
    mp = (n - 1) * n / 2;
    for (int i = 1; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= mp; j++)
            for (int k = 1; k <= n - i; k++)
                dp[i + k][j + k * i] |= dp[i][j];
    for (int i = 0; i <= mp; i++)
        if (dp[n][i])
            ans++;
    cout << ans;
    return 0;
}