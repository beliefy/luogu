#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
bool vis[maxn];
vector<int> num;
int n;
void dfs(int index)
{
    if (index >= n)
    {
        for (int i = 0; i < num.size(); ++i)
            cout  << "    "<< num[i];
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        num.push_back(i);
        vis[i] = true;
        dfs(index + 1);
        num.pop_back();
        vis[i] = false;
    }
}
int main()
{
    cin >> n;
    dfs(0);
    return 0;
}