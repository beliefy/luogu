#include <bits/stdc++.h>
using namespace std;
queue<int> cur;
priority_queue<int, vector<int>, greater<int> > qgreater;
priority_queue<int, vector<int>, less<int> > qless;
vector<int> maps[500001];
int ind1[500001], ind2[500001];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        maps[u].push_back(v);
        ind1[v]++;
        ind2[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ind1[i] == 0)
        {
            qgreater.push(i);
            qless.push(i);
        }
    }
    //"最优情况"
    int maxn = 0, ans = 0;
    while (!qgreater.empty())
    {
        int x = qgreater.top();
        qgreater.pop();
        if (x > maxn)
            ans++;
        maxn = max(maxn, x);
        for (int j = 0; j < maps[x].size(); j++)
        {
            int y = maps[x][j];
            ind1[y]--;
            if (!ind1[y])

                qgreater.push(y);
        }
    }
    cout << ans << endl;
    //"最劣情况"
    maxn = 0, ans = 0;
    while (!qless.empty())
    {
        int x = qless.top();
        if (x > maxn)
            ans++;
        while (!qless.empty())
        {
            cur.push(qless.top());
            qless.pop();
        }
        while (!cur.empty())
        {
            int nx = cur.front();
            cur.pop();
            maxn = max(maxn, nx);
            for (int j = 0; j < maps[nx].size(); j++)
            {
                int y = maps[nx][j];
                ind2[y]--;
                if (!ind2[y])
                {
                    if (y > maxn)
                        qless.push(y);
                    else
                        cur.push(y);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}