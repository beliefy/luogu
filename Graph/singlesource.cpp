#include<cstdio>
#include<iostream>
#define MAXN 10021
#define INF 0x7fffffff
using namespace std;

struct Edge {
    int s, value, next;
};

int n, m, s, t, flag;
int h[MAXN], vis[MAXN], d[MAXN];

Edge graph[100000021];

int main() {
    scanf("%d%d%d", &n, &m, &s);
    flag = n;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        graph[++t] = {b, c, h[a]};
        h[a] = t;
    } 
    fill(d+1, d+n+1, INF);
    d[s] = 0;
    while (flag--) {
        int mini = INF, num = 0;
        for (int i=1; i<=n; i++)
            if (!vis[i]) {
                num = d[i] < mini ? i : num;
                mini = min(mini, d[i]);
            }
        vis[num] = 1;
        for (int i=h[num]; i; i=graph[i].next)
            d[graph[i].s] = min(d[graph[i].s], d[num] + graph[i].value);
    }
    for (int i=1; i<=n; i++)
        printf("%d ", d[i]);

    return 0;
}