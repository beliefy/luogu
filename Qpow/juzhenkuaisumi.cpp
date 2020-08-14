#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int mod = 1e9 + 7,maxn=1e2+5;
LL n, k; 
struct matrix
{
    LL a[maxn][maxn];
} p, ans;

matrix mul(matrix x, matrix y)
{
    matrix box;
    for (LL i = 1; i <= n; i++)
        for (LL j = 1; j <= n; j++)
            box.a[i][j] = 0; 
    for (LL i = 1; i <= n; i++)
        for (LL j = 1; j <= n; j++)
            for (LL k = 1; k <= n; k++)
                box.a[i][j] = (box.a[i][j] + (x.a[i][k] * y.a[k][j]) % mod) % mod; //注意取模
    return box;
}
matrix quick_pow(LL k)
{
    matrix ans;
    for (LL i = 1; i <= n; i++)
        ans.a[i][i] = 1;
    //将对角线全赋值为1，A矩阵与这个矩阵相乘，结果是A矩阵本身
    //其实呢，可以直接将ans矩阵赋值为p，然后乘方次数剪1是一样的
    while (k)
    {
        if (k % 2)
        {
            ans = mul(ans, p);
        }
        k >>= 1;
        p = mul(p, p);
    } 
    return ans;
}
int main()
{
    cin >> n >> k;
    for (LL i = 1; i <= n; i++)
        for (LL j = 1; j <= n; j++)
            cin>>p.a[i][j];

    ans = quick_pow(k);
    for (LL i = 1; i <= n; i++)
    {
        for (LL j = 1; j <= n; j++)
        {
            cout << ans.a[i][j] << " ";
        }
        cout << endl;
    } 
    return 0;
}