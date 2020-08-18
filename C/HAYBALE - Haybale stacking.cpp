#include <bits/stdc++.h>

using namespace std;
const int N =  1e6+ 5;
int a[N];
int n;
int main()
{
    int k;
    cin >>n>> k;
    while (k--)
    {
        int l, r;
        cin>>l>>r;
        a[l] ++;
        a[r + 1] --;
    }
    // int now;
    int ans[N];
    for (int i = 1; i <= n; ++i)
    {
        // now+=a[i];
        // ans=max(now,ans);
        ans[i]=ans[i-1]+a[i];
    }
    sort(ans+1,ans+n+1);
    cout<<ans[n/2+1]<<endl;
    return 0;
}