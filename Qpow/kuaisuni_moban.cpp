#include <bits/stdc++.h>

using namespace std;

long long b, p, k;
long long ans = 1;
long long qpow(long long a, long long b, long long c)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % c;
        a = a * a%c;
        b >>= 1;
    }
    return ans;
}
int main()
{
    cin >> b >> p >> k;
    cout << b << "^" << p << " mod " << k << "=" << qpow(b, p, k) %k<< endl;
    return 0;
}