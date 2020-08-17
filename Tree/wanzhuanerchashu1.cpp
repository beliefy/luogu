#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int pret[31], midt[31];
queue<int> q;
vector<int> v;
vector<int>::iterator it;
struct treenode
{
    int l, r;
} t[31];
int findtree(int a1, int a2, int b1, int b2) //参数表示在数组a，b中的初末位置
{
    int root, pos, i;
    if (a2 - a1 == 0) //长度为1，为叶节点
        return b1;
    if (a2 - a1 < 0)
        return -1;
    root = b1;
    for (i = a1; i <= a2; i++) //在中序遍历中找根节点
        if (midt[root] == pret[i])
        {
            pos = i;
            break;
        }
    t[root].l = findtree(a1, pos - 1, b1 + 1, b1 + pos - a1);
    t[root].r = findtree(pos + 1, a2, b1 + pos - a1 + 1, b2);
    return root; //返回根节点位置
}
void printtree(int n)
{
    int temp;
    q.push(n);
    while (!q.empty()) //队列为空则层序遍历结束
    {
        temp = q.front();
        q.pop();
        v.push_back(midt[temp]); //将根节点放入容器
        if (t[temp].r != -1)
            q.push(t[temp].r);
        if (t[temp].l != -1)
            q.push(t[temp].l); //若左右子节点存在则放入队列
    }
}
int main()
{
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        t[i].l = t[i].r = -1;
        cin >> pret[i];
    }
    for (i = 0; i < n; i++)
        cin >> midt[i];
    findtree(0, n - 1, 0, n - 1); //树的重建
    printtree(0);                 //层序遍历
    cout << *v.begin();
    for (it = v.begin() + 1; it != v.end(); it++)
        cout << ' ' << *it;
    return 0;
}