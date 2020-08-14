#include <iostream>
using namespace std;
const int N = 2e5 + 5;
int n;
int cnt = 1;
int ans = -1;
int a[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (2 * a[i] >= a[i + 1])
            cnt++;
        else
        {
            if (cnt > ans)
                ans = cnt;
            cnt = 1;
        }
    }
    if (cnt > ans)
        ans = cnt;
    cout << ans << endl;
}