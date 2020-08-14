#include<bits/stdc++.h>
using namespace std;
int n, k, x, y, power, dp[100001] , ans;
bool bo[100001];
vector<pair<int,int> > edge[100001]; 
void doit(int x)          
{
    bo[x] = 1;
    dp[x] = 1;
    for (int i = 0; i < edge[x].size(); i++)
        if (!bo[edge[x][i].first])
        {
            if (edge[x][i].second >= power)
                printf("No solution."), exit(0);
            doit(edge[x][i].first);
            if (dp[edge[x][i].first] + edge[x][i].second > power)
                ans++, dp[edge[x][i].first] = 1; 
            dp[x] = max(dp[x], dp[edge[x][i].first] + edge[x][i].second);
        }
}
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>k;
        for (int j = 1; j <= k; j++)
            cin>>x>>y, edge[i].push_back(pair<int,int>(x, y));
    }
    cin>>power;
    doit(1);
    cout<<ans<<endl;
    return 0;
}