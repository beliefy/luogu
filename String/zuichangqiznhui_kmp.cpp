#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define fo1(a, b) for (int a = 0; a < b; ++a)
#define fo2(a, b) for (int a = 1; a <= b; ++a)
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int nxt[15];
vector<int> v[maxn]; //首尾位置
bool vis[maxn];
int ans = 0;
void getnxt(string s2, int l2)
{
    int i = 0, j = 1;
    while (j < l2)
    {
        if (s2[i] == s2[j])
            nxt[j++] = ++i;
        else if (!i)
            nxt[j++] = 0;
        else
            i = nxt[i - 1];
    }
}
void KMP(string s1, string s2, int l1, int l2)
{
    int i = 0, j = 0;
    while (i < l1)
    {
        if (s1[i] == s2[j])
            i++, j++;
        else if (!j)
            i++;
        else
            j = nxt[j - 1];
        if (j == l2)
        {
            v[i - j].push_back(i - j - 1 + l2); //记录首尾位置
            j = nxt[j - 1];
        }
    }
}
void dfs(int x)
{

    int len = v[x].size();
    if (len == 0)
    {
        ans = max(ans, x);
    }
    fo1(i, len)
    {
        if (!vis[v[x][i] + 1])
        { //看看要去的点走没走过
            vis[v[x][i] + 1] = 1;
            dfs(v[x][i] + 1);
        }
    }
}
int main()
{
    string s1, s2[205];
    int l = 0;
    while (cin >> s2[++l])
    {
        if (s2[l] == ".")
            break;
    }
    string t;
    while (cin >> t)
        s1 += t;
    int l1 = s1.size();
    fo2(i, l - 1)
    {
        int l2 = s2[i].size();
        mem(nxt, 0);
        getnxt(s2[i], l2);
        KMP(s1, s2[i], l1, l2);
    }
    mem(vis, 0);
    dfs(0);
    printf("%d\n", ans);
    return 0;
}