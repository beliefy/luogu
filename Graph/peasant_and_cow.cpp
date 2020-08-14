#include <bits/stdc++.h>
using namespace std;
char m[12][12];
int farmer[3], cow[3], ans, flag;
bool visit[160005];
void move(int x, int y, int mi, int h)
{
    if (mi == 0)
    {
        if (m[x - 1][y] == '*')
            if (h == 0)
                farmer[0] = 1;
            else
                cow[0] = 1;
        else if (h == 0)
            farmer[1]--;
        else
            cow[1]--;
    }
    else if (mi == 1)
    {
        if (m[x][y + 1] == '*')
            if (h == 0)
                farmer[0] = 2;
            else
                cow[0] = 2;
        else if (h == 0)
            farmer[2]++;
        else
            cow[2]++;
    }
    else if (mi == 2)
    {
        if (m[x + 1][y] == '*')
            if (h == 0)
                farmer[0] = 3;
            else
                cow[0] = 3;
        else if (h == 0)
            farmer[1]++;
        else
            cow[1]++;
    }
    else
    {
        if (m[x][y - 1] == '*')
            if (h == 0)
                farmer[0] = 0;
            else
                cow[0] = 0;
        else if (h == 0)
            farmer[2]--;
        else
            cow[2]--;
    }
}
bool judge()
{
    if (farmer[1] == cow[1] && farmer[2] == cow[2])
        return 0;
    else
        return 1;
}
int main()
{
    for (int i = 0; i <= 11; i++)
        m[i][0] = '*', m[i][11] = '*';
    for (int i = 1; i <= 11; i++)
        m[0][i] = '*', m[11][i] = '*';
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == 'F')
                farmer[1] = i, farmer[2] = j;
            if (m[i][j] == 'C')
                cow[1] = i, cow[2] = j;
        }
    }
    while (judge())
    {
        flag = farmer[1] + farmer[2] * 10 + cow[1] * 100 + cow[2] * 1000 + farmer[0] * 10000 + cow[0] * 40000;
        if (visit[flag])
        {
            cout << 0 << endl;
            return 0;
        }
        visit[flag] = 1;
        move(farmer[1], farmer[2], farmer[0], 0);
        move(cow[1], cow[2], cow[0], 1);
        ans++;
    }
    cout << ans << endl;
    return 0;
}