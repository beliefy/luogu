#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int dp[N];
int pos, ans = 0;
int main()
{
    string s;
    s += " ";
    cin >> s;
    for (int i = 1; i <= s.length(); ++i)
    {
        if (s[i] == '(' || s[i] == '[')
            continue;
        else if (s[i] == ')' && s[i - dp[i - 1] - 1] == '(')
        {
            dp[i] = dp[i - 1] + 2 + dp[i - 2 - dp[i - 1]];
            if (dp[i] > ans)
            {
                ans = dp[i];
                pos = i;
            }
        }
        else if (s[i] == ']' && s[i - 1 - dp[i - 1]] == '[')
        {
            dp[i] = dp[i - 1] + 2 + dp[i - 2 - dp[i - 1]];
            if (dp[i] > ans)
            {
                ans = dp[i];
                pos = i;
            }
        }
    }

    for(int i = pos-ans+1;i<=pos;++i)
    {
        cout<<s[i];
    }

    return 0;
}