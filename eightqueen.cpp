#include<cstdio>
#include<iostream>
using namespace std;
int ans[14],vis[3][28]={0},sum=0,n;
void search(int cur)
{
    if(cur>n)
    {
        sum++;
        if(sum>3) return;
        else
        {
            for(int i=1;i<=n;i++) printf("%d ",ans[i]);
            printf("\n");
            return;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if((!vis[0][i])&&(!vis[1][cur+i])&&(!vis[2][cur-i+n]))
        {
            ans[cur]=i;
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
            search(cur+1);
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    search(1);
    printf("%d",sum);
    return 0;
}