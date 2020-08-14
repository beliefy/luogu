#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005; //点数最大值
int n, m, cnt;         //n个点，m条边
struct Edge
{
    int to, w, next; //终点，边权，同起点的上一条边的编号
} edge[maxn];        //边集
int head[maxn];      //head[i],表示以i为起点的第一条边在边集数组的位置（编号）
void init()          //初始化
{
    for (int i = 0; i <= n; i++)
        head[i] = -1;
    cnt = 0;
}
void add(int u, int v, int w) //加边，u起点，v终点，w边权
{
    edge[cnt].to = v;         //终点
    edge[cnt].w = w;          //权值
    edge[cnt].next = head[u]; //以u为起点上一条边的编号，也就是与这个边起点相同的上一条边的编号
    head[u] = cnt++;          //更新以u为起点上一条边的编号
}
int main()
{
    cin >> n >> m;
    int u, v, w;
    init();                      //初始化
    for (int i = 1; i <= m; i++) //输入m条边
    {
        cin >> u >> v>>w;
        add(u, v, w); //加边
        /*
        加双向边
        add(u, v, w);
        add(v, u, w);
        */
    }
    cout<<endl;
    for (int i = 1; i <= n; i++)                    //n个起点
        for (int j = head[i]; ~j; j = edge[j].next) //遍历以i为起点的边
            cout << i << " " << edge[j].to << " " << edge[j].w << endl;
    return 0;
}
/*
5 7
1 2 1
2 3 2
3 4 3
1 3 4
4 1 5
1 5 6
4 5 7
*/