#include <bits/stdc++.h>
using namespace std;
const int N = 10;
const int M = 15;
int dp[N + 1][M + 1], m, n;
int value[N + 1][M + 1]; 
int ans[N + 1][M + 1];

void print(int i, int j) {
    if(i != 0) {
        print(i - 1, j - ans[i][j]);
        cout<<i<<" "<<ans[i][j]<<endl;
    }
}
int main()
{
    scanf(" %d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf(" %d", &value[i][j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k <= j; k++) {
                int tmp = dp[i - 1][j - k] + value[i][k];
                if(tmp >= dp[i][j]) {
                    dp[i][j] = tmp;
                    ans[i][j] = k;
                }
            }
        }
    }
    cout<<dp[n][m]<<endl;
    print(n, m);
    return 0;
}
