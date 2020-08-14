#include<bits/stdc++.h>
using namespace std;
int n,sum,j;
int main()
{
    cin>>n;    
    for(int i=1;i<=n/2;i++)
    {
        sum=0;     
        for(j=i;j<n;j++)   
        {
            sum+=j;           
            if(sum==n)
            {
                cout<<i<<' '<<j<<endl;   //输出
                break;    
            }
            else if(sum>n)
            {
                break;
            }
        }
    }
    return 0;
}