#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n, a[maxn], r[maxn];
long long ans = 0;
void merge_sort(int x, int y)
{
    int i, j, k, m;
    if (x == y)
        return;
    m = x + (y - x) / 2;
    merge_sort(x, m);
    merge_sort(m + 1, y);
    i = x, j = m + 1, k = x;
    while (i <= m && j <= y)
    {
        if (a[i] <= a[j])
            r[k++] = a[i++];
        else
        {
            r[k++] = a[j++];
            ans += m - i + 1;
        }
    }
    while (i <= m)
    {
        r[k++] = a[i++];
    }
    while (j <= y)
    {
        r[k++] = a[j++];
    }
    for (int i = x; i <= y; i++)
        a[i] = r[i];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    merge_sort(1, n);
    cout << ans << endl;
    return 0;
}