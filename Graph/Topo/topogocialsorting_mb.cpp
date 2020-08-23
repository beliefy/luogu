#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void TopSort(vector<vector<int>> &G, int n, vector<int> &inDegree)
{
    int num = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (size_t i = 0; i < G[u].size(); ++i)
        {
            int v = G[u][i]; // v is the successor vertices of u
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
        G[u].clear(); // clear all out edge of vertices u
        num++;
    }
    cout << endl;

    if (num == n)
    {
        cout << "topological sorting successed";
    }
    else
    {
        cout << "there is a ring in the graph, can't do topological sorting";
    }
    return;
}

int main()
{
    int n, m;
    cout << "please enter # of vertices and edges: ";
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cout << "input the " << i + 1 << " edge: ";
        cin >> x >> y;
        G[x].push_back(y);
    }
    cout << "the topological sorting is: " << endl;
    vector<int> inDegree(n);
    for (auto x : G)
    {
        for (auto y : x)
        {
            inDegree[y]++;
        }
    }
    TopSort(G, n, inDegree);

    return 0;
}