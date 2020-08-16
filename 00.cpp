#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int s, p;

inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}

inline void write(int x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}

int x[510], y[510];

double dist(int x, int y, int i, int j)
{
	return sqrt((abs(x - i) * abs(x - i)) + ((abs(y - j)) * (abs(y - j))));
}

double dis[510][510];

struct Edge
{
	int x;
	int y;
	double v;
}ed[500010];int cnt;

bool cmp(Edge a, Edge b)
{
	return a.v < b.v;
}

int f[50010];
int find(int x)
{
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}

int line[500010];

int main()
{
//	freopen("wireless.in","r",stdin);
//	freopen("wireless.out","w",stdout);
	s = read(), p = read();
	for(register int i=1;i<=p;i++)
	{
		x[i] = read(), y[i] = read();

	}
	for(register int i=1;i<=p;i++)
	{
		for(register int j=1;j<=p;j++)
		{
			if(i == j) dis[i][j]/* = dis[j][i] */= 0x7fffff;
			else dis[i][j] /*= dis[j][i]*/ = dist(x[i], y[i], x[j], y[j]);
			//cout<<dis[i][j]<<" ";
			cnt++;
			ed[cnt].x = i;
			ed[cnt].y = j;
			ed[cnt].v = dis[i][j];
		}
	}
	for(register int i=1;i<=p;i++) f[i] = i;
	
	sort(ed+1, ed+1+cnt, cmp);
	
	
	int k = 0;///////注意！！！！！！！！！！！！！ 
	for(register int i=1;i<=cnt;i++)
	{
		int x = ed[i].x , y = ed[i].y ;
		if(find(x) != find(y))
		{
			f[find(x)] = find(y);
			k++;
			line[k] = i;
		}
		if(k == p - 1)break;
	}
	//cout<<line[k - s/2];
	//cout<<ed[line[k-s+1]].v;
	printf("%.2lf",ed[line[p-s]].v);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
	
}