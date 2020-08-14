#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long ans;
int a[N], b[N];
int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
    { 
        cin >> a[i] >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > b[i])
            ans += (a[i] - b[i]) * y;
        if (a[i] < b[i])
            ans += (b[i] - a[i]) * x;
    }
    cout << ans << endl;
    return 0;
}