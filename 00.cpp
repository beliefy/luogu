#include <bits/stdc++.h>
const int N = 60;
const double EPS = 1e-6;
using namespace std;
struct node
{
    string name;
    double score;
} a[N];
int main()
{
    string s[100];

    for (int i = 1; i <= 56; ++i)
    {
        cin >> a[i].name;
    }
    for (int i = 1; i <= 56; ++i)
    {
        cin >> a[i].score;
    }
    double lev;
    cin >> lev;
    int ans = 1;
    int cnt = 0;
    for (int j = 1; j <= 56; ++j)
    {
        // if(fabs(a[j].score - lev)<EPS)
        // {
            cout << a[j].name << "" << a[j].score << endl;
            cnt++;
            // if (cnt >= 32)
            // {
            //     ans = j;
            // }
        // }
    }
    cout << a[ans].name << "" << a[ans].score << endl;
    return 0;
}
/*
苗文昊
吴晨越
沈德瑞
马子恒
常甜
张馨月
周宇疃
王景东
云恒
唐名时
王子灿
刘心怡
董艺帆
苏月彤
夏振兴
李怡宁
刘宏天
韩鹏宇
侯文昊
张昶
张可鑫
李硕
刘娅茹
李春旺
陈诗颖
郑琳潇
郑子涵
张庆保
王崧仁
杨峥
赵化硕
郭思远
王俊博
司景瑞
邢梓珺
高婕
高敬一
王艺霏
李越洋
祝佳琪
房一诺
管晓涵
赵嘉
张正宇
郭旭彪
王子峥
王守轩
唐玉翔
舒文博
芦慧瑶
李民宇
李宁
李艾欣
曾庆鹤
付晴
尹志远
551.5
542
539
533
531.5
529.5
527
523.5
523
523
523
522.5
521.5
521.5
520.5
520.5
520.5
516.5
514.5
514
514
514
512.5
512
510.5
510.5
510
508
509.5
508
508
506
505.5
502.5
501
499.5
499
498.5
498
496
493.5
492
491.5
491
491
488.5
488
487.5
484.5
484.5
484
483
481.5
481.5
481
479


*/