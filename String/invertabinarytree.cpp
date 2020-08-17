#include <bits/stdc++.h>
using namespace std;
struct node
{
    int l;
    int r;
} tr[10];
int n, check[10], cnt;
int build(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        char lchild, rchild;
        cin >> lchild >> rchild;
        if (lchild == '-')
            tr[i].l = -1;
        else
        {
            tr[i].l = lchild - '0';
            check[lchild - '0'] = 1;
        }
        if (rchild == '-')
            tr[i].r = -1;
        else
        {
            tr[i].r = rchild - '0';
            check[rchild - '0'] = 1;
        }
    }
    for (i = 0; i < n; i++)
        if (!check[i])
            return i; 
}
void level_order(int t)
{
    queue<int> q;
    int flag = 0;
    q.push(t);
    while (!q.empty())
    {
        int x = q.front();
        if (!flag)
            flag = 1, cout << x; 
        else
            cout << " " << x;
        if (tr[x].r != -1)
            q.push(tr[x].r);
        if (tr[x].l != -1)
            q.push(tr[x].l); 
        q.pop();
    }
    cout << endl;
}
void in_order(int t)
{
    if (t == -1)
        return;
    in_order(tr[t].r);
    cnt++;
    if (cnt == n)
        cout << t << endl;
    else
        cout << t << " ";
    in_order(tr[t].l); 
}
int main()
{
    cin >> n;
    int head = build(n);
    level_order(head);
    in_order(head);
    return 0;
}
