#include <bits/stdc++.h>

using namespace std;
string s;
int N;
int main()
{
    cin >> N;
    cin >> s;
    int len = s.length();
    // cout << s.at(len - 1) << endl;
    int pos = 0;
    int flag = 1;
    for (int i = len - 1; i >= 0; --i)
    {
        int a = s.at(pos++) - '0';
        if (a != 0)
        {
            if (flag)
            {
                cout << a << "*" << N << "^" << i;
                flag = 0;
            }
            else
                cout << "+" << a << "*" << N << "^" << i;
        }
    }
    return 0;
}
