#include <bits/stdc++.h>

using namespace std;

char s[10];
int head[30];
struct node
{
    int w, na;
} w[30];

bool cmp(node x, node y) { return x.w > y.w; }

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s);
        int l = strlen(s), ans = 1;
        for (int i = 0; i <= l - 1; ++i)
        {
            if (i == l - 1)
                head[s[0] - 'a'] = 1;
            w[s[l - 1 - i] - 'a'].w += ans;
            w[s[l - 1 - i] - 'a'].na = s[l - 1 - i] - 'a';
            ans *= 10;
        }
    }
    sort(w , w + 10, cmp);
    int pos = 1, vis = 0;
    int ans = 0;
    for (int i = 0; i <= 9; ++i)
    {
        if (!head[w[i].na] && !vis)
            vis = 1;
        else
            ans += w[i].w * pos, pos++;
    }
    cout<<ans<<endl;
    return 0;
}