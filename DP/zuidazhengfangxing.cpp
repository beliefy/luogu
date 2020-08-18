#include <bits/stdc++.h>

using namespace std;
const int N = 255;
int a[N][N], sum[N][N],res[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin>>s;
        for (int j = 1; j <= n; ++j)
        {
            // cin >> a[i][j];
            a[i][j]=s[j-1]-'0';
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int ans = 1;
    bool f[N]={false};
    int l = 2;
    int ml = min(n, n);
    while (l <= ml)
    {
        for (int i = l; i <= n; ++i)
            for (int j = l; j <= n; ++j)
            {
                if (sum[i][j] - sum[i - l][j] - sum[i][j - l] + sum[i-l][j-l] == l * l)
                {
                    ans = max(ans, l);
                    f[ans]=true;
                    res[ans]++;
                }
            }
        l++;
    }
    // cout<<ans<<endl;
    for(int i = 1;i<=n;++i)
    {
        if(f[i])
        {
            cout<<i<<" "<<res[i]<<endl;
        }
    }
    return 0;
}