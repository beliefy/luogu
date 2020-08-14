#include <bits/stdc++.h>
using namespace std;
struct food
{
    int val, num;
} f[102]; 
int number, s, n, ans = 0;
bool cmp(food a, food b) { return a.val < b.val; } 
int Min(int a, int b) { return a < b ? a : b; }
int main()
{
    cin>>number>>s>>n;
   for (int i = 1, a, b; i <= n; i++) 
    {
        cin>>a>>f[i].num>>b;
        f[i].val = s - a + b;
    }
    sort(f + 1, f + 1 + n, cmp); 
    for (int i = 1; i <= n && number > 0; i++)
    {
        ans += Min(number, f[i].num) * f[i].val;
        number -= f[i].num;                      
    }
    cout<<ans<<endl;
    return 0;
}