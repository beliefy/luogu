#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N=1e3+5,mod=100003;
int m, n, k, map[N][N], f[N][N];

int dfs(int x, int y)
{
    if (x > n || y > n || map[x][y])
        return 0; //边界条件和能否走通
    if (x == n && y == n)
        return 1; //如果到了学校答案+1
    if (f[x][y] != -1)
        return f[x][y]%mod;                             //记忆化的标准剪枝
    return f[x][y] = (dfs(x + 1, y) + dfs(x, y + 1))%mod; //两种方案
}

int main()
{
    cin >> n ;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y; //也是坑！！！
        map[x][y] = 1; //标记障碍
    }
    memset(f, -1, sizeof(f)); //初始化
    cout << dfs(1, 1)%mod;        //dfs函数返回的是答案
    return 0;
}