#include <bits/stdc++.h>
using namespace std;
int mid[35], post[35];
struct node
{
    int l, r;
} tree[35];
int build(int pml, int pmr, int ppl, int ppr) //pml,rmid表示中序遍历 ppl,rpost表示后序遍历
{
    if (pml > pmr)
        return 0;
    int root = post[ppr];
    int ml = pml;
    while (mid[ml] != root)
        ml++; //在中序遍历中找到根节点
    int len = ml - pml;
    tree[root].l = build(pml, ml - 1, ppl, ppl + len - 1);
    tree[root].r = build(ml + 1, pmr, ppl + len, ppr - 1);
    return root;
}
void bfs(int x)
{
    queue<int> q;
    vector<int> v;
    q.push(x);
    while (!q.empty())
    {
        int w = q.front();
        q.pop();
        if (!w)
            break;
        v.push_back(w);
        if (tree[w].l)
            q.push(tree[w].l);
        if (tree[w].r)
            q.push(tree[w].r);
    }
    for (int i = 0; i < v.size(); i++)
    {
        string t = (i == v.size()-1)?"":" ";
        cout<<v[i]<<t;
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> mid[i];

    int root = post[n - 1];
    build(0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}