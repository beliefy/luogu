#include <bits/stdc++.h>
using namespace std;
const int N = 120000;
int n, k;
long long a[N];
long long total = 0; //总效率
long long f[N];
//f数组，用来存储去除第n头奶牛时要去除多少效率
deque<int> q;
int main()
{
    memset(f, 0, sizeof f);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], total += a[i];
    q.push_front(0);
    for (int i = 1; i <= n + 1; i++)
    {
        //如果队首到(有超过k头连续奶牛)则弹出队首
        while (q.front() < i - k - 1)
            q.pop_front();
        f[i] = f[q.front()] + a[i];
        while (f[q.back()] > f[i])
            q.pop_back();
        //如果前面的反而更小就弹出前面的
        q.push_back(i);
    }
    cout << total - f[q.front()];
    //因为队首一定最优，所以直接输出总效率-队首即可
    return 0;
}