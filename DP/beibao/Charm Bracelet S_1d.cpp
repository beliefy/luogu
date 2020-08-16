
#include <bits/stdc++.h>
using namespace std;
int n, v, dp[15000], i, j, c, w;
int main()
{
    cin>>n>>v;
    for (i = 1; i <= n; ++i)
    {
        cin>>c>>w;
        for (j = v; j > 0; j--)
            if (c <= j)
                dp[j] = max(dp[j], dp[j - c] + w); 
    }
    cout<<dp[v]<<endl;
    return 0;
}