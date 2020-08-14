#include <bits/stdc++.h>

using namespace std;
string s, ss[9];
int main()
{
    cin >> s;
    if (s == "0000:0000:0000:0000:0000:0000:0000:0000")
    {
        cout << "::" << endl;

        return 0;
    }
    s = ":" + s;
    // for (int i = 1; i <= s.length(); ++i)
    // {
    //     if (s[i] == ':')
    //         cout << i <<endl;
    // }
    int x = 0, y = 5;
    for (int i = 1; i <= 8; ++i)
    {
        ss[i] = s.substr(x, y);
        x += 5;
    }
    for (int i = 1; i <= 8; ++i)
    {
        // if(!ss[i].compare(":0000"))
        if (ss[i] == ":0000")
        {
            ss[i] = ":";
        }
        else
        {
            // for(int j = 1;j<=ss[i].length())
            // {
            //     if(ss[i][j]=='0')
            //     {

            //     }
            // }
            ss[i].erase(0, 1);
            reverse(ss[i].begin(), ss[i].end());
            // while (ss[i].back() == '0' && ss[i].size() > 1)
            //     ss[i].pop_back();
            for (int j = ss[i].size() - 1; j > 0; j--)
            {
                if (ss[i][j] == '0')
                    ss[i].erase(j, 1);
                else
                    break;
            }
            reverse(ss[i].begin(), ss[i].end());
            ss[i] = ":" + ss[i];
            // ss[i].
        }
    }

    // int ans = 0;
    int mx = 0;
    int pos[9];
    for (int i = 1; i <= 8; ++i)
    {
        int ans = 0;
        // int pos = 0;
        if (ss[i] == ":")
        {
            ans++;
            // =i;
            for (int j = i + 1; j <= 8; ++j)
            {
                if (ss[j] == ":")
                {
                    ans++;
                }
                else
                {
                    break;
                }
            }
            pos[ans] = i;
        }
        mx = max(ans, mx);
        // pos[mx]=i;
    }
    string res = "";
    bool add = false;
    // for(int i = 1;i<=8;++i)
    // {
    //     ss[i].erase(0,1);
    // }
    for (int i = 0; i <= 8; ++i)
    {
        if (ss[i] != ":")
        {
            res += ss[i];
            // res+=":";
        }
        else
        {
            if (i >= pos[mx] && i < pos[mx] + mx)
            {
                if (add == false)
                {
                    res += ":";
                    add = true;
                }
            }
            else
            {
                res += "0000";
            }
        }
    }
    res.erase(0, 1);
    if (res.substr(res.size() - 1, 1) == ":" && res.substr(res.size() - 2, 1) != ":")
        res = res + ":";
    if (res.substr(0, 1) == ":" && res.substr(1, 1) != ":")
        res = ":" + res;
    cout << res << endl;
    // for (int i = 1; i <= 8; ++i)
    //     cout << ss[i] << endl;
    return 0;
}