#include <bits/stdc++.h>
using namespace std;
struct node
{
    string curstr;
    int ans;
};
queue<node> q; 
string before[15], after[15];
map<string, bool> h;
int main()
{
    int u = 1;
    string curstr, tarstr;
    cin >> curstr >> tarstr;
    while (cin >> before[u] >> after[u])  u++;
    u--;
    q.push(node{curstr, 0});
    while (!q.empty())
    {
        node s = q.front();
        if (s.ans > 10)
            break;
        if (s.curstr == tarstr) 
        {
            cout << s.ans << endl;
            return 0;
        }
        for (int i = 1, pos = 0; i <= u; i++, pos = 0)
            while (s.curstr.find(before[i], pos) != -1)
            {
                string w = s.curstr;
                int m = s.curstr.find(before[i], pos);
                w.replace(m, before[i].size(), after[i]);
                if (!h[w]) 
                    q.push(node{w, s.ans+1}), h[w] = 1;
                pos = m + before[i].size();
            }
        q.pop();
    }
    cout<<"NO ANSWER!"<<endl;
}