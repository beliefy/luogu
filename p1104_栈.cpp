#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
ull a[20]={0,1};
int main()
{
    int n;
    cin>>n;
    for(int i = 2;i<=n;++i)
    {
        a[i]=a[i-1]*(4*i-2)/(i+1);
    }
    cout<<a[n]<<endl;
    return 0;
}