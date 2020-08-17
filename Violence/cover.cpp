#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool map[1000][1000];
    int a, b, n, m, r, sum = 0;
    cin >> n >> m >> r;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        for (int x = a - r; x <= a + r; x++)
            for (int y = b - r; y <= b + r; y++)
                if (x >= 1 && x <= n && y >= 1 && y <= n)
                    if (map[x][y] == false && (a - x) * (a - x) + (b - y) * (b - y) <= r * r)
                    {
                        map[x][y] = true;
                        sum++;
                    }
    }
    cout << sum<<endl;
    return 0;
}