#include<bits/stdc++.h>
#define ITALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;
map<set<int>,int> toNum;
vector< set<int> > setdata;
int SH(set<int> x) { 
	if(toNum.count(x))return toNum[x];
	setdata.push_back(x);
	return toNum[x]=setdata.size()-1;
}
int main() {
	int T;
	cin>>T;
	while(T) {
		T--;
		stack<int>s;
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			string tip;
			cin>>tip;
			if(tip=="PUSH")
				s.push(SH(set<int>()));
			else if(tip=="DUP")
				s.push(s.top());
			else {
				set<int> x1=setdata[s.top()];
				s.pop();
				set<int> x2=setdata[s.top()];
				s.pop();
				set<int> x;
				if(tip=="UNION")set_union(ITALL(x1),ITALL(x2),INS(x));
				else if(tip=="INTERSECT")set_intersection(ITALL(x1),ITALL(x2),INS(x));
				else if(tip=="ADD") {
					x=x2;
					x.insert(SH(x1));
				}
				s.push(SH(x));
			}
			cout<<setdata[s.top()].size()<<endl;
		}
		cout<<"***"<<endl;
	}
	return 0;
}