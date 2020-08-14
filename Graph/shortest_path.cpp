#include<cstdio>
#include<algorithm>
using namespace std; 
int f[5001],n,m,k,s,ans,sum[5001];
struct note
{
    int start;
    int end;
    int time;    
};
int cmp(const note &a,const note &b)
{ 
    if(a.time<b.time)
        return 1;
    return 0;
}
struct note x[200001];
int find(int v)
{
    if(f[v]==v)
        return v;
    else
    {
        f[v]=find(f[v]);
        return f[v];
    }
}
void unionn(int v,int u)
{
    int t1,t2;
    t1=find(v);
    t2=find(u);
    if(t1!=t2)
    {
        f[t2]=t1;
        sum[t1]=sum[t2]+sum[t1];
        ans=ans+s;
    }
    return;
}
int main()
{
    int i,flag=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        f[i]=i,sum[i]=1;
    for(i=1;i<=m;i++)
        scanf("%d %d %d",&x[i].start,&x[i].end,&x[i].time);
    sort(x+1,x+1+m,cmp);
    for(i=1;i<=m;i++)
    {
        s=x[i].time;
        unionn(x[i].start,x[i].end);
        if(sum[find(x[i].start)]==n)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("%d",ans);
    else
        printf("orz");
    return 0;
}