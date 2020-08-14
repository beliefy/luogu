#include <bits/stdc++.h>

using namespace std;

long long s[1000005];

int main()
{
    int n, i, j;
    cin>>n;
    s[0] = 0;
    for (i = 1; i <= n; i++)
        s[i] = s[i - 1] + i;
    i = 0;
    j = 1;
    while (i < n && j < n)
    {
        if (s[j] - s[i] == n)
        {
            printf("%d %d\n", i + 1, j);
            i++;
            j++;
        }
        else if (s[j] - s[i] > n)
            i++;
        else
            j++;
    }
    return 0;
}