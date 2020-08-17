#include <bits/stdc++.h>
using namespace std;
int can_reach, sx, sy, dx, dy, d[5], EW, SN, t;
char ch;
int main()
{
    cin >> sx >> sy >> dx >> dy;
    EW = dx - sx, SN = dy - sy;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> ch;
        if (ch == 'N')
            d[1] += 1;
        if (ch == 'S')
            d[2] += 1;
        if (ch == 'W')
            d[3] += 1;
        if (ch == 'E')
            d[4] += 1;
    };
    if ((EW) && (d[4] >= EW))
    {
        if ((SN) && (d[1] >= SN))
            can_reach = 1;
        if ((!SN) && (d[2] + SN >= 0))
            can_reach = 1;
    }
    if ((!EW) && (d[3] + EW >= 0))
    {
        if ((SN) && (d[1] >= SN))
            can_reach = 1;
        if ((!SN) && (d[2] + SN >= 0))
            can_reach = 1;
    }
    int ans = abs(EW) + abs(SN);
    if (can_reach)
        cout << (abs(EW) + abs(SN));
    else
        cout << -1;
    return 0;
}