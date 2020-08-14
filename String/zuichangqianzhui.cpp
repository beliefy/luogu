#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
string txt, pattern[205], T;
int nxt[1005], n, m[205], ans = 0;
bool vis[MAXN];

void get_next(int x) 
{
    int j = 0;
    nxt[1] = 0;
    for (int i = 1; i < m[x]; i++)
    {
        while (j > 0 && pattern[x][j + 1] != pattern[x][i + 1])
            j = nxt[j];
        if (pattern[x][j + 1] == pattern[x][i + 1])
            j++;
        nxt[i + 1] = j;
    }
    return;
}
int kmp(int x) 
{
    int j = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && pattern[x][j + 1] != txt[i + 1])
            j = nxt[j];
        if (pattern[x][j + 1] == txt[i + 1])
            j++;
        if (j == m[x])
        {
            for (int k = i + 1 - m[x] + 1; k <= i + 1; k++) 
                vis[k] = 1;
            j = 0; 
        }
    }
    return ans;
}

int main()
{
    int len = 1; 
    memset(vis, 0, sizeof vis);
    while (true)
    {
        cin >> pattern[len];
        pattern[len] = '*' + pattern[len]; 
        m[len] = pattern[len].size() - 1;
        if (pattern[len] == "*.")
        {
            len--;
            break;
        }
        len++;
    }
    cin>>txt;
    txt = '*' + txt; 
    n = txt.size() - 1;
    for (int i = 1; i <= len; i++)
        get_next(i);
    for (int i = 1; i <= len; i++) 
        kmp(i);

    for (int i = 1; i <= n; i++)
        if (vis[i])
            ans++; 
        else
            break;      
    cout << ans << endl; 
    return 0;
}