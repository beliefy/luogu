#include <bits/stdc++.h>

using namespace std;

string a, b, c_set[300];
int num, n, i, j, k, m, ans, dp[230000], b_len, c_len[300];

int main()
{
    n = 1;
    while (cin >> c_set[n] && c_set[n] != ".")
    {
        n++;
        continue;
    }
    n--;

    while (cin >> a)
    {
        b += a;
    }

    dp[0] = 1;

    b_len = b.size();
    for (i = 1; i <= n; i++)
        c_len[i] = c_set[i].size();

    for (j = 1; j <= b_len; j++)
        for (i = 1; i <= n; i++)
        {
            if (j >= c_len[i] && dp[j - c_len[i]])
            {
                if (c_set[i] == b.substr(j - c_len[i], c_len[i]) || c_set[i] == b.substr(j - c_len[i], c_len[i]))
                {
                    dp[j] = 1;
                    break;
                }
            }
        }

    for (j = b.size(); j >= 0; j--)
        if (dp[j])
        {
            ans = j;
            break;
        }

    cout << ans << endl;
    return 0;
}