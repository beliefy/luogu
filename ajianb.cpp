#include <bits/stdc++.h>
using namespace std;
long a[200005];
long N, C, ans;
int main()
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N);
    for (int i = 0; i < N; i++)
    {
        ans += ((upper_bound(a, a + N, a[i] + C) - a) - (lower_bound(a, a + N, a[i] + C) - a));
    }
    cout << ans;
    return 0;
}