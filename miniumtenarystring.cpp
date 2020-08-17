#include <bits/stdc++.h>

using namespace std;

int n, cnt, pos;
string dat, ans;

int main()
{
    cin >> dat;
    for (int i = 0; i < dat.size(); ++i)
    {
        if (dat[i] == '1')
        {
            ++cnt;
            continue;
        }
        ans += dat[i];
    }
    pos = ans.size();
    for (int i = 0; i < ans.size(); ++i)
    {
        if (ans[i] == '2')
        {
            pos = i;
            break;
        }
    }
    while (cnt--)
    {
        ans.insert(ans.begin() + pos, '1');
    }
    cout << ans << endl;
    return 0;
}
