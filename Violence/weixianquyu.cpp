#include<bits/stdc++.h>
using namespace std;
int n, m, k, t, x, y, ans, maxn = 0;  
double dis(int x, int y, int a, int b) 
{
    return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}
int main()
{
    cin>>n>>m>>k>>t;
    while(k--)
    {
        ans = 0;             
        cin>>x>>y;
        for (int i = max(x - t, 1); i <= min(n, x + t); ++i)
        { 
            for (int j = max(y - t, 1); j <= min(m, y + t); ++j)
            {
                if (dis(i, j, x, y) <= t)
                    ans++;               
            }
        }
            maxn=max(maxn,ans);
    }
    cout<<maxn<<endl;
    return 0;          
}