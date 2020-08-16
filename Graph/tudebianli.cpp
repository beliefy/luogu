#include <bits/stdc++.h>
using namespace std;
int n, m, i;
const int maxsize = 1e5+5;
//u、v和w的数组大小要根据实际情况来设置，要比m的最大值要大1
int u[maxsize], v[maxsize];
//first和next的数组大小要根据实际情况来设置，要比n的最大值要大1
int first[maxsize], nxt[maxsize];
int main()
{
    scanf("%d %d", &n, &m);
    //初始化first数组下标1~n的值为-1，表示1~n顶点暂时都没有边
    for (i = 1; i <= n; i++)
        first[i] = -1;
    for (i = 1; i <= m; i++)
    {
        scanf("%d %d", &u[i], &v[i]); //读入每一条边
        //下面两句是关键啦
        nxt[i] = first[u[i]];
        first[u[i]] = i;
    }
    int ans[maxsize];
    memset(ans,0,sizeof(ans));
    for (i = 1; i <= n; i++)
    {
        int k = first[i];
        while (k != -1)
        {
            printf("%d %d\n", u[k], v[k]);
            ans[i]=max(ans[i],k);
            k = nxt[k];
        }
    }
    // for(int i = 1;i<=n;++i) cout<<ans[i]<<" ";
    return 0;
}
