#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int cnt;
struct node
{
    int to, nxt;
} e[N];
int head[N], siz[N];
int n, k;
int ans;
void add(int u, int v)
{
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dfs(int x, int last)
{
    siz[x] = 1;
    for (int i = head[x]; ~i; i = e[i].nxt)
    {
        if (e[i].to != last)
        {
            dfs(e[i].to, x);
            siz[x] += siz[e[i].to];
        }
    }
    if (siz[x] == k)
    {
        siz[x] = 0;
        ans++;
    }
}
int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        memset(head, -1, sizeof(head));
        memset(siz, 0, sizeof(siz));
        cnt = ans = 0;
        cin >> n >> k;
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            add(u, v), add(v, u);
        }
        if (n % k != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        dfs(1, 0);
        if (n / k == ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}