#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1E6 + 5;
int d[MAXN], rom[MAXN], s[MAXN], t[MAXN], f[MAXN], sum[MAXN];
int n, m;
bool can = false;
bool can_book(int mid)
{
    memset(f, 0, sizeof f);
    for (int i = 1; i <= mid; ++i)
    {
        f[s[i]] += d[i];
        f[t[i] + 1] -= d[i];
    }
    int cur = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + f[i];
        if (sum[i] > rom[i])
        {
            can = false;
            return false;
        }
    }

    return true;
}
int main()
{
    freopen("D:\\materials\\vccode\\luogu\\2fen\\P1083_19.in","r",stdin);
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i)
        cin >> rom[i];
    for (int i = 1; i <= m; ++i)
        cin >> d[i] >> s[i] >> t[i];
    int l = 1, r = m ;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (can_book(mid))
            l = mid+1 ;
        else
            r = mid-1;
    }
    if(l>=m+1) can =true;

    if (can)
        cout << 0 << endl;
    else
        cout << -1 << endl
             << l << endl;

    return 0;
}