#include <bits/stdc++.h>
#define mod 4147
using namespace std;
const int MAXN = 105;
int n, m, w[MAXN], a[MAXN];
struct Matrix
{ 
    int val[MAXN][MAXN];
    Matrix() { memset(val,0,sizeof(val)); }
    int *operator[](int x) { return val[x]; }
    Matrix operator*(Matrix t)
    {
        Matrix res;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    res[i][j] = (res[i][j] + val[i][k] * t[k][j]) % mod;
        return res;
    }
} ans, p;
void init()
{
    for (int i = 1; i <= n; i++)
        ans[i][1] = w[n - i + 1];
    for (int i = 1; i <= n; i++)
        p[1][i] = a[i];
    for (int i = 2; i <= n; i++)
        p[i][i - 1] = 1;
}
int qpow(int w)
{
    while (w)
    {
        if (w % 2)
            ans = p * ans;
        p = p * p;
        w >>= 1;
    }
    return ans[1][1];
}
int main()
{
    cin >> n >> m;
    for (int i = n; i; i--)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    cout << qpow(m - n)<<endl;
    return 0;
}