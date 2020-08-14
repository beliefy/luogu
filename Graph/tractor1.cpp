#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int inf  =0x7fffffff;
const int maxn =250010;
const int maxm =1000010;
const int maxl =505;

int node[maxl][maxl];
int fa[maxn];
int siz[maxn];
int n, m, sum, ans, maxsize, maxi;

struct road {
	int st;
	int en;
	int l;
}r[maxm];

bool operator<(road a, road b){
	return a.l<b.l;
}

bool operator>(road a, road b){
	return a.l>b.l;
}

int find(int x)
{
    return fa[x] == x ? x : find(fa[x]);
}

void add(int a,int b){
	int faa, fab;
	faa=find(a);
	fab=find(b);
	fa[fab]=faa;
	siz[faa]+=siz[fab];
	if(siz[faa] > maxsize) {
		maxsize=siz[faa];
		maxi=faa;
	}
	return;
}

int main() {
	
	int i, j, ii, ta, tb, tc, minn, mint, mi, mj;
	int zi[4]={0, 1}, zj[4]={1, 0};
	road t;
	
	scanf("%d", &n);
	
	for(i=1; i <= n*n; i++)
		fa[i]=i, siz[i]=1;
	
	for(i=1; i <= n; i++)
		for(j=1; j <= n; j++)
			scanf("%d", &node[i][j]);
	
	m=0;
	for(i=1; i <= n; i++)
		for(j=1; j <= n; j++) {
			for(ii=0; ii <= 1; ii++){
				mi=i+zi[ii];
				mj=j+zj[ii];
				if(mi > n || mj > n) continue;
				
				m++;
				r[m].st = ( i-1)*n+ j;
				r[m].en = (mi-1)*n+mj;
				r[m].l  = abs(node[i][j] - node[mi][mj]);
			}
		}
	
	sort(r+1,r+1+m);
	
	maxsize=0;
	i=0;
	n=n*n;
	while(maxsize < n/2){
		i++;
		if(i>m)break;
		t=r[i];
		ta=t.en;
		tb=t.st;
		
		if(find(ta)==find(tb))continue;
		
		add(ta, tb);
	}
	
	printf("%d\n", t.l);
	return 0;
}