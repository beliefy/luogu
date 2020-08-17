#include <bits/stdc++.h>

using namespace std;

string ciphertext, origntext, txt;
map<char, char> f,ff;
int main()
{
    cin >> ciphertext >> origntext >> txt;
    for (int i = 0; i < ciphertext.size(); ++i)
    {
        if (f.count(ciphertext[i])==1 && f[ciphertext[i]] != origntext[i])
        {
            cout << "Failed" << endl;
            return 0;
        }
        f[ciphertext[i]] = origntext[i];
        ff[origntext[i]]=ciphertext[i];
    }
    if (f.size() != 26||ff.size()!=26)
    {
        cout << "Failed" << endl;
        return 0;
    }
    
    for (int i = 0; i < txt.size(); ++i)
    {
        txt[i] = f[txt[i]];
    }
    cout << txt << endl;
    return 0;
}