#include<bits/stdc++.h>
using namespace std;
struct node{
	string a;
	int ans;
};
queue<node> q;//BFS队列
string x[15],y[15];
map<string,bool> h;//用map当哈希表
int main()
{
	int u=1;
	string a,b;
	cin>>a>>b;
	while(cin>>x[u]>>y[u])
		u++;
	u--;
	q.push(node{a,0});
	while(!q.empty())//以下为标准的BFS模板
	{
		node s=q.front();
		if(s.ans==11)//如果超过10直接跳出输出NO ANSWER!
			break;
		if(s.a==b)//找到答案即输出
		{
			printf("%d",s.ans);
			return 0;
		}
		for(int i=1,v=0;i<=u;i++,v=0)
			while(s.a.find(x[i],v)!=-1)//被坑了，不能只找一次，可能有多个相同的子串……应在找到一个后往后面继续找
			{
				string w=s.a;
				int m=s.a.find(x[i],v);
				w.replace(m,x[i].size(),y[i]);
				if(h[w]==0)//哈希表，不开最后一个点MLE
					q.push(node{w,s.ans+1}),h[w]=1;
				v=m+x[i].size();//记录继续查找的位置
			}
		q.pop();
	}
	printf("NO ANSWER!");
}