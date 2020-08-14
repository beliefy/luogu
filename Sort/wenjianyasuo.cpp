#include <cstdio>
#define N 10001
using namespace std;
char s[N], ans[N];
int a[26], l[26], r[26];
int main()
{
    int n, p;
    scanf("%d%s%d", &n, s + 1, &p);
    for (int i = 1; i <= n; i++)
        a[s[i] - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        l[i] = r[i - 1] + 1;
        r[i] = l[i] + a[i] - 1;
    }
    int now = l[s[p] - 'a'];
    int tot = 0;
    while (tot < n)
    {
        ans[tot] = s[now];
        now = r[s[now] - 'a']--;
        tot++;
    }
    for (int i = n - 1; i >= 0; i--)
        putchar(ans[i]);
}