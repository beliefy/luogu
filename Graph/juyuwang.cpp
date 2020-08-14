#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int inf = 0x7fffffff;
struct node
{
    int u, v, w;
  
} a[N];
int p[N], ans; //并查集
int x;
int n, m;
int find(int x)
{
    return p[x]==x?x:find(p[x]);
}
int cmp(node a, node x)
{
    return a.w < x.w;
}
void kruskal()
{               
    int sum = 0; 
    for (int i = 1; i <= m; i++)
    {

        int x = find(a[i].u);
        int y = find(a[i].v);

        if (x==y)
            continue;          
        p[x] = y; 
        ans += a[i].w;             
        sum++;
        if (sum == n - 1)
            break; 
    }
}
signed main()
{
    int x, y, z, sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i; 
    }
    for (int i = 1; i <= m; i++)
    {
        cin>>x>>y>>z;
        a[i].u = x;
        a[i].v = y;
        a[i].w = z;
        sum += z; 
    }
    sort(a + 1, a + m + 1, cmp); 
    kruskal();
    cout << sum - ans << endl; 
    return 0;
}