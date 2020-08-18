#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
ull f(int n)
{
    ull sum = 1;
    for (int i = 2; i <= n; ++i)
    {
        sum *= i;
        while (sum % 10LL == 0LL)
            sum /= 10LL;
        sum %= 1000000;
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    // for(int i =)
    ostringstream outs;
    outs << f(n);
    string s = outs.str();
    // cout<<s<<endl;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != '0')
        {
            cout << s[i] << endl;
            break;
        }
    }
    // cout<<f(n)<<endl;
    return 0;
}