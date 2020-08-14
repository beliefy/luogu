#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int a[N][N];
int sum[N][N];
int n, k;
int main()
{
    cin>>n>>k; 
    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; ++i)
        {
            a[i][y1]++;
            a[i][y2 + 1]--;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] += a[i][j - 1];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // for(int i = 1;i<=n;++i)
    // {
    //     for(int j = 1;)
    // }
    return 0;
}