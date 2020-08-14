#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = N * 2;
int n;
int head[N], to[M], nxt[M], cnt;
int deg[N], dp[N];
void add(int u, int v)
{
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}
bool check(int x)
{
    return deg[x] == 1 ? true : false;
} 
void dfs(int x,int last)
{
    int sum = 1;
    for (int i = head[x]; ~i; i = nxt[i])
    {
        if (to[i] == last)
            continue;
        //由于为双向边，防止无限递归，所以多记录一个last，表示上次到达的点，如果不是上次到达的点再走
        int j = to[i];
        dfs(j,x);
        if (check(j))
            sum++; //如果是叶子节点，计时器+1
        else
            dp[x] += dp[j];
        //以上为转移转移
    }
    dp[x] += sum / 2; //加上计数器除以二
}
int main()
{
    memset(head, -1, sizeof head);
    cin >> n;
    for (int i = 1; i < n; i++) //n-1条边
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
        deg[u]++, deg[v]++;
    }
    dfs(1,-1);
    cout << dp[1] << endl;
    return 0;
}