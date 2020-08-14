#include <bits/stdc++.h> 
using namespace std;    
const int inf = 0x3f3f3f3f;
int p[100001], n, dist, ans;
int main(void)
{
    cin >> n >> dist;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p, p + n);
    for (int i = 1; i <= n - 2; ++i)
        if (p[i - 1] != inf && p[i + 1] - p[i - 1] <= dist)
            p[i] = inf, ans++; 
        else
        { 
            int j = i - 1;
            while (p[j] == inf)
                j--;
            if (p[i + 1] - p[j] <= dist)
                p[i] = inf, ans++;
        }
    cout<<ans<<endl;
}