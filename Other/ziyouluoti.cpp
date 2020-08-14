#include<bits/stdc++.h>
#define ESP 1e-7
using namespace std;
const int N=1e5+4;

double H,S,V,L,K;
int num[N];
int n;
double t1,t2;
double pre;
int cnt = 0;
int main()
{
    memset(num,1,sizeof num);
    cin>>H>>S>>V>>L>>K>>n;
    t2=sqrt(2*(H-K)/(double)10);
    t1=sqrt(2*(H)/(double)10);
    double bac =S-t2*V;
    pre=S-t1*V;
    for(int i = 1;i<=n;++i)
    {
        if(i>=pre-ESP && i-ESP<=bac+L)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

