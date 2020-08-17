#include <bits/stdc++.h>
using namespace std;
char s1[100010], s2[100010], s3[100010], a[100010];
long long top2, top1, p;
long long js[100010], topjs;
int count(char n)
{
    if (n == '+' || n == '-')
        return 1;
    if (n == '*' || n == '/')
        return 2;
    if (n == '^')
        return 3;
    return 0;
}
void print()
{
    for (int i = 1; i <= topjs; i++)
    {
        cout << js[i] << " ";
    }
    for (int i = p + 1; i <= top2; i++)
    {
        cout << s2[i];
        if (i != top2)
            cout << " ";
    }
    if (p != top2)
        cout << endl;
}
int main()
{
    long long n;
    scanf("%s", a);
    n = strlen(a); 
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            s2[++top2] = a[i];
        }
        else
        {
            if (a[i] == '(')
            {
                s1[++top1] = a[i];
                continue;
            }
            if (s1[top1] == '(' || top1 == 0)
            {
                s1[++top1] = a[i]; 
                continue;
            }
            if (count(s1[top1]) >= count(a[i]) && a[i] != ')')
            {
                s2[++top2] = s1[top1--];
                while (count(s1[top1]) >= count(a[i]))
                {
                    s2[++top2] = s1[top1--];
                }
                s1[++top1] = a[i];
                continue;
            }
            if (count(s1[top1]) < count(a[i]) && a[i] != ')')
            {
                s1[++top1] = a[i];
                continue;
            }
            if (a[i] == ')')
            {
                while (s1[top1] != '(')
                {
                    s2[++top2] = s1[top1--];
                }
                --top1;
                continue;
            }
        }
    }
    while (top1 > 0)
    {
        s2[++top2] = s1[top1--];
    }
    for (int i = 1; i <= top2; i++)
    {
        cout << s2[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= top2; i++)
    {
        p = i;
        if (s2[i] >= '0' && s2[i] <= '9')
        {
            js[++topjs] = s2[i] - '0';
        }
        else
        {
            if (s2[i] == '+')
            {
                long long y = js[topjs];
                long long x = js[--topjs];
                long long ans = x + y;
                js[topjs] = ans;
            }
            if (s2[i] == '-')
            {
                long long y = js[topjs];
                long long x = js[--topjs];
                long long ans = x - y;
                js[topjs] = ans;
            }
            if (s2[i] == '*')
            {
                long long y = js[topjs];
                long long x = js[--topjs];
                long long ans = x * y;
                js[topjs] = ans;
            }
            if (s2[i] == '/')
            {
                long long y = js[topjs];
                long long x = js[--topjs];
                long long ans = x / y;
                js[topjs] = ans;
            }
            if (s2[i] == '^')
            {
                long long y = js[topjs];
                long long x = js[--topjs];
                long long ans = pow(x, y);
                js[topjs] = ans;
            }
            print();
        }
    }
    return 0;
}