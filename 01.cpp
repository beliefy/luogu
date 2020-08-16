#include <bits/stdc++.h>
using namespace std;

int s, p;
int x[510], y[510];
double dis[510][510];
int cnt;
int f[50010];
int pos[500010];

double dist(int x, int y, int i, int j)
{
    return sqrt((abs(x - i) * abs(x - i)) + ((abs(y - j)) * (abs(y - j))));
}

struct node
{
    int x;
    int y;
    double v;
} e[500010];

bool cmp(node a, node b)
{
    return a.v < b.v;
}

int find(int x)
{
    return f[x] == x ? x : find(f[x]);
}


int main()
{
    freopen("D:\\materials\\vccode\\luogu\\Graph\\P1991_3.in", "r", stdin);
    cin >> s >> p;
    for (int i = 1; i <= p; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            if (i == j)
                dis[i][j] = 0x3f3f3f3f;
            else
                dis[i][j] = dist(x[i], y[i], x[j], y[j]);
            cnt++;
            e[cnt].x = i;
            e[cnt].y = j;
            e[cnt].v = dis[i][j];
        }
    }
    for (int i = 1; i <= p; i++)
        f[i] = i;

    sort(e + 1, e + 1 + cnt, cmp);

    int k = 0; 
    for (int i = 1; i <= cnt; i++)
    {
        int x = e[i].x, y = e[i].y;
        if (find(x) != find(y))
        {
            f[find(x)] = find(y);
            k++;
            pos[k] = i;
        }
        if (k == p - 1)
            break;
    }
    cout << e[pos[p - s]].v << endl;
    return 0;
}