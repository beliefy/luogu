#include <bits/stdc++.h>

using namespace std;
int num[105], dp[105],dp_rev[105];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        for (int j = 1; j < i; ++j)
        {
            if (num[i] > num[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (int i = n; i >=1; --i)
    {
        dp_rev[i] = 1;
        for (int j = n; j > i; --j)
        {
            if (num[i] > num[j])
            {
                dp_rev[i] = max(dp_rev[i], dp_rev[j] + 1);
            }
        }
    }
    int f[105],m=-1;
    for(int i = 1;i<=n;++i)
    {
        f[i]=dp[i]+dp_rev[i];
        m=max(m,f[i]);
    }
    cout << n - m+1 << endl;
    return 0;
}