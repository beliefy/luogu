#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int maxsize = 2e5 + 5;

int p[maxsize];
int ans = inf;
int n;
int find(int x, int &cnt)
{
    cnt++;
    return p[x] == x ? x : find(p[x], cnt);
}
void init()
{
    for (int i = 1; i <= n; ++i)
        p[i] = i;
}
int main()
{
    cin >> n;
    init();
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        int x;
        cin >> x;
        if (find(x, cnt) == i)
            ans = min(ans, cnt);
        else
            p[i] = x;
    }
    cout << ans;
    return 0;
}