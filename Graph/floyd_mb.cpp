#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#define INF 1000000 + 10
using namespace std;
int Map[500][500];
int pre[500][500]; //记录当前顶点的 前一个顶点
int n, m;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            Map[i][j] = i == j ? 0 : INF;
            pre[i][j] = j; //初始化
        }
    }
}
void getMap()
{
    int a, b, c;
    while (m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        if (Map[a][b] > c)

        {
            Map[a][b] = c;
            Map[b][a] = c;
        }
    }
}
void floyd()
{
    int i, j, k;
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (Map[i][j] > Map[i][k] + Map[k][j])
                {
                    Map[i][j] = Map[i][k] + Map[k][j];
                    pre[i][j] = pre[i][k]; //记录
                }
            }
        }
    }
}
int main()
{
    int s, e;
    while (scanf("%d %d", &n, &m), n || m)
    {
        init();
        getMap();
        floyd();
        while (scanf("%d%d", &s, &e), s != -1 || e != -1)
        {
            if (s == e)
            {
                printf("从%d到%d的最优路线 : %d\n", s, e, s);
                printf("最小花费 : %d\n", 0);
                continue;
            }
            printf("从%d到%d的最优路线 : %d", s, e, s);
            int now = pre[s][e];
            while (1)
            {
                printf("-->%d", now);
                if (now == e)
                    break;
                now = pre[now][e];
            }
            printf("\n");
            printf("最小花费 : %d\n", Map[s][e]);
        }
    }
    return 0;
}