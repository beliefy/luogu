#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5;
// string a[N];
set<string> se;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        se.insert(s);
    }

    // sort(a,a+n);
    cout<<se.size()<<endl;

    return 0;
}