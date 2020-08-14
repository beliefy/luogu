#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
long long dp[maxn], k[maxn], c[maxn], n, m, qb;
int main()
{
    int i, j, p;
    cin >> n >> m;
    for (i = 1; i <= n; i++) 
        cin >> k[i];
    for (i = 1; i <= n; i++)
        cin >> c[i], qb += c[i] * k[i];                   
    dp[0] = 1;                                           
    for (i = 1; i <= n; i++)                              
        for (j = qb; j >= 0; j--)                        
            for (p = 0; p <= k[i] && p * c[i] <= j; p++)  
                dp[j] = max(dp[j], dp[j - p * c[i]] * p); 
    long long ans = 0;
    while (ans <= qb && dp[ans] < m)
        ans++; 
    cout << ans << endl;
    return 0;
}