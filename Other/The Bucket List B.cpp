#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int a[N];
double average;
int main()
{
    int n;
    cin >>average>> n;
    while (n--)
    {
        int l, r, s;
        cin>>l>>r>>s;
        a[l] += s;
        a[r + 1] -= s;
    }
    int now = 0;
    int ans = 0;
    for (int i = 0; i < 1000; ++i)
    {
        now+=a[i];
        // ans=max(now,ans);
    }
    cout<<now<<endl;
    return 0;
}