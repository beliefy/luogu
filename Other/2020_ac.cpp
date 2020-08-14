#include <bits/stdc++.h>
using namespace std;
int c[1000001], t,sum, d;
int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    while (n--)
    {
        cin >> t;
        while (t--)
        {
            cin >> d;
            ++c[d];
        }
    }
    vector<int> b;
    for (int i = 1; i <= m; i++)
        if (c[i] == p)
        {
            // s[sum] = i;
            b.push_back(i);
            ++sum;
        }
    cout<<sum<<endl;
    // sort(s, s + sum);
    for (int i = 0; i < b.size(); i++)
        cout<<b[i]<<" ";
    // printf("\n");
    return 0;
}