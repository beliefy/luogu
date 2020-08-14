#include <bits/stdc++.h>
using namespace std;

long long n, k,sum;
long long a[1000005];

bool canl(long long maxlen)
{
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i] / maxlen;
    }
    return ans >= k;
}

int main()
{

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i],sum+=a[i];

    long long l = 0, r = 100000001;
    long long mid;

    // while (l + 1 < r)
    // {
    //     mid = (l + r) / 2;
    //     if (canl(mid))
    //         l = mid;
    //     else
    //         r = mid;
    // }
    if(l<1)
    {
        cout<<0<<endl;
        return 0;
    }
    cout << l << endl;
    return 0;
}