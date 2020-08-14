#include<bits/stdc++.h>
using namespace std;
long long d, n, x[25], y[25], k[25], ans, cnt;
int main()
{
    cin >> d >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i] >> k[i];
    for (int i = 0; i <= 128; i++)
        for (int j = 0; j <= 128; j++)
        {
            long long c = 0;
            for (int l = 1; l <= n; l++)
                if (abs(x[l] - i) <= d && abs(y[l] - j) <= d)
                    c += k[l];
            if (c == ans)
                cnt++;
            if (c > ans)
                ans = c, cnt = 1;
        }
    cout << cnt << " " << ans << endl;
    return 0;
}