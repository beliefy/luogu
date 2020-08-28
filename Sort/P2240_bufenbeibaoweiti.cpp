#include <bits/stdc++.h>

using namespace std;
struct node
{
    int c, v;
    double per_v;
} a[1005];
bool cmp(node a, node b)
{
    return a.per_v >= b.per_v;
}
int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].c >> a[i].v;
        a[i].per_v = (double)a[i].v / a[i].c;
    }

    sort(a + 1, a + 1 + n, cmp);
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << a[i].per_v << endl;
    // }
    int sum = 0;
     double ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (sum == t)
            break;
        if (sum > t)
        {
            ans -= (sum - t) * a[i-1].per_v;
            break;
        }
        sum += a[i].c;
        ans += a[i].v;
    }
    cout.setf(ios::fixed);
    cout <<fixed<<setprecision(2)<< ans << endl;
    return 0;
}