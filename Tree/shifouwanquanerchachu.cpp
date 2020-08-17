#include<bits/stdc++.h>
using namespace std;
vector<int> tree(1009);
void build(int root, int val)
{
    if (!tree[root])
    {
        tree[root] = val;
    }
    else if (val > tree[root])
    {
        build(root << 1, val);
    }
    else
        build(root << 1 | 1, val);
}
int main(void)
{
    int n, t;
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin >> t, build(1, t);
    int flag = 0, cnt;
    for (int i = 1; i < 1009; i++)
    {
        if (tree[i])
        {
            if (flag)
                cout << " ";
            else
                flag = 1;
            cout << tree[i];
            cnt = i;
        }
    }
    if (cnt > n)
        cout << endl
             << "NO" << endl;
    else
        cout << endl
             << "YES" << endl;
    return 0;
}