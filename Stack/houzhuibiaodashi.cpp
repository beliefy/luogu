#include <bits/stdc++.h>

using namespace std;

char ch;
stack<int> num;
int a, b;
int tot ;
int main()
{
    while ((ch = getchar()) != '@')
    {
        switch (ch)
        {
        case '+' :
        {
            /* code */
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();
            num.push(a + b);
            break;
        }
        case '-':
        {
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();
            num.push(b - a);
            break;
        }
        case '*':
        {
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();
            num.push(a * b);
            break;
        }
        case '/':
        {
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();
            num.push(a / b);
            break;
        }
        case '.':
        {
            num.push(tot);
            tot = 0;
            break;
        }
        default:
        {
            tot = tot * 10 + ch - '0';
            break;
        }
        }
    }
    cout << num.top() << endl;
    return 0;
}

