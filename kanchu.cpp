#include<bits/stdc++.h>

using namespace std;
const int maxsize = 1e6+5;
int n;
long long a[maxsize]; 
long long m,ans;

bool caninc(int x)
{
    long long sum = 0;
    for(int i = 1;i<=n;++i)
    {
        if(a[i]>x)
        {
            sum+=a[i]-x;
        }
    }
    return sum>=m;
}
int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;++i) cin>>a[i];
    long long l = 0,r=1e9;
    while(l+1<r)
    {
        long long mid=l+(r-l)/2;
        if(caninc(mid))
            l=mid;
        else
            r=mid;
    }
    cout<<l<<endl;
    return 0;
}