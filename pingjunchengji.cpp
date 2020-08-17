#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double total=0;
    double t_male=0;
    double t_female=0;
    int nan = 0;
    int nv = 0;
    cin>>n;
    for(int i = 0;i<n;++i)
    {
        int score;
        int sex;
        cin>>sex>>score;
        total+=score;   
        if(sex==1)
        {
            t_male+=score;
            nan++;
        }
        else
        {
            t_female+=score;
            nv++;
        }
    }
    if(nan==0)
        cout<<total/n<<" "<<"X "<<t_female/nv<<endl;
    if(nv==0)
        cout<<total/n<<" "<<t_male/nan<<" X "<<endl;
    if(nan!=0 && nv!=0)
        cout<<total/n<<" "<<t_male/nan<<" "<<t_female/nv<<endl;
    return 0;
}
