#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, p;
char s[N], od[N];
char ans[N];
int main()
{
    cin >> n >> s + 1 >> p;
    memcpy(od + 1, s + 1, sizeof s);
    sort(od + 1, od + 1 + n);
    int cnt = n;
    for (int i = 1; i <= n; ++i)
        if (od[i] == s[p])
        {
            p = i;
            break;
        }
    while (cnt > 0)
    {
        ans[--cnt] = s[p];
        od[p] = '*';
        for (int i = n; i >= 1; --i)
            if (od[i] == s[p])
            {
                p = i;
                break;
            }
    }
    cout << ans << endl;
    return 0;
}