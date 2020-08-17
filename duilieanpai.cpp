#include <iostream>
#include <cstring>
using namespace std;
int dat[100001], nxt[100001], pre[100001];
int main()
{
    int n, i, k;
    cin >> n;
    nxt[0] = 1;
    dat[1] = 1;
    pre[1] = 0;
    for (i = 2; i <= n; i++)
    {
        int k, p;
        cin >> k >> p;
        dat[i] = i;
        if (p)
        {
            nxt[i] = nxt[k];
            nxt[k] = i;
            pre[i] = k;
            pre[nxt[i]] = i;
        }
        else
        {
            int tem = pre[k];
            nxt[tem] = i;
            pre[i] = tem;
            nxt[i] = k;
            pre[k] = i;
        }
    }
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> k;
        dat[k] = 0;
    }
    i = 0;
    while (true)
    {
        i = nxt[i];
        if (!i)
        {
            cout << endl;
            break;
        }
        if (dat[i])
            cout << dat[i] << ' ';
    }
    return 0;
}
