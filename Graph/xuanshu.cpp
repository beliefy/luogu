#include <iostream>
#include <math.h>
using namespace std;
int x[20], n, k; //依照题目所设
bool isprime(int n)
{ //判断是否质数
    int s = sqrt(double(n));
    for (int i = 2; i <= s; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int dfs(int left, int already_sum, int start)
{
    //调用递归生成全组合，在过程中逐渐把K个数相加，当选取的数个数为0时，直接返回前面的累加和是否为质数即可
    if (left == 0)
    {
        cout<<already_sum<<endl;
        return isprime(already_sum);
    }
    int sum = 0;
    for (int i = start; i <= n-1; i++)
    {
        sum += dfs(left - 1, already_sum + x[i], i + 1);
    }
    return sum;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cout << dfs(k, 0, 0); //调用递归解决问题
    return 0;
}