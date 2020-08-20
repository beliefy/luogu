#include <bits/stdc++.h>
using namespace std;
int p[7001], n, ans;
struct node
{
    int x1, y1, x2, y2;
} pos[7001];
int find(int a)
{
    return a == p[a] ? a : p[a] = find(p[a]);
}
bool check(node a, node b)
{
    if ((a.x2 < b.x1 || b.x2 < a.x1) || (a.y2 < b.y1 || b.y2 < a.y1))
        return false;
    if ((a.x1 == b.x2 || a.x2 == b.x1) && (a.y1 == b.y2 || a.y2 == b.y1))
        return false; 
    return true;     
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> pos[i].x1 >> pos[i].y1 >> pos[i].x2 >> pos[i].y2;
        for (int j = 1; j <= i - 1; ++j)
            if (check(pos[i], pos[j]) && find(i) != find(j))
            {
                int u = find(i), pos = find(j);
                p[u] = pos;
            }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] == i)
            ans++;
    }
    cout << ans << endl;
    return 0;
}