#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int max_city=100005;
int n,m,cnt;
int indegree[max_city],f[max_city],a[max_city];
//三个数组分别表示：入度、dp数组、拓扑序列
struct node
{
    int to,next;
}edge[max_city<<2];
int head[max_city],sum;

void add(const int& x,const int& y)
{
    edge[++sum].next=head[x];
    edge[sum].to=y;
    head[x]=sum;
}



void topo_sort(void)//按上面教程说得来就行了
{
    queue <int> q;
    for(int i=1;i<=n;i++)
     if(!indegree[i])//初始化队列
      q.push(i);
    while(!q.empty())
    {
        const int tmp=q.front();
        q.pop();
        a[++cnt]=tmp;//把队列里的入度为0的点存进拓扑序列
        for(int i=head[tmp];i!=0;i=edge[i].next)//遍历一遍图
        {
            const int now=edge[i].to;
            indegree[now]--;
            if(!indegree[now])
             q.push(now);
        }
    }
}

void dp(void)
{
    for(int i=1;i<=n;i++)
     f[i]=1;//每个城市到本身都至少有1条路线
    for(int i=1;i<=n;i++)//每个城市都遍历一遍
    {
        const int tmp=a[i];//注意遍历的是拓扑序列里的城市，此时保证tmp是now的前驱
        for(int j=head[tmp];j!=0;j=edge[j].next)//遍历图
        {
            const int now=edge[j].to;
            f[now]=max(f[now],f[tmp]+1);//把有关联的城市都max一下
        }
    }   
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        indegree[y]++;
    }
    topo_sort();
    dp();
    for(int i=1;i<=n;i++)
     printf("%d\n",f[i]);
    return 0;
}