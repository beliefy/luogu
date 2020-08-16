#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int mod = 2017;
struct Matrix
{
    int a[31][31];
    inline Matrix operator*(const Matrix &rhs)
    {
        Matrix ret;
        memset(&ret, 0, sizeof ret);
        for (int i = 0; i <= 30; i++)
            for (int j = 0; j <= 30; j++)
                for (int k = 0; k <= 30; k++)
                    (ret.a[i][j] += a[i][k] * rhs.a[k][j] % mod) %= mod;
        return ret;
    }
} mp;
Matrix ksm(Matrix &a, int k)
{
    Matrix ret;
    memset(&ret, 0, sizeof ret);
    for (int i = 0; i <= 30; i++)
        ret.a[i][i] = 1;
    while (k)
    {
        if (k & 1)
            ret = ret * a;
        a = a * a;
        k >>= 1;
    }
    return ret;
}
int u, v, n, m, t;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        mp.a[u][v] = 1;
        mp.a[v][u] = 1;
    }
    for (int i = 0; i <= n; i++)
        mp.a[i][i] = 1;
    for (int i = 1; i <= n; i++)
        mp.a[i][0] = 1;
    int ans = 0;
    scanf("%d", &t);
    Matrix anss = ksm(mp, t);
    for (int i = 0; i <= n; i++)
        (ans += anss.a[1][i]) %= mod;
    printf("%d\n", ans);
    return 0;
}