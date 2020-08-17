#include <bits/stdc++.h>
using namespace std;
int n, p[39], dp[47][47], i, j, k, root[49][49];
void print(int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        printf("%d ", l);
        return;
    }
    printf("%d ", root[l][r]);
    print(l, root[l][r] - 1);
    print(root[l][r] + 1, r);
}
int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> p[i];
    for (i = 1; i <= n; i++)
    {
        dp[i][i] = p[i];
        dp[i][i - 1] = 1;
    }
    for (i = n; i >= 1; i--)
        for (j = i + 1; j <= n; j++)
            for (k = i; k <= j; k++)
            {
                if (dp[i][j] < (dp[i][k - 1] * dp[k + 1][j] + dp[k][k]))
                {
                    dp[i][j] = dp[i][k - 1] * dp[k + 1][j] + dp[k][k];
                    root[i][j] = k;
                }
            }
    cout << dp[1][n] << endl;
    print(1, n);
    return 0;
}