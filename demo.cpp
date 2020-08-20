#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define N 100
int v, n, kind = INF, lenth;
int vet[N], food[N][N], save[N], ans[N];
bool vis[N];
bool canfini(int lenth)
{
	int t[N];
	memset(t, 0, sizeof(t));
	for (int i = 1; i <= lenth; i++)
	{
		for (int l = 1; l <= v; l++)
			t[l] += food[save[i]][l];
	}
	for (int i = 1; i <= v; i++)
	{
		if (t[i] < vet[i])
			return false;
	}
	return true;
}
void dfs()
{
	if (lenth > n || lenth > kind)
		return;
	if (canfini(lenth))
	{
		if (kind > lenth)
		{
			kind = lenth;
			for (int i = 1; i <= kind; i++)
				ans[i] = save[i];
		}
		return;
	}
	int start = save[lenth];
	if (start == 0)
		start = 0;
	for (int i = start; i <= n; i++)
	{
		if (vis[i] == false)
		{
			vis[i] = true;
			lenth++;
			save[lenth] = i;
			dfs();
			vis[i] = false;
			save[lenth] = 0;
			lenth--;
		}
	}
}
int main()
{
	cin >> v;
	for (int i = 1; i <= v; i++)
		cin >> vet[i];
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= v; j++)
			cin >> food[i][j];
	dfs();
	cout<<kind<<" ";
	for (int i = 1; i <= kind; i++)
		cout << ans[i] << " ";
	return 0;
}