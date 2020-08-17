#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
long long dp[maxn], k[maxn], c[maxn], n, m, qb;
int main()
{
    int i, j, p;
    cin >> n >> m; //n个英雄 ,至少到达M种
    for (i = 1; i <= n; i++)
        cin >> k[i];
    for (i = 1; i <= n; i++)
        cin >> c[i], qb += c[i] * k[i];
    dp[0] = 1;
    for (i = 1; i <= n; i++)//枚举物品
        for (j = qb; j >= 0; j--)//枚举体积
            for (p = 0; p <= k[i] && p * c[i] <= j; p++) //皮肤总数 总金钱数  //枚举物品个数
                dp[j] = max(dp[j], dp[j - p * c[i]] * p);
    long long ans = 0;
    while (ans <= qb && dp[ans] < m)
        ans++;
    cout << ans << endl;
    return 0;
}