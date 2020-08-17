#include <bits/stdc++.h>
#define pli pair<long long ,int>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,k;
priority_queue<pli,vector<pli>,greater<pli>> h;
int main(){
   cin>>n>>k;

   for(int i=0;i<n;i++){
      ll x;
      cin>>x;
      h.push({x,0});
   }

   while((n-1)%(k-1)) h.push({1ll*0,0}),n++;

   ll ans=0;
   while(h.size()>1) {
      ll res=0;
      int depth=0;
      for (int i = 0; i < k; i++) {

         auto t = h.top();
         h.pop();
         res += t.first;
         depth=max(depth,t.second);
      }
      h.push({res,depth+1});
      ans+=res;
   }

   cout<<ans<<endl<<h.top().second;
}
