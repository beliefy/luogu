#include <stdio.h>
#include <iostream>
using namespace std;
const int N = 100001;
long long q[N], x, total; //line存单调队列,x临时变量存输入，total存效率总数(long long注意!不然后果自负)
int NO[N];                   //NO存单调队列的编号,就是1~k,用于更新队列头
int main()
{
    int n, k, head = 0, tail = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> x, total += x; //更新效率总数
        if (NO[head] < i - k - 1)
            head++;    //区间K个以内
            
        x += q[head]; //由于是单调队列,所以第一个一定最小,用它来更新f(i)
        while (q[tail - 1] > x)
            tail--;     //踢人模式,被我完爆的家伙们，你们不属于这里!(因为后面几项不但靠前且值还较大，所以不能还会用它们更新)
        q[tail] = x; //将刚来的f(i)存入队列
        NO[tail++] = i;   //将它的序号存入队列
    }
    if (NO[head] < n - k)
        head++; //这里注意,由于最后尾指针更新,所以头可能不在k的范围内
    cout << total - q[head];
    return 0;
}
