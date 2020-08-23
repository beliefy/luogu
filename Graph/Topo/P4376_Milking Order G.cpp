#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar())
        if (ch == '-')
            f = -1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return x * f;
}
const int N = 1e5, M = 5e4;
int nxt[(N << 1) + 10], head[N + 10], child[(N << 1) + 10], inde[N + 10];
int dfn[N + 10], low[N + 10], sta[N + 10], num[N + 10], milk[N + 10];
bool instack[N + 10];
int tot, Time, top, cnt, n, m;
vector<int> vec[M + 10];
struct node
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define fa (p >> 1)
    int Q[N + 10], len;
    void insert(int x)
    {
        Q[++len] = x;
        int p = len;
        while (p != 1 && Q[p] < Q[fa])
            swap(Q[p], Q[fa]), p = fa;
    }
    int Get()
    {
        int Ans = Q[1], p = 1, son;
        Q[1] = Q[len--];
        while (ls <= len)
        {
            if (rs > len || Q[ls] < Q[rs])
                son = ls;
            else
                son = rs;
            if (Q[p] > Q[son])
                swap(Q[p], Q[son]), p = son;
            else
                break;
        }
        return Ans;
    }
} Heap;
void add(int x, int y)
{
    nxt[++tot] = head[x], head[x] = tot, child[tot] = y, inde[y]++;
}
void tarjan(int x)
{
    dfn[x] = low[x] = ++Time;
    instack[sta[++top] = x] = 1;
    for (int p = head[x], son = child[p]; p; p = nxt[p], son = child[p])
    {
        if (!dfn[son])
            tarjan(son), low[x] = min(low[x], low[son]);
        else if (instack[son])
            low[x] = min(low[x], dfn[son]);
    }
    if (dfn[x] == low[x])
    {
        instack[x] = 0, num[x] = ++cnt;
        while (sta[top] != x)
            instack[sta[top]] = 0, num[sta[top--]] = cnt;
        top--;
    }
}
void init()
{
    tot = Time = cnt = 0;
    memset(inde, 0, sizeof(inde));
    memset(head, 0, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
}
bool check(int x)
{
    init();
    for (int i = 1; i <= x; i++)
        for (int j = 1; j < (int)vec[i].size(); j++)
            add(vec[i][j - 1], vec[i][j]);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    return cnt == n;
}
void topo()
{
    int T = 0;
    for (int i = 1; i <= n; i++)
        if (!inde[i])
            Heap.insert(i);
    while (Heap.len)
    {
        int x = (milk[++T] = Heap.Get());
        for (int p = head[x], son = child[p]; p; p = nxt[p], son = child[p])
            if (!--inde[son])
                Heap.insert(son);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int j;
        cin >> j;
        while (j--)
        {
            int x;
            cin>>x;
            vec[i].push_back(x);
        }
    }
    int l = 1, r = m, res = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            res = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    init();
    for (int i = 1; i <= res; i++)
        for (int j = 1; j < (int)vec[i].size(); j++)
            add(vec[i][j - 1], vec[i][j]);
    topo();
    for (int i = 1; i <= n; i++)
        printf("%d", milk[i]), i == n ? putchar('\n') : putchar(' ');
    return 0;
}