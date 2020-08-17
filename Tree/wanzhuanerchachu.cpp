#include <bits/stdc++.h>
using namespace std;
const int M = 111111;
int midt[M];
int pret[M];
int dt[M];
int pos = 1, n;
queue<int> q;
void rebuild(int l, int r, int rt)
{
    //	printf("%d %d %d    %d\n",l,r,rt,pret[pos]);
    if (l > r) //子树为空的情况
    {
        dt[rt] = -1;
        return;
    }
    int root = pret[pos++]; //这里pos++就能做到在前序遍历中找到对应的根节点
    dt[rt] = root;
    int m = find(midt + l, midt + 1 + r, root) - (midt + 1) + 1;
    rebuild(l, m - 1, rt << 1);     //重建左子树 ,不包括中点（根节点）。
    rebuild(m + 1, r, rt << 1 | 1); //重建右子树
}
void bfs()
{
    int rt = 1;
    q.push(rt);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        if (dt[now] != -1) //二叉树的叶子节点都是-1，所以不会无限BFS下去
        {
            if (now != 1)
                cout << " ";
            cout << dt[now];
            q.push(now << 1 | 1); //先把右子树加入队列
            q.push(now << 1);     //再把左子树加入队列
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> midt[i];
    for (int i = 1; i <= n; i++)
        cin >> pret[i];
    rebuild(1, n, 1);
    bfs();
    puts("");
    return 0;
}