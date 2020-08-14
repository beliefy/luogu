#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int N=1e6+5;

int a[N];
int main()
{
    int cnt =0;
    // memset(a,inf,sizeof a);
    int n,m,p;
    cin>>n>>m>>p;
    while(n--)
    {
        int x;
        cin>>x;
        while(x--)
        {
            int y ;
            cin>>y;
            a[y]++;
        }
    }
    vector<int> b;
    for(int i = 1;i<=m;++i)
    {
        if(a[i]==p)
        {
             cnt++;
            //  cout<<i<<" ";
            b.push_back(i);
        }
    }
    cout<<cnt<<endl;
    // sort(b.begin(),b.end());
    for(int i=0;i<b.size();i++)
    {
        cout<<b[i]<<" ";
    }
    return  0;
}