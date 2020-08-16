#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int M = 1e8, maxn = 3;
LL n = 2, k;
struct matrix
{
    LL a[maxn][maxn];
} p, ans;

matrix mul(matrix a, matrix b)
{
    matrix box;
    for (LL i = 1; i <= n; i++)
        for (LL j = 1; j <= n; j++)
            box.a[i][j] = 0;
    for (LL i = 1; i <= n; i++)
        for (LL j = 1; j <= n; j++)
            for (LL k = 1; k <= n; k++)
                box.a[i][j] = (box.a[i][j] + (a.a[i][k] * b.a[k][j]) % M) % M; //注意取模
                // (box.a[i][j]+=a.a[i][k]*b.a[k][j]%M)%=M;
    return box;
}
matrix quick_pow(LL k)
{
    matrix ans;
    for (LL i = 1; i <= n; i++)
        ans.a[i][i] = 1;
    while (k)
    {
        if (k & 1)
            ans = mul(ans, p);
        k >>= 2;
        p = mul(p, p);
    }
    return ans;
}
LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}
    LL a, b;
int main()
{
    cin >> a >> b;
    LL k = gcd(a, b);
    p.a[1][1] = p.a[1][2] = p.a[2][1] = 1;
    p.a[2][2] = 0;

    ans = quick_pow(k - 1);
    for (LL i = 1; i <= n; i++)
    {
        for (LL j = 1; j <= n; j++)
        {
            cout << ans.a[i][j] << " ";
        }
        cout << endl;
    }
    if (k <= 2)
    {
        cout << 1 << endl;
        return 0;
    }
    cout << ans.a[1][1] << endl;
    return 0;
}