#include <bits/stdc++.h>
using namespace std;
bool prime[100],vis[100];
int n,a[100],ind;
void dfs(int cur){
    if(cur==n+1&&prime[a[1]+a[n]]){
        for(int i = 1;i<=n;++i)
        {
            printf("%d",a[i]);
            if(i!=n)printf(" ");
        }
        puts("");
        return;
    }
    for(int i = 2;i<=n;++i)
    {
        if(prime[i+a[cur-1]]&&!vis[i])
        {
            vis[i]=true;
            a[cur]=i;
            dfs(cur+1);
            vis[i]=false;
        }
    }
}
int main(){
    prime[2]=prime[3]=prime[5]=prime[7]=prime[11]=prime[13]=prime[17]=prime[19]=prime[23]=prime[29]=prime[31]=true;  //每日打表心情好
    bool isf=false;
    while(scanf("%d",&n)!=EOF){
        a[1]=1;
        if(isf)puts("");
        isf=true;
        printf("Case %d:\n",++ind);
        memset(vis,false,sizeof(vis));
        dfs(2);
    }
    return 0;
}