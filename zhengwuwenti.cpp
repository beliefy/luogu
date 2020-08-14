#include <bits/stdc++.h>
using namespace std;
stack<int> op;  
stack<int> tf;
void cal()
{
    bool f1, f2;
    switch (op.top())
    {
    case 1:
        if (tf.size() < 2) 
            cout << "error", exit(0);
        f1 = tf.top(), tf.pop();
        f2 = tf.top(), tf.pop(); 
        tf.push(f1 || f2);
        break; 
    case 2:
        if (tf.size() < 2) 
            cout << "error", exit(0);
        f1 = tf.top(), tf.pop();
        f2 = tf.top(), tf.pop(); 
        tf.push(f1 && f2);
        break; 
    case 3:
        if (tf.empty())
            cout << "error", exit(0);
        f1 = tf.top(), tf.pop(); 
        tf.push(!f1);
        break; 
    }
    op.pop();
}
int main()
{
    string st;
    while (cin >> st)
    {
        if (st == "or")
        {
            while (!op.empty()) 
                cal();
            op.push(1); 
        }
        else if (st == "and")
        {
            while (!op.empty() && op.top() >= 2)
                cal();
            op.push(2);
        }
        else if (st == "not") 
            op.push(3);
        else if (st == "true") 
            tf.push(1);
        else if (st == "false") 
            tf.push(0);
    }
    while (!op.empty())
        cal(); 
    if (tf.size() == 1)
    {
        if (tf.top())
            cout << "true";
        else
            cout << "false";
    }
    else
        cout << "error";
    return 0;
}