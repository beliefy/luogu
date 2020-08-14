#include<bits/stdc++.h>

using namespace std;

const int N=3e5+10;
int n,m,a[N],b[N];
long long ans;

int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;++i) cin>>a[i];
    for(int i = 1;i<=m;++i) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    ans= (long long)a[1]*(m-1)+(long long)b[1]*(n-1);
    int x,y,r,c;
    x=y=2;
    r=c=1;
    while(x<=n&&y<=m)
    {
        if(a[x]<=b[y])
            ans+=(long long)a[x++]*(m-r),c++;
        else
            ans+=(long long)b[y++]*(n-c),r++;
    }
    cout<<ans<<endl;
    return 0;
}