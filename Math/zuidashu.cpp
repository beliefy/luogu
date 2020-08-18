#include <bits/stdc++.h>

using namespace std;
int M, D;
vector<int> v;
int main()
{
    cin >> M >> D;
    int t = 0;
    while (M--)
    {
        char a;
        int x;
        cin >> a >> x;
        if (a == 'A')
        {
            if (!t)
            {
                v.push_back(x % D);
            }
            else
            {
                v.push_back((x + t) % D);
            }
        }
        if (a == 'Q')
        {
            int m = 0;
            int n = v.size();
            // for (int i = n - 1; i > n - 1 - x && i >= 0; i--)
            // {
            //     if (v[i] > m)
            //         m = v[i];
            // }
            // vector<int> ::reverse_iterator l=v.rbegin();
            // for()
            t = m;
            cout << t << endl;
        }
    }
    return 0;
}