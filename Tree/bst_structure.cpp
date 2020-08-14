#include <bits/stdc++.h>
#include <cmath>

#define mem(a, b) memset(a, b, sizeof a)
#define ssclr(ss) ss.clear(), ss.str("")
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;

typedef long long ll;

struct node
{
    int data;
    node *left, *right;
};

unordered_map<int, int> lvl;
unordered_map<int, node *> fu;

node *insertBST(node *rt, int d, int l, node *par)
{
    if (rt == NULL)
    {
        rt = new node;
        rt->left = rt->right = NULL;
        rt->data = d;
        lvl[d] = l;
        if (par == NULL)
            par = rt;
        fu[d] = par;
        return rt;
    }

    if (rt->data > d)
        rt->left = insertBST(rt->left, d, l + 1, rt);
    else if (rt->data < d)
        rt->right = insertBST(rt->right, d, l + 1, rt);
}

int main()
{
    int n, a, q, b;
    string ts;
    scanf("%d", &n);
    node *tree = NULL;
    for (int i = 0; i < n; i++)
        scanf("%d", &a),
            tree = insertBST(tree, a, 1, tree);
    scanf("%d", &q);
    while (q--)
    {
        int f = 0, flag = 0;
        cin >> a >> ts;
        if (lvl[a] == 0)
            flag = 1;
        if (ts[0] == 'i')
        {
            cin >> ts >> ts;
            if (ts[1] == 'o')
            {
                if (!flag && fu[a]->data == a)
                    f = 1;
            }
            else if (ts[0] == 'p')
            {
                cin >> ts >> b;
                if (lvl[b] == 0)
                    flag = 1;
                if (!flag && fu[b]->data == a && a != b)
                    f = 1;
            }
            else if (ts[0] == 'l')
            {
                cin >> ts >> ts >> b;
                if (lvl[b] == 0)
                    flag = 1;
                if (!flag && fu[a]->data != a)
                {
                    node *l = fu[a]->left;
                    if (!flag && l != NULL && l->data == a && fu[a]->data == b)
                        f = 1;
                }
            }
            else if (ts[1] == 'i')
            {
                cin >> ts >> ts >> b;
                if (lvl[b] == 0)
                    flag = 1;
                if (!flag && fu[a]->data != a)
                {
                    node *r = fu[a]->right;
                    if (!flag && r != NULL && r->data == a && fu[a]->data == b)
                        f = 1;
                }
            }
        }
        else
        {
            cin >> b;
            getline(cin, ts);
            if (lvl[b] == 0)
                flag = 1;
            if (ts[ts.length() - 1] == 's')
            {
                if (!flag && fu[a] == fu[b])
                    f = 1;
            }
            else
            {
                if (!flag && lvl[a] == lvl[b])
                    f = 1;
            }
        }

        if (flag == 1)
            f = 0;
        puts(f ? "Yes" : "No");
    }

    return 0;
}
