#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

struct node
{
    int l, r, rank;
    node() {}                                                    
    node(int p, int b) : l(p), r(b), rank(p * b) {}               
    bool operator<(const node &x) const { return rank < x.rank; } 
} p[N];
struct int_l
{
    int data[N];
    int_l()
    { 
        memset(data, 0, sizeof(data)), data[0] = 1;
    }
    int_l(int x)
    { 
        memset(data, 0, sizeof(data));
        data[0] = 1;
        int i = 1;
        while (x)
        {
            data[i++] = x % 10;
            x /= 10;
        }
        data[0] = --i; 
    }
    int_l operator*(const int &x)
    { 
        int_l p;
        int len;
        p.data[0] = data[0];
        for (int i = 1; i <= data[0]; ++i)
            p.data[i] = data[i] * x;
        for (int i = 1; i <= p.data[0] || p.data[i]; len = ++i)
        {
            p.data[i + 1] += p.data[i] / 10;
            p.data[i] %= 10;
        }
        p.data[len] ? p.data[0] = len : p.data[0] = --len;
        return p;
    }
    int_l operator/(const int &x)
    { 
        int_l p;
        p.data[0] = data[0];
        int rest = 0;
        for (int i = data[0]; i >= 1; i--)
        {
            rest = rest * 10 + data[i];
            p.data[i] = rest / x;
            rest %= x;
        }
        while (!p.data[p.data[0]] && p.data[0] > 1)
            p.data[0]--; //去掉多余的 0
        return p;
    }
    bool operator<(const int_l &x) const
    {
        if (data[0] == x.data[0])
        { //从位数开始比较
            int i;
            for (i = data[0]; data[i] == x.data[i] && i > 1; i--) ; //然后是最高位
            if (i >= 1) return data[i] < x.data[i];
            else return false;
        }
        else return data[0] < x.data[0];
    }
};
ostream &operator<<(ostream &out, const int_l &x)
{
    for (int i = 1; i <= x.data[0]; ++i)
        out << x.data[x.data[0] - i + 1];
    return out;
}

int n, x, y;
int_l ans;
int main()
{
    cin >> n;
    for (int i = 0; i <= n; ++i)
        cin >> x >> y, p[i] = node(x, y);
    sort(p + 1, p + n + 1);
    int_l k(1);
    for (int i = 1; i <= n; ++i)
    { 
        if (p[i - 1].l == 0) break; 
        k = k * p[i - 1].l;
        if (ans < k / p[i].r) ans = k / p[i].r;
    }
    cout << ans << endl;
    return 0;
}