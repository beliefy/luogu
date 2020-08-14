#include <iostream>
#include <cstdio>
#include <cstring>.
#include <string>

using namespace std;
string s;
int a,ze_len,mx,pos=-1,last=-1;
int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i += 5)
    {
        if (s[i] == '0' && s[i + 1] == '0' && s[i + 2] == '0' && s[i + 3] == '0') 
        {
            if (last == i - 5)
                last = i;
            else
            {
                ze_len = 0;
                last = i;
                a = i;
            }
            ze_len++;
        }
        if (ze_len > mx)
        {
            mx = ze_len;
            pos = a;
        }
    }

    int t = 0;
    while (t < s.length())
    {
        if (t == pos)
        {
            if (t == 0)
                cout << ":";
            t += mx * 5 - 1;
            if (t == s.length())
                cout << ":";
        }
        else
        {
            if (t % 5 == 0)
            {
                if (t >= 35) 
                {
                    while (s[t] == '0' && t + 1 != s.length())
                    {
                        t++;
                    }
                }
                else
                {
                    while (s[t] == '0' && s[t + 1] != ':')
                    {
                        t++;
                    }
                }
            }
            cout << s[t];
            t++;
        }
    }
    return 0;
}