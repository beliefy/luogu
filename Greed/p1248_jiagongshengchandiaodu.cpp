#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;
struct node
{
    int a;
    int b;
    int c;
} stuff[MAXN];
bool cmp(node x, node y)
{
    return min(x.a, y.b) < min(y.a, x.b);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> stuff[i].a;
        stuff[i].c = i;
    }
    for (int i = 1; i <= n; ++i)
        cin >> stuff[i].b;
    int ans=0;
    int A=0;
    sort(stuff + 1, stuff + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
    {
        A += stuff[i].a;
        ans = max(A, ans) + stuff[i].b;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i)
        cout << stuff[i].c << " ";
    return 0;
}