#include <bits/stdc++.h>
#define maxn 1000100
using namespace std;
int q[maxn], a[maxn];
int n, k;
void getmin()
{
    int head = 0, tail = 0;
    for (int i = 1; i < k; i++)
    {
        while (head <= tail && a[q[tail]] >= a[i])
            tail--;
        q[++tail] = i;
    }
    for (int i = k; i <= n; i++)
    {
        while (head <= tail && a[q[tail]] >= a[i])
            tail--;
        q[++tail] = i;
        while (q[head] <= i - k)
            head++;
        printf("%d ", a[q[head]]);
    }
}

void getmax()
{
    int head = 0, tail = 0;
    for (int i = 1; i < k; i++)
    {
        while (head <= tail && a[q[tail]] <= a[i])
            tail--;
        q[++tail] = i;
    }
    for (int i = k; i <= n; i++)
    {
        while (head <= tail && a[q[tail]] <= a[i])
            tail--;
        q[++tail] = i;
        while (q[head] <= i - k)
            head++;
        printf("%d ", a[q[head]]);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    getmin();
    printf("\n");
    getmax();
    printf("\n");
    return 0;
}
/*
8 3
1 3 -1 -3 5 3 6 7

 */