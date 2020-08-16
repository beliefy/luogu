#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int mod = 2017, maxn = 1e2 + 5;
LL n, k, m;
struct matrix
{
    LL a[maxn][maxn];
} p, ans;

matrix mul(matrix x, matrix y)
{
    matrix box;
    for (LL i = 0; i <= n; i++)
        for (LL j = 0; j <= n; j++)
            box.a[i][j] = 0;
    for (LL i = 0; i <= n; i++)
        for (LL j = 0; j <= n; j++)
            for (LL k = 0; k <= n; k++)
                box.a[i][j] = (box.a[i][j] + (x.a[i][k] * y.a[k][j]) % mod) % mod; 
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
    cin >> n >> m;
    for (LL i = 0; i <= n; i++)
        for (LL j = 0; j <= n; j++)
        {
            p.a[i][j]=0;
            if(i==j)p.a[i][j]=1;
            if(j==0&&i!=0)p.a[i][j]=1;
        }

    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        p.a[x][y] = p.a[y][x] = 1;
    }
    cin>>k;

    ans = quick_pow(k);
    int res=0;
        for (LL j = 0; j <= n; j++)
        {
            // cout << ans.a[i][j] << " ";
            res+=ans.a[1][j];
            res=res%mod;
        }
        // cout << endl;
    
    cout<<res<<endl;
    return 0;
}