#include <bits/stdc++.h>
using namespace std;
const int M = 1e8; //模数
long long x, y;
struct matrix
{
    long long m[2][2];
};
int gcd(int a1, int a2) //求gcd的步骤
{
    return a2 == 0 ? a1 : gcd(a2, a1 % a2);
}
matrix a = {1, 1, 1, 0};
matrix I = {1, 0, 0, 1};
matrix mul(matrix a, matrix b) //矩阵乘法
{
    matrix c;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            c.m[i][j] = 0;
            for (int k = 0; k <= 1; k++)
            {
                (c.m[i][j] += a.m[i][k] * b.m[k][j] % M) %= M;
            }
        }
    }
    return c;
}
matrix quick_pow(long long k) //矩阵快速幂主要过程
{
    matrix ans = I, p = a;
    while (k)
    {
        if (k & 1)
            ans = mul(ans, p);
        p = mul(p, p);
        k >>= 1;
    }
    return ans;
}
int main()
{
    cin >> x >> y;
    matrix ans = quick_pow(gcd(x, y) - 1); //计算答案
    cout << ans.m[0][0] << endl;
    return 0;
}