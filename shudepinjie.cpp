#include <bits/stdc++.h>

using namespace std;

string a[11];
bool cmp(const string &a, const string &b)
{
    return a + b < b + a;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1,cmp);
    for (int i = n; i >= 1; --i)
    {
        cout << a[i];
    }
    return 0;
}