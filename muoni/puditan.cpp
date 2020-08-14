#include <bits/stdc++.h>

using namespace std;

const int N = 1E4 + 5;
int m[N][5];
int main()
{
    // freopen("D:\\materials\\vccode\\luogu\\muomi\\P1003_2.in", "r", stdin);
    // freopen("P1003_2.in", "r", stdin);

    int n;
    cin >> n;
    for (int k = 1; k <= n; ++k)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        // for (int i = x; i <= x + a && i < N; i++)
        // {
        //     for (int j = y; j <= y + b && j < N; j++)
        //     {
        //         m[i][j] = k;
        //     }
        // }
        m[k][1] = x, m[k][2] = y, m[k][3] = a, m[k][4] = b;
    }
    int x, y;
    cin >> x >> y;
    for (int i = n; i >= 1; --i)
    {
        if (x >= m[i][1] && x <= m[i][1] + m[i][3])
        {
            if (y >= m[i][2] && y <= m[i][2] + m[i][4])
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }
    // int x, y;
    // cin >> x >> y;
    // cout << m[x][y] << endl;
    // for(int i =)
    return 0;
}