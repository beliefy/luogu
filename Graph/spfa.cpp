#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int M = 10005;

struct A
{
    int y, time, next;
} a[M << 1];

int head[M], cnt = 0; //链式前向星数组
int vis[M], ven[M], nums[M];

//SPFS数组，vis记录最短路，ven记录是否在队列，nums记录入队次数

void add(int x, int y, int k) //链式前向星，加入节点
{
    a[cnt].y = y, a[cnt].time = k, a[cnt].next = head[x];
    head[x] = cnt++;
}

bool SPFA(int s, int n)
{
    queue<int> q;
    memset(vis, inf, sizeof(vis));
    memset(ven, 0, sizeof(ven));
    memset(nums, 0, sizeof(nums));
    vis[s] = 0;            //初始化距离
    ven[s] = 1, nums[s]++; //标记s节点在队列，队列次数+1
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();                                //出队
        ven[x] = 0;                             //标记不在队列
        for (int i = head[x]; ~i; i = a[i].next) //遍历与x节点连通的点
        {
            int y = a[i].y;
            if (vis[y] > vis[x] + a[i].time) //更新
            {
                vis[y] = vis[x] + a[i].time;
                if (!ven[y])
                //由于更新了节点，所以后续以这个为基础的最短路，也要更新下
                //所以如果在队列就不用加入，不在的话加入更新后续节点
                {
                    q.push(y);
                    ven[y] = 1;      //标记这个节点在队列中
                    nums[y]++;       //记录加入次数
                    if (nums[y] > n) //如果这个点加入超过n次，说明存在负圈，直接返回
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n, m, t;
    int b[M], c[M];
    while (cin >> n >> m >> t)
    {
        cnt = 0;
        memset(head, -1, sizeof(head));
        for (int i = 0; i < n; i++)
        {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, y, k);
            add(y, x, k);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < t; i++)
        {
            cin >> c[i];
        }
        int minn = inf;
        for (int i = 0; i < m; i++) //遍历多个找寻最小
        {
            SPFA(b[i], n);
            for (int j = 0; j < t; j++)
                minn = min(minn, vis[c[j]]);
        }
        cout << minn << endl;
    }
}