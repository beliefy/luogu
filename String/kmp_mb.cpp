#include <bits/stdc++.h>
using namespace std;

vector<int> get_next(string pattern)
{
    vector<int> result;
    int i=0, j=-1;
    result.push_back(-1);
    while (i < pattern.size() - 1)
    {
        if (j == -1 || pattern[i] == pattern[j])
        {
            ++i, ++j;
            if (pattern[i] != pattern[j])
                result.push_back(j);
            else if (i == 1)
                result.push_back(j);
            else
                result.push_back(result[j]);
        }
        else
            j = result[j];
    }
    return result;
}

int KMP(string txt, string pattern)
{
    vector<int> next = get_next(pattern);
    int i = 0,j=0;
    while (i < (int)txt.size() && j < (int)pattern.size())
    {
        if (j == -1 || txt[i] == pattern[j])
            ++i, ++j;
        else
            j = next[j];
    }
    if (j == pattern.size())
        return i - j;
    else
        return -1;
}

int main()
{
    string str;
    cout << "enter the string:";
    cin >> str;
    string pattern;
    cout << "enter the pattern:";
    cin >> pattern;
    int result = KMP(str, pattern);
    cout << result << endl;
    return 0;
}
