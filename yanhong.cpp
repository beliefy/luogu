#include<bits/stdc++.h>

using namespace std;

#define maxsize 100000010

map<int,bool> ma;

int a[100000010],b[100000010];
int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n;++i) cin>>a[i];
    for(int i = 0;i<m;++i) 
    {
        cin>>b[i];
        ma[b[i]]=true;
    }
    for(int i =0;i<n;++i)
    {
        if(ma[a[i]]==true)
            cout<<a[i]<<" ";
    }

    return 0;

}