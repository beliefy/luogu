#include <bits/stdc++.h>

using namespace std;
string s;
bool low_cha;
int p1, p2, p3;
int main()
{
    freopen("D:\\materials\\vccode\\luogu\\String\\P1098_8.in","r",stdin);
    cin >> p1 >> p2 >> p3;
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '-')
        // cout<<s[i-1]<<"" <<s[i+1]<<endl;
        {
            if (islower(s[i - 1]) && islower(s[i + 1])||(isdigit(s[i - 1]) && isdigit(s[i + 1])))
            {
                // cout<<s[i-1]<<" " <<s[i+1]<<endl;
                if (s[i - 1] < s[i + 1])
                {
                    string ss = "";
                    char a = (char)s[i - 1];
                    a++;
                    while (a < s[i + 1])
                    {
                        int k = p2;
                        while (k--)
                        {
                            string t(1, a);
                            // a.str();
                            // string aa = a + "";
                            // ss += a;
                            // ss.insert()
                            ss += t;
                        }
                        a++;
                    }
                    if(p1==2)
                    {
                        transform(ss.begin(),ss.end(),ss.begin(),::toupper);
                    }
                    else if(p1==3)
                    {
                        // string t="*";
                        // t=ss.size()*t;
                        // ss.replace(0,ss.size(),"*");
                        for(int i = 0;i<ss.size();++i)
                        {
                            ss[i]='*';
                        }
                    }

                    if(p3==2)
                    {
                        reverse(ss.begin(),ss.end());
                    }
                    // cout << ss << endl;
                    s.replace(i,1,ss);
                }
            }
            // else if (isdigit(s[i - 1]) && isdigit(s[i + 1]))
            // {
            //     // cout<<s[i-1]<<" " <<s[i+1]<<endl;
            // }
        }
    }
    cout<<s<<endl;
    return 0;
}