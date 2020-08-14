#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int maxn = 221;
vector<pair<int, int> > e[maxn];
int d, p, c, f, s, a, b, g, dis[maxn], inque[maxn];
queue<int> q;
int ans = inf;

void spfa()
{
    q.push(s);
    dis[s] = -d;
    inque[s] = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        inque[now] = 0;
        for (int i = 0; i < e[now].size(); i++)
        {
            int v = e[now][i].first;
            if (dis[v] > dis[now] + e[now][i].second)
            {
                dis[v] = dis[now] + e[now][i].second;
                if (!inque[v])
                {
                    q.push(v);
                    inque[v] = 1;
                }
            }
        }
    }
}
int main()
{
    cin >> d >> p >> c >> f >> s;
    for (int i = 1; i <= c; i++)
    {
        dis[i] = inf;
        inque[i] = 0;
    }
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b;
        e[a].push_back(make_pair(b, -d));
    }
    for (int i = 0; i < f; i++)
    {
        cin >> a >> b >> g;
        e[a].push_back(make_pair(b, g - d));
    }
    spfa();
    for (int i = 1; i <= c; i++)
        ans = min(ans, dis[i]);

    cout << -ans << endl;
    return 0;
}
