#include <bits/stdc++.h>

using namespace std;
const int MAXN = 105;
int n, m;
int dir[8][2] = {1, 0, 0, 1, -1, 0, 0, -1};
char a[MAXN][MAXN];
// void dfs(int x, int y)
// {
//     a[x][y] = '0';
//     for (int i = 0; i < 4; ++i)
//     {
//         int xx = x + dir[i][0];
//         int yy = y + dir[i][1];
//         if (xx <1 || xx > n || yy <1 || yy > m||a[xx][yy]=='0')
//             continue;
//         dfs(xx, yy);
//     }
// }
queue<pair<int, int>> q;
void bfs(int x, int y)
{
	q.push(make_pair(x, y));
	a[x][y] = '0';
	// a[x][y]='0';
	while (!q.empty())
	{
		// int x0 = q.front().first;
		// int y0 = q.front().second;
		pair<int, int> p = q.front();
		int x0 = p.first;
		int y0 = p.second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int xx = x0 + dir[i][0];
			int yy = y0 + dir[i][1];
			if (xx < 1 || xx > n || yy < 1 || yy > m)
				continue;
			if (a[xx][yy] != '0')
			{
				a[xx][yy] = '0';
				p = make_pair(xx, yy);
				q.push(p);
			}
		}
	}
}
int main()
{
	int ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] != '0')
			{
				ans++;
				bfs(i, j);
			}
		}
	cout << ans << endl;
	return 0;
}