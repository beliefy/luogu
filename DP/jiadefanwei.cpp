#include <bits/stdc++.h>

using namespace std;
const int N = 105;
int a[N][N], sum[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int ans = 1;
    int l = 2;
    while (l <= n)
    {
        for (int i = l; i <= n; ++i)
            for (int j = l; j <= n; ++j)
            {
                if (sum[i][j] - sum[i - l][j] - sum[i][j - l] + sum[i-l][j-l] == l * l)
                {
                    ans = max(ans, l);
                }
            }
        l++;
    }
    cout<<ans<<endl;
    return 0;
}