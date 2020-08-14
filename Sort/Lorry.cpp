#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
pi a[100005], b[100005];
int t1, t2, num[100005];
int ans, sum, maxi, maxj;
bool cmp(pi a, pi b)
{
    return a.first > b.first;
}
int main()
{
    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
    {
        int opt, x;
        cin >> opt >> x;
        if (opt == 2)
            b[++t2] = make_pair(x, i);
        else
            a[++t1] = make_pair(x, i);
    }
    sort(a + 1, a + t1 + 1, cmp);
    sort(b + 1, b + t2 + 1, cmp);
    for (int i = 1; i <= t2; i++)
    {
        num[i] = num[i - 1] + b[i].first; 
    }
    for (int i = 0; i <= t1 && i <= v; i++)
    {                                 
        int j = min((v - i) / 2, t2);
        sum += a[i].first;
        if (sum + num[j] > ans)
        {
            ans = sum + num[j];
            maxi = i;
            maxj = j;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= maxi; i++)
        cout << a[i].second << ' ';
    for (int i = 1; i <= maxj; i++)
        cout << b[i].second << ' ';
    return 0;
}