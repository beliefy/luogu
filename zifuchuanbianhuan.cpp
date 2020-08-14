#include <bits/stdc++.h>
using namespace std;
string a[10], b[10], s, t;
int n = 1;
map<string, int> A, B; //pair< string , step + 1 >
queue<string> A_, B_;
inline void initialization()
{
    cin >> s >> t;
    while (cin >> a[n] >> b[n])
        n++;
}
inline int bfs()
{
    int step = 0;
    A_.push(s); //开始状态
    A[s] = 0;   //开始状态的层数
    B_.push(t); //开始状态
    B[t] = 0;   //结束状态的层数
    string s, s2;
    while (++step <= 5) //一边是10步之内，那么两边一起走就是5步之内
    {
        while (A[A_.front()] == step - 1) //保证是上一层的
        {
            s = A_.front();
            A_.pop();
            for (int i = 1; i <= n; i++) //对于每一个转换方案遍历
            {
                unsigned int pos = 0; //遍历开始搜索的节点，结合string::find( key_string , starting )
                while (pos < s.length())
                {
                    if (s.find(a[i], pos) == s.npos)
                        break; //如果找不到了
                    s2 = s;
                    s2.replace(s2.find(a[i], pos), a[i].length(), b[i]); //replace( starting , length , substitution )
                    if (A.find(s2) != A.end())                           //这棵树里面之前出现过
                    {
                        pos++;
                        continue;
                    }
                    if (B.find(s2) != B.end())
                        return step * 2 - 1; //对面的搜索树里面出现过，由于是上面先走，所以-1
                    A_.push(s2);             //入队
                    A[s2] = step;
                    pos++;
                }
            }
        }
        while (B[B_.front()] == step - 1) //保证是上一层的
        {
            s = B_.front();
            B_.pop();
            for (int i = 1; i <= n; i++) //对于每一个转换方案遍历
            {
                unsigned int pos = 0; //遍历开始搜索的节点，结合string::find( key_string , starting )
                while (pos < s.length())
                {
                    if (s.find(b[i], pos) == s.npos)
                        break; //如果找不到了
                    s2 = s;
                    s2.replace(s2.find(b[i], pos), b[i].length(), a[i]); //replace( starting , length , substitution )
                    if (B.find(s2) != B.end())                           //这棵树里面之前出现过
                    {
                        pos++;
                        continue;
                    }
                    if (A.find(s2) != A.end())
                        return step * 2; //对面的搜索树里面出现过，由于是上面先走，所以-1
                    B_.push(s2);         //入队
                    B[s2] = step;
                    pos++;
                }
            }
        }
    }
    return -1;
}
int main()
{
    initialization();
    int ans = bfs();
    if (ans == -1)
        printf("NO ANSWER!");
    else
        printf("%d", ans);
    return 0;
}