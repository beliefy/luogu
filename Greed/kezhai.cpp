#include <bits/stdc++.h>

using namespace std;
const int maxn=55;
int n, k, p;
int color, price;
int last[maxn];
int sum[maxn];
int cnt[maxn];
int ans = 0;
int cur;
int main()
{
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> color >> price;
        if (price <= p)
            cur = i;
        if (cur >= last[color])
            sum[color] = cnt[color];
        last[color] = i;
        ans += sum[color];
        cnt[color]++;
    }
    cout << ans << endl;
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> parent of 7c8312c... 整理
