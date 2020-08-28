#include <bits/stdc++.h>
using namespace std;
struct node //前向星存边
{
    int to;     
    int w;   
    int nxt; //与它最近的父节点一样的边的编号
} e[1000000];
int head[20000]; //以某点为父节点引出的最后一条边
int cnt = 0;
bool visit[20000] = {0}; //是否作为过起点
long long dis[20000];    //距离
int n, m, s;
inline void add(int a, int b, int c) //存边
{
    cnt++;
    e[cnt].to = b;
    e[cnt].w = c;
    e[cnt].nxt = head[a];
    head[a] = cnt; //更新head
}
int main()
{
    cin>>n>>m>>s;
    for (int i = 1; i <= n; i++)
        dis[i] = 2147483647;
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u, v, w);
    }
    int curr = s;
    dis[s] = 0;
    long long minn;
    while (!visit[curr]) //即搜完整张图
    {
        visit[curr] = true;                                 //已做为过起点
        for (int i = head[curr]; i; i = e[i].nxt) //链式前向星搜边
        {
            if (!visit[e[i].to] && dis[e[i].to] > dis[curr] + e[i].w)
                dis[e[i].to] = dis[curr] + e[i].w; //更新操作
        }
        minn = 2147483647;
        for (int i = 1; i <= n; i++)
        {
            if (!visit[i] && minn > dis[i]) //取新的最小值
            {
                minn = dis[i];
                curr = i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    return 0;
}