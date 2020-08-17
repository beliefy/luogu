#include <bits/stdc++.h>
using namespace std;
const double esp = 1e-8;
double H, h, d, ans;

double f(double x, double y)
{ 
    double l = x, r = y, midl, midr;
    while (l <r- esp)
    { 
        midl = (r + l)/2, midr = (r + midl) /2;
        if ((d - midl + H - (H - h) * d / midl) >= (d - midr + H - (H - h) * d / midr))
            r = midr;
        else
            l = midl;
    }
    return d - r + H - (H - h) * d / r;
}

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        scanf("%lf%lf%lf", &H, &h, &d);
        ans = f(d - h * d / H, d);
        printf("%.3f\n", ans);
    }

    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> parent of 7c8312c... 整理
