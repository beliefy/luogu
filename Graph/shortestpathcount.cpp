#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define maxn 1000000+1
#define maxn1 4000000+1
#define mod 100003
using namespace std;
inline int qread()                      
{
    char c=getchar();int num=0,f=1;
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) num=num*10+c-'0';
    return num*f;
}
int n,m,dis[maxn],head[maxn],s,ans[maxn],num;     
struct Edge
{
    int v,w,nxt;
}edge[maxn1];
inline void ct(int u,int v,int w)          
{
    edge[++num].v=v;
    edge[num].w=w;
    edge[num].nxt=head[u];
    head[u]=num;
}
struct node
{
    int x,y;
    bool operator < (const node &a) const            
    {
        return y>a.y;
    }
};
void dijkstra()
{
    memset(dis,0x3f,sizeof(dis));             
    dis[1]=0;
    priority_queue<node>q;
    ans[1]=1;                           
    q.push((node){1,0});
    node a;
    while(!q.empty())                            
    {
        a=q.top();                              
        int u=a.x,d=a.y;                       
        q.pop();
        if(d!=dis[u]) continue;                   
        for(int i=head[u];i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(d+edge[i].w==dis[v])
              ans[v]=(ans[u]+ans[v])%mod;            
            if((dis[v]>dis[u]+edge[i].w))
            {
                dis[v]=dis[u]+edge[i].w;
                ans[v]=ans[u];                      
                q.push((node){v,dis[v]});
            }
        }
    }
}
int main()
{
    n=qread(),m=qread();
    for(int i=1,u,v;i<=m;++i)
    {
        u=qread(),v=qread();
        ct(u,v,1);                          
        ct(v,u,1);
    }
    dijkstra();
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<'\n';                   
    cout<<'\n';
    return 0;
}