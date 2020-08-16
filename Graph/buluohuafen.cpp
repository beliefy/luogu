#include <bits/stdc++.h>
using namespace std;
int n, m, x[1010], y[1010], idx, p[1010];
struct edge
{
    int from, to, val;
} a[1000010];
inline int cmp(edge a, edge b)
{ 
    return a.val < b.val;
}
inline int find(int x)
{
    return p[x] == x ? x : find(p[x]);
}
inline int f(int x)
{
    for (int i = x; i <= idx; i++)
    {
        int q = find(a[i].from), w = find(a[i].to);
        if (q != w)
        { 
            return a[i].val;
        }
    }
}
inline int Krustral()
{ 
    for (register int i = 1; i <= n; i++)
        p[i] = i;
    int k = n;
    sort(a + 1, a + 1 + idx, cmp);
    for (register int i = 1; i <= idx; i++)
    {
        if (k == m)
        { 
            return f(i);
        }
        int q = find(a[i].from), w = find(a[i].to);
        if (q != w)
        {
            p[q] = w;
            k--;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            idx++;
            a[idx].from = i;
            a[idx].to = j;
            a[idx].val = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
        }
    }
    
    double ans = sqrt(Krustral());
    printf("%0.2lf", ans);
    return 0;
}