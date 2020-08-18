#include <bits/stdc++.h>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;
const int MAXN = 200005,inf=0x3f3f3f3f;
int MOD, m, t, tree[MAXN << 2], n;
void build(int l, int r, int rt)
{
    if (l == r)
    {
        tree[rt] = -inf;
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(lson);
    build(rson);
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);

}
void update(int add, int loc, int l, int r, int rt)
{
    if (r == loc && l == loc)
    {
        tree[rt] = add;
        return;
    }
    int mid = l + ((r - l) >> 1); 
    if (loc <= mid)
        update(add, loc, lson);
    else
        update(add, loc, rson);
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);

}
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return tree[rt];
    }
    int mid = l + ((r - l) >> 1);
    int q = -inf;
    if (L <= mid)
    {
        q = max(q, query(L, R, lson));
    }
    if (mid < R)
        q = max(q, query(L, R, rson));
    return q;
}
int main()
{
    cin >> m >> MOD;
    build(1, m, 1);
    for (int i = 1; i <= m; i++)
    {
        char c;
        cin >> c;
        int k;
        cin >> k;
        if (c == 'A')
        {
            n++;
            k = ((long long)k + t) % MOD; //注意防止溢出
            update(k, n, 1, m, 1);
        }
        else
        {
            t = query(n - k + 1, n, 1, m, 1);
            cout << t << endl;
        }
    }
    return 0;
}