#include<bits/stdc++.h>
using namespace std;
#define N 3000005
int sta[N],a[N],f[N];
int main()
{
	int n,i,top=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i = n;i>=1;--i)
	{
		while(top&&a[sta[top]]<=a[i])top--; 
		f[i]=sta[top]; 
		sta[++top]=i;
	}
	for(int i=1;i<=n;++i)printf("%d",f[i]),putchar(' ');
	return 0;
}