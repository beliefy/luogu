#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int max_v=100;

int main()
{
    int v,e;
    int x,y;//x->y
    int m[max_v][max_v];
    memset(m,0,sizeof(m));
    cin>>v>>e;//输入顶点和边的个数
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;//输入每两个节点的的值表示两个节点之间的边的指向
        m[x][y]=1;//存在有指向的边便赋值为1
    }
    for(int i=0;i<v;i++)//输出邻接矩阵
    {
        for(int j=0;j<v;j++)
            cout<<m[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}