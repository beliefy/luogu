#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 200005;
ll a[MAXN], f[MAXN][21], s, D, Logn[MAXN];
int n, m;
bool flag;
void pre()
{
    Logn[1] = 0;
    Logn[2] = 1;
    for (int i = 3; i < MAXN; ++i)
    {
        Logn[i] = Logn[i / 2] + 1;
    }
}
void st(int id)
{
	f[id][0] = a[id];
	for (int i = 1; i << i <= id; i++)
		f[id][i] = max(f[id][i - 1], f[id - (1 << (i - 1))][i - 1]);
}
ll query(int x, int y)
{
	int s  = Logn[y - x + 1];
	// double t = log2(y - x + 1);
	// int s = t;
	return max(f[y][s], f[x + (1 << s) - 1][s]);
}
int main()
{

	memset(f, 0, sizeof f);
	pre();
	cin >> m >> D;
	for (int i = 1; i <= m; i++)
	{
		char c;
		cin >> c;
		ll x;
		if (c == 'A')
		{
			cin >> x;
			a[++n] = (x + s) % D;
			st(n);
		}
		else
		{
			int L;
			cin >> L;
			ll ans;
			if (L == 1)
			{
				cout << a[n] << endl;
				s = a[n];
				continue;
			}
			s = query(n - L + 1, n);
			cout << s << endl;
		}
	}
	return 0;
}