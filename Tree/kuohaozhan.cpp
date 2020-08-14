#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define N 500005

using namespace std;

int n;
char c[N];
int head[N], nxt[N], to[N], cnt, p[N];
ll lst[N], sum[N], ans;
int s[N], top;

void add(int u, int v)
{
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void dfs(int x)
{
    int flag = 0;
    if (c[x] == ')')
    {
        if (top)
        {
            flag = s[top];
            lst[x] = lst[p[flag]] + 1;
            --top;
        }
    }
    else if (c[x] == '(')
        s[++top] = x;
    sum[x] = sum[p[x]] + lst[x];
    for (int i = head[x]; i; i = nxt[i])
        dfs(to[i]); 
  
    if (flag != 0)
        s[++top] = flag; 
    else
    {
        if(top!=0) --top;
    } 
}

int main()
{
    cin>>n;
    scanf("%s", c + 1);
    for (int i = 2; i <= n; i++)
    {
        int f;
        cin>>f;
        add(f, i);
        p[i] = f;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        ans ^= sum[i] * (ll)i;
    cout<<ans<<endl;
    return 0;
}