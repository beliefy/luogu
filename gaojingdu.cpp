#include <bits/stdc++.h>
using namespace std;
// 定义了每个数中存多少位
#define DIGITS 20100
//////////////////// 高精度整数 ////////////////////
struct BigInt
{
    // 默认情况下会把所有没用的位设为零
    BigInt() { memset(digits, 0, sizeof(digits)); }
    BigInt(string x)
    {
        memset(digits, 0, sizeof(digits));
        for (int i = 1; i <= x.length(); i++)
        {
            digits[i] = x[x.length() - i] - '0';
        } // 注意倒序（个十百千的顺序）
    }

    // 转换为可以输出的字符串
    string toString()
    {
        string str;
        int back = 0;
        // 先找到最后一个不是零的数位
        //（复杂度不高完全没必要把长度存下来）
        for (int i = DIGITS; i >= 1; i--)
            if (digits[i] != 0)
            {
                back = i;
                break;
            }

        // 倒着放到字符串里
        for (int i = back; i >= 1; i--)
            str += to_string(digits[i]);

        // 如果字符串里什么也没有：所有数位都是零，手动赋一个零
        if (str == "")
            str = "0";

        return str;
    }

    // 用只有16位的short
    short digits[DIGITS + 2];
};
//////////////////// 高精度加法 ////////////////////
BigInt add(BigInt x, BigInt y)
{
    BigInt sum;
    int inc = 0; // 进位标记

    // 从最低位开始累加
    for (int i = 1; i <= DIGITS; i++)
    {
        // 加起来
        sum.digits[i] = x.digits[i] + y.digits[i] + inc;

        // 如果结果大于了十：要进位
        if (sum.digits[i] >= 10)
        {
            inc = 1;             // 标记进位
            sum.digits[i] -= 10; // 把结果减去十
        }
        else // 如果不需要进位，把标记清空
            inc = 0;
    }
    return sum;
}

//////////////////// 高精度乘法 ////////////////////
//////// 注意：在极端数据下须适当放宽保存位数 ////////
BigInt multply(BigInt x, BigInt y)
{
    BigInt ans, tmp;
    // 主要思路就是 取x的每一位和y相乘
    // 然后将结果累加起来
    // 以下的代码将每一位分别相乘的结果放在tmp中
    // 再累加到ans中
    for (int i = 1; i <= DIGITS; i++)
    {
        if (x.digits[i] == 0) // 如果x的这一位是零
            continue;         // 就可以跳过了

        // 清空tmp
        memset(tmp.digits, 0, sizeof(tmp.digits));

        // 暴力相乘
        for (int j = 1; j <= DIGITS; j++)
            tmp.digits[i + j - 1] = y.digits[j] * x.digits[i];
        // 这里将乘积放到i位以后（想想竖式乘法）

        // 处理进位
        for (int j = 1; j <= DIGITS; j++)
        {
            tmp.digits[j + 1] += tmp.digits[j] / 10;
            tmp.digits[j] %= 10;
        }

        //累加
        ans = add(ans, tmp);
    }
    return ans;
}
// 高精度比较的三种结果
enum Result
{
    Less,   // X小于Y
    Equal,  // X等于Y
    Greater // X大于Y
};

//////////////////// 高精度比较 ////////////////////
Result compare(BigInt x, BigInt y)
{
    // 这里的back指的是最高的非零位的位数
    //（也可以看成长度）
    int backX = 0, backY = 0;

    // 暴力现场求长度
    for (int i = DIGITS; i >= 1; i--)
    {
        if (x.digits[i] != 0)
        {
            backX = i;
            break;
        }
    } // 求完X求Y
    for (int i = DIGITS; i >= 1; i--)
    {
        if (y.digits[i] != 0)
        {
            backY = i;
            break;
        }
    }

    // 如果X比Y长：X大于Y
    if (backX > backY)
        return Greater;

    // 如果X比Y短：X小于Y
    else if (backX < backY)
        return Less;

    // 一样长：从最高位开始逐位比较
    else
    {
        for (int i = backX; i >= 1; i--)
        {
            // 每一次能够循环到这里都说明了
            // X和Y之前的位全都一样

            // 如果这一位上X比Y大：X大于Y
            if (x.digits[i] > y.digits[i])
                return Greater;

            // 如果这一位上X比Y小：X小于Y
            else if (x.digits[i] < y.digits[i])
                return Less;
        }
        // 之前的所有比较都没有结果：
        // X与Y在每一位上都相等
        return Equal;
    }
}
//////////////////// 高精度减法 ////////////////////
BigInt minusX(BigInt x, BigInt y)
{
    BigInt sum;
    int inc = 0; // 借位标志
    // 从最低位开始计算
    for (int i = 1; i <= DIGITS; i++)
    {
        // 直接减
        sum.digits[i] = x.digits[i] - y.digits[i] + inc;

        //如果这一位的结果小于零：要借位
        if (sum.digits[i] < 0)
        {
            inc = -1;            //标记借位
            sum.digits[i] += 10; //把结果加上十
        }
        else // 如果不需要借位，把标记清空
            inc = 0;
    }
    return sum;
}

string s1, s2;
BigInt x, y;
/////////// 低调的主函数 ///////////
int main(int argc, char *argv[])
{
    // 以字符串输入
    cin >> s1 >> s2;
    // 生成高精度数
    x = BigInt(s1);
    y = BigInt(s2);
    // 判断结果是否会是负数
    if (compare(x, y) == Less)
    {                // 如果被减数小于减数
        cout << "-"; // 先输出一个负号
        swap(x, y);  // 交换被减数与减数
    }
    // 计算并输出
    cout << minusX(x, y).toString() << endl;

    return 0;
}