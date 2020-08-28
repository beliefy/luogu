#include<bits/stdc++.h>
using namespace std;
struct node {
    int d, to, next;
} e[200010 << 1];

pair<int, int> heap[200010 << 1];
int siz, n, m, d[100010], head[100010], tot;
bool v[200010];

bool cmp(pair<int, int> a, pair<int, int> b) {//比较函数
    return a.first > b.first;
}

 void add(int u, int v, int w) {
    e[++tot].to = v;
    e[tot].d = w;
    e[tot].next = head[u];
    head[u] = tot;

}

void dijkstra() {
    memset(d, 0x3f, sizeof(d));
    memset(v,0, sizeof(v));
    d[1] = 0;
    heap[++siz] = make_pair(0, 1);
    while (siz) {
        int x = heap[1].second;
        pop_heap(heap + 1, heap + siz + 1, cmp);//弹出堆顶
        siz--;
        if (v[x]) continue;
        v[x] = 1;
        for (int i = head[x]; i; i = e[i].next) {
            int y = e[i].to, z = e[i].d;
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                heap[++siz] = make_pair(d[y], y);
                push_heap(heap + 1, heap + siz + 1, cmp);//把二元组插入堆中
            } 
        }
    }
}

int main() {
    int s;
    cin>>n>>m>>s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        add(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; i++) {
        cout<<d[i]<<" ";
    }
    return 0;
}