#include <cstdio>
int V, G; //v需要的维他命的种类数,G可用的食物的种数
int a[30]; //存牛每天需要的每种维他命的最小量
int Y[30][30]; //编号为n食物包含的各种维他命的量的多少
int book[20]; //记录尝试过的食物
int m = 1000000, mink; //记录使用最小食物种类
int ans[20]; //输出方案
void memo()
{ //每次尝试一种后 记录尝试的食物
    int tmp = 0;
    for (int i = 1; i <= G; i++)
        if (book[i] == 1)   //
            ans[++tmp] = i; //记录答案
}

//检测 牛所需的每种维他命量 是否满足 有-->true 没-->false
bool finish()
{
    for (int i = 1; i <= V; i++)
        if (a[i] > 0)
            return false;
    return true;
}
//深搜...
void dfs(int x)
{
    //判断是否满足牛所需的每种维他命量,满足后继续
    if (finish())
    {
        //记录使用最小食物种类,及 比较最小的输出方案
        if (mink < m)
        {
            m = mink;
            memo(); //调用flag()记录使用最小食物种类
            return;
        }
    }
    //当可用食物种数<1时，跳出函数
    if (x > G)
        return;
    //二维数组第一个下标(1,1)开始读,及 每种食物中维他命含量的第一个值
    for (int i = 1; i <= V; i++)
        a[i] -= Y[x][i]; //每次读取一个后牛所需的维他命量减少
    book[x] = 1;         //标记已读取过的
    mink++;              //更新min1的值
    dfs(x + 1);
    //回溯到初始状态...
    for (int i = 1; i <= V; i++)
        a[i] += Y[x][i];
    book[x] = 0;
    mink--;
    dfs(x + 1);
}

int main()
{

    scanf("%d", &V);
    for (int i = 1; i <= V; i++)
        scanf("%d", &a[i]);
    scanf("%d", &G);
    for (int i = 1; i <= G; i++)
        for (int j = 1; j <= V; j++)
            scanf("%d", &Y[i][j]);
    dfs(1);
    printf("%d ", m);
    for (int i = 1; i <= m; i++)
        printf("%d ", ans[i]);
    return 0;
}