#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int sum=0;
    sum=a+b;
    if(sum>=0)
    {
        string sum_s = to_string(sum);
        for(int i = 0;i<sum_s.length();i++)
        {
            char ss = sum_s[i];
            cout<<ss<<endl;
        }
    }
    else
    {
        string sum_s = to_string(sum);
        for(int i = 0;i<sum_s.length();i++)
        {
            char ss = sum_s[i];
            cout<<ss<<endl;
        }
    }
    return 0;
}