#include <bits/stdc++.h>
using namespace std;
int sum, k;        //累加和
bool vis[102];     //白蓝点
int n, dis[102];   //记边
int f[102][102];   //记图
long long ans = 0; //权值
void Prim()
{
    //开始时全是蓝点
    memset(vis, true, sizeof(vis));
    //记为最大值
    memset(dis, 0x7f, sizeof(dis));
    //将1设为最小生成树的根，距离为0
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int h = 0;
        //找出与i点相连的所有点中边权最小的点
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] && dis[j] < dis[h])
            {
                h = j;
            }
        }
        //加上
        ans += dis[h];
        //把h点记为白点
        vis[h] = false;
        //修改所有蓝点到生成树的距离
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] && f[h][j] < dis[j])
            {
                dis[j] = f[h][j];
            }
        }
    }
}
int main()
{
    //输入，不用多说。
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        f[x][y] = f[y][x] = z;
        sum += z; //累加，后面有用
    }
    //一定要记住这一段，将没赋值的边设为无穷大
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && f[i][j] == 0)
            {
                f[i][j] = 1e9;
            }
        }
    }
    Prim(); //Prim算法
    //因为要输出的是删除的边，
    //所以要用总和减去最小生成树的值
    cout << sum - ans;
    return 0;
}