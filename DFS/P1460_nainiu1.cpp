#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;
#define INF 0x3f3f3f3f
#define N 100
int v, n, mink = INF, lenth;             //v,g如题，minn存答案长度，lenth存当前长度
int vet[N], food[N][N], save[N], ans[N]; //vet存每种维生素最少需要量，food存每种食物可以提供维生素的多少，save存已经选择的饲料，ans存答案选择c的饲料种类
bool vis[N];                             //标记
bool canfini(int lenth)
{ //判断当前是否已经满足牛牛维生素的需求量
    int t[N];
    memset(t, 0, sizeof(t)); //一定要初始化，我因为没有初始化卡了好久！！！
    for (int i = 1; i <= lenth; i++)
    {
        for (int l = 1; l <= v; l++)
            t[l] += food[save[i]][l]; //存食物提供给牛牛的维生素
    }
    for (int i = 1; i <= v; i++)
    {
        if (t[i] < vet[i])
            return false; //如果有一种维生素不够就返回false
    }
    return true; //每种维生素都够了就返回true
}
void dfs()
{
    if (lenth > n || lenth > mink)
        return; //剪枝优化m，如果选择的饲料种类超过了一共有的饲料种类，或是选择的种类已经超过了之前的最优解
    if (canfini(lenth))
    { //如果满足了每种维生素的需求量
        if (mink > lenth)
        { //如果当前解最优
            mink = lenth;
            for (int i = 1; i <= mink; i++)
                ans[i] = save[i]; //存储答案
        }
        return; //结束
    }
    int start = save[lenth]; //从上一步以选择的饲料开始选择，可避免出现1，2，3和3，2，1的情况，特别重要，不然会T两个点
    if (start == 0)
        start = 0;
    for (int i = start; i <= n; i++)
    { //枚举选择的饲料种类
        if (vis[i] == false)
        {                    //如果未被选择过
            vis[i] = true;   //标记已被选择
            lenth++;         //答案长度++
            save[lenth] = i; //存储答案
            dfs();           //递归进行下一次选择
            vis[i] = false;  //回溯时还原
            save[lenth] = 0;
            lenth--;
        }
    }
}
int main()
{
    scanf("%d", &v);
    for (int i = 1; i <= v; i++)
        scanf("%d", &vet[i]);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int l = 1; l <= v; l++)
            scanf("%d", &food[i][l]); //输入
    dfs();
    printf("%d ", mink);
    for (int i = 1; i <= mink; i++)
        printf("%d ", ans[i]); //输出
    return 0;
}