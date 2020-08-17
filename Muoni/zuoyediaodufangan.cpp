#include <bits/stdc++.h>

using namespace std;
int m, n;
int t[25][25], sequence[625], serial[25][25];
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n * m; ++i)
    {
        cin >> sequence[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> serial[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> t[i][j];
        }
    }

    return 0;
}