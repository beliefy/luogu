#include<bits/stdc++.h>

using namespace std;
#define LL long long
int n;
set<LL>gen;
int main()
{
    cin>>n;
    gen.insert(1);
    set<LL>::iterator it=gen.begin();
    for(int i=1;i<=n;++i)
    {
        LL u=*it;
        gen.insert(u*2),gen.insert(u*3),gen.insert(u*5),gen.insert(u*7);
        it++;
    }
    it--;
    cout<<*it<<endl;
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> parent of 7c8312c... 整理
