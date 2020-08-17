#include<bits/stdc++.h>
using namespace std;
int cake, n, m, ans = -0xffffffff; 
int sum[500005];
struct node
{
    int index, value; 
} q[500005];

int main()
{
    int head = 1, tail = 0;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &cake);
        sum[i] = sum[i - 1] + cake;
    }
    for (int i = 1; i <= n; i++)
    {
        if (q[head].index + m < i)
            head++; 
        while (head <= tail && q[tail].value >= sum[i])
            tail--;
        q[++tail].index = i;
        q[tail].value = sum[i];
        ans = max(ans, q[tail].value - q[head].value);
    }
    cout<<ans<<endl;
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> parent of 7c8312c... 整理
