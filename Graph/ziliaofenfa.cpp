#include<bits/stdc++.h>
using namespace std;
int n, m, fa[100010], ans;
bool vis[100010];
inline int find(int x)
{
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
inline void unionn(int x, int y)
{
    int xx = find(x);
    int yy = find(y);
    if (xx != yy)
        fa[xx] = yy;
    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1, a, b; i <= m; i++)
    {
        cin >> a >> b;
        unionn(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        if(fa[i]==i)
            ans++;
    }
    cout << ans << endl;
    return 0;
}