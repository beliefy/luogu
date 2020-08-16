#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
string qs[3000000], info[1000007], s, c, a, b = "123804765", gz[9] = {"13", "024", "15", "046", "1357", "248", "37", "468", "57"};
int sum, list[1000007] = {0}, following[1000007] = {0}, u, tim[3000000], head = 0, tail = 1, cnt = 0, t, x, p, i, j;
int hash_a(string h)
{
    sum = 0;
    for (i = 0; i < h.size(); i++)
    {
        sum = sum * 33 + h[i];
    } //微小的处理
    sum = abs(sum % 1000007), u = list[sum];
    while (u)
    {
        if (info[u] == h)
        {
            return 0;
        }
        u = following[u];
    } //如果出现过，返回0，否则找到最后一个，返回1并且进入到链
    info[++cnt] = h, following[cnt] = list[sum], list[sum] = cnt;
    return 1; 
}


void jh(int x, int y)
{
    char t = s[x];
    s[x] = s[y], s[y] = t;
} //两个位置交换


int main()
{
    cin >> a;
    if (a == b)
    {
        cout << "0";
        return 0;
    } //特判，虽然好像没有特殊情况
    qs[1] = a, tim[1] = 0;
    while (head < tail)
    {
        head++, c = qs[head], t = tim[head], x = c.find("0", 0); //拖出状态，找到0的位置
        for (j = 0; j < gz[x].size(); j++)
        {
            s = c, p = gz[x][j] - 48;
            jh(x, p); //交换
            if (s == b)
            {
                cout << t + 1;
                return 0;
            } //如果是目标情况，输出
            if (hash_a(s))
            {
                tail++, qs[tail] = s, tim[tail] = t + 1;
            } //如果没出现过，进队
        }
    }
    return 0;
}