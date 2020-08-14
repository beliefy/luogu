#include<bits/stdc++.h>

using namespace std;
// const int N=100;

int cnt = 0;
void dfs(int n,int last ,int left_k)
{
    if(left_k == 1)
    {
        cnt++;
        return;
    }
    for(int i = last;i<=n/left_k;++i)
        dfs(n-i,i,left_k-1);

}


int main()
{
    int n,k;
    cin>>n>>k;
    dfs(n,1,k);
    cout<<cnt<<endl;
    return 0;
}