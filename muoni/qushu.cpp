#include<bits/stdc++.h>
using namespace std;
int vis[200500];
int main()
{
    int n;
    queue<int> q;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    while (n--)
    {
        int x, cnt = 1;
        cin >> x;
        if (vis[x])
        {
            cout << 0 << ' ';
        }
        else
        {
            while (q.front() != x)
            {
                vis[q.front()] = 1;
                q.pop();
                cnt++;
            }
            q.pop();
            cout << cnt << ' ';
        }
    }
    return 0;
}