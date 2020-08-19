#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=200001;
ll a[MAXN], f[MAXN][21], t, D;
int Logn[MAXN];
int n, m;   
bool flag;
void pre()
{
    Logn[1] = 0;
    Logn[2] = 1;
    for (int i = 3; i < MAXN; ++i)
    {
        Logn[i] = Logn[i / 2] + 1;
    }
}
void change(int u)
{ 
    f[u][0] = a[u];
    for (int i = 1; u - (1 << i) >= 0; i++)
        f[u][i] = max(f[u][i - 1], f[u - (1 << (i - 1))][i - 1]);
}
ll find(int x, int y)
{
    int K =Logn[y-x+1];
    return max(f[y][K], f[x + (1 << K) - 1][K]);
}
int main()
{
    memset(f, 0, sizeof(f));
    pre();
    scanf("%d%lld", &m, &D);
    for (int i = 1; i <= m; i++)
    {
        char c;
        cin >> c;
        ll x;
        if (c == 'A')
        { 
            scanf("%lld", &x);
            a[++n] = (x + t) % D;
            change(n);
        }
        else
        {
            int L;
            scanf("%d", &L);
            ll ans;
            if (L == 1)
            {
                printf("%lld\n", a[n]);
                t = a[n];
                continue;
            }
            ans = find(n - L + 1, n);
            printf("%lld\n", ans);
            t = ans;
        }
    }
    return 0;
}