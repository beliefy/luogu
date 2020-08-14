#include <bits/stdc++.h>

using namespace std;
const int maxn = 1010;
int n, flag;
int pr[maxn];
vector<int> v;

void judge(int l, int r)
{
    if (l > r)
        return;
    int tl = l + 1, tr = r;
    if (!flag)
    {
        while (tl <= r && pr[tl] < pr[l])
            tl++;
        while (tr > l && pr[tr] >= pr[l])
            tr--;
    }
    else
    {
        while (tl <= r && pr[tl] >= pr[l])
            tl++;
        while (tr > l && pr[tr] < pr[l])
            tr--;
    }
    if (tl - tr != 1)
        return;
    judge(l + 1, tr);
    judge(tl, r);
    v.push_back(pr[l]);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pr[i];
    judge(0, n - 1);
    if (v.size() != n)
    {
        flag = 1;
        v.clear();
        judge(0, n - 1);
    }
    if (v.size() != n)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            printf("%d%c", v[i], i == (n - 1) ? '\n' : ' ');
    }
    return 0;
}