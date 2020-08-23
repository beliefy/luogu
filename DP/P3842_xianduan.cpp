#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 5;
int n;
int l[MAXN], r[MAXN];
int f[MAXN][2];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    f[1][0] = 2 * r[1] - l[1] - 1; 
    f[1][1] = r[1] - 1;           
    for (int i = 2; i <= n; i++)
    {
        f[i][1] = min(f[i - 1][1] + abs(l[i] - r[i - 1]) + r[i] - l[i] + 1, f[i - 1][0] + abs(l[i] - l[i - 1]) + r[i] - l[i] + 1); //本行走到右端点，上一行走到左/右端点，取最小值
        f[i][0] = min(f[i - 1][1] + abs(r[i] - r[i - 1]) + r[i] - l[i] + 1, f[i - 1][0] + abs(r[i] - l[i - 1]) + r[i] - l[i] + 1); //本行走到左端点，上一行走到左/右端点，取最小值
    }
    cout << n + min(f[n][1] - r[n], f[n][0] - l[n]);
    return 0;
}