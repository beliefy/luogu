#include <bits/stdc++.h>
using namespace std;
int m, n, ans = 0;
int sequence[625];
int t[25][25], serial[25][25];
int mac[21][100001] = {0};
// mac[机器编号][时间
int step[21] = {0};
int las_time[21] = {0};
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m * n; i++)
	{
		cin >> sequence[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> serial[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> t[i][j];
		}
	}
	for (int i = 1; i <= m * n; i++) //遍历工序
	{
		int now = sequence[i];
		step[now]++;
		int id = serial[now][step[now]], cost = t[now][step[now]], s = 0, j = las_time[now] + 1;
		while (true)
		{
			if (!mac[id][j])
				s++;
			else
				s = 0;
			if (s == cost)
			{
				for (int k = j - cost + 1; k <= j; k++)
				{
					mac[id][k] = 1;
				}
				ans = max(ans, j);
				las_time[now] = j;
				break;
			}
			j++;
		}
	}
	cout << ans << endl;
	return 0;
}