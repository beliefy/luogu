#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "请输入多项式的次数 ：";
    cin >> n;
    double *a = new double[n + 1]; //n次多项式申请n+1大小的数组
    cout << "请输入多项式的系数（最高次项开始）:" << endl;
    for (int i = n; i >= 0; i--)
        cin >> a[i]; //读入各项系数
    double x0, ans = a[n];
    cout << "请输入 X0 " << endl;
    cin >> x0;
    for (int i = n - 1; i >= 0; i--)
        ans = ans * x0 + a[i]; //最高次项开始，往外展开
    cout << "多项式在X0出的函数值为：" << ans << endl;
    delete[] a; //释放动态内存
    return 0;
}