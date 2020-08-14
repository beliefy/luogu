#include <bits/stdc++.h>
using namespace std;
string s;
map<string,bool>v;
int main(){
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	while(getline(cin,s)){
		if(!v.count(s)){
			cout <<s<<endl;
			v.insert(make_pair(s,true));
		}
	}
	return 0;
} 