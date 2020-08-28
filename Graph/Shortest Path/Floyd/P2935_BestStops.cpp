#include <bits/stdc++.h>

using namespace std;
const int MAXN = 505, inf = 0x3f3f3f;
int d[MAXN][MAXN], fav[MAXN];
int main()
{
    memset(d,inf,sizeof d);
    int n, m, p;
    cin >> n >> p >> m;
    for (int i = 1; i <= p; ++i)
        cin >> fav[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i == j)
                d[i][j] = 0;
    while(m--)
    {
        int u ,v,w;
        cin>>u>>v>>w;
        d[u][v]=d[v][u]=w;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int ans = inf,res;
    for(int i =1;i<=n;++i)
    {
        int sum=0;
        for(int j = 1;j<=p;j++)
        {
            sum+=d[i][fav[j]];
        }
        // ans=min(ans,sum);
        if(sum<ans)
        {
            ans=sum;
            res=i;
        }
    }
    cout<<res<<endl;

    return 0;
}