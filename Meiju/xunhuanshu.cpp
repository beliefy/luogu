#include <bits/stdc++.h>
using namespace std;
int b[200], len, vis[200], a[200];
int convert(int x)
{
    int t = 0;
    while (x > 0)
    {
        b[++t] = x % 10;
        x /= 10;
    }
    for (int i = 1; i <= t; ++i)
        a[i] = b[t - i + 1]; //逆序存进去
    return t;                //长度
}
bool canFind()
{
    int t = 1;                  //开始的位置
    memset(vis, 0, sizeof vis); //每一次都memset一遍
    for (int i = 1; i <= len; ++i)
    {
        if (vis[a[t]] || a[t] == 0)
            return 0;         //走过就会有环;零也不行;
        vis[a[t]]++;          //走过了;
        t = (t + a[t]) % len; //走到下一位上;
        if (!t)
            t = len; //最后一个就是l;
    }
    if (t != 1)
        return 0; //没走到原来的辣个位置当然就"挂了";
    return 1;
}
int main()
{
    int n;
    cin >> n;
    while (true)
    {
        n++;
        len = convert(n);
        if (canFind())
        {
            cout << n << endl;
            return 0;
        }
    }
    return 0;
}