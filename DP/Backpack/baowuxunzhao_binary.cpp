#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, m, x, y, z, cnt, f[N], w[N], v[N];//w[]->重量 v[]数量
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &x, &y, &z);//价值 重量 数量
        for (int j = 1; j <= z; j <<= 1)
            v[++cnt] = x * j, w[cnt] = y * j, z -= j;
        if (z)
            v[++cnt] = x * z, w[cnt] = y * z; 
    }

    for (int i = 1; i <= cnt; i++)
        for (int j = m; j >= w[i]; j--)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    printf("%d\n", f[m]);
    return 0;
}