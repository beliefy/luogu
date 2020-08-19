#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n, M, D, t;
int dp[MAXN][20],Logn[MAXN];

void add(int u, int tt)
{
    dp[u][0] = tt;
    for (int i = 1; (1 << i) <= n; i++)
    {
        dp[u][i] = max(dp[u][i - 1], dp[u - (1 << (i - 1))][i - 1]);
    }
}

void pre()
{
    Logn[1] = 0;
    Logn[2] = 1;
    for (int i = 3; i < MAXN; ++i)
    {
        Logn[i] = Logn[i / 2] + 1;
    }
}

int query(int L, int R) 
{
    int log = 0;

    log=Logn[R-L+1];
    return max(dp[R][log], dp[L + (1 << log) - 1][log]);
}

int main()
{
    pre();
    cin>>M>>D;
    char ch;
    int pp;
    t = 0;
    n = 0;
    while (M--)
    {
        cin >> ch;
        cin >> pp;
        if (ch == 'A')
        {
            pp += t;
            pp %= D;
            n++;
            add(n, pp);
        }
        else if (ch == 'Q')
        {
            if (n == 0)
            {
                printf("0\n");
                continue;
            }
            t = query(n - pp + 1, n);
            printf("%d\n", t);
        }
    }
    return 0;
}