#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

int n, tot = 1, head[N], a[N], fa[N], re[N];
ll ans, cnt[N];
char temp[N];

struct Edge
{
    int to, next;
} e[N << 1];
void add(int x, int y)
{
    e[tot].to = y, e[tot].next = head[x], head[x] = tot++;
}

void dfs(int x, int f)
{
    cnt[x] += cnt[f], fa[x] = f;
    if (a[x] == 1)
    {
        while (a[f] != -1 && re[f] != -1)
            f = fa[re[f]];
        if (f == 0 || a[f] == 1)
            re[x] = -1;
        else
            re[x] = f, cnt[x] += cnt[fa[f]] - cnt[fa[fa[f]]] + 1;
    }
    else
        re[x] = -1;
    for (int i = head[x]; i; i = e[i].next)
        dfs(e[i].to, x);
}

int main()
{
    cin >> n;
    cin >> temp;
    for (int i = 1; i <= n; i++)
    {
        if (temp[i - 1] == '(')
            a[i] = -1;
        else
            a[i] = 1;
    }
    for (int i = 2, f; i <= n; i++)
    {
        cin >> f;
        add(f, i);
    }
    re[0] = -1;
    dfs(1, 0);

    for (ll i = 1; i <= n; i++)
        ans ^= (cnt[i] * i);
    cout << ans << endl;

    return 0;
}