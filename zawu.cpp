#include <bits/stdc++.h>
using namespace std;
const int maxsize = 10005;
int n, work[maxsize] = {0}, cost[maxsize] = {0}, a[maxsize][110] = {0}, sum[maxsize] = {0}, f[maxsize] = {0};

int wok(int k)
{
    int ans = 0;
    for (int i = 1; i <= sum[k]; i++)
        ans = max(ans, f[a[k][i]]);
    return ans + cost[k];
}

int main()
{
    int x;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> work[i] >> cost[i];
        cin >> x;
        while (x != 0)
        {
            sum[i]++;
            a[i][sum[i]] = x;
            cin >> x;
        }
    }
    for (int i = 1; i <= n; i++)
        f[i] = wok(i);
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
