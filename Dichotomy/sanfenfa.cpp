#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
int n;
double a[15], L, R, midl, midr, k;
double f(double x)
{
    double ret = 0;
    for (int i = n; i >= 0; i--)
        ret = ret * x + a[i];
    return ret;
}
int main()
{
    cin>>n>>L>>R;
    for (int i = n; i >= 0; i--)
        scanf("%lf", &a[i]);
    while (R - L >= eps)
    {
        k = (R - L) / 3.0;
        midl = L + k, midr = R - k;
        if (f(midl) > f(midr))
            R = midr;
        else
            L = midl;
    }
    printf("%.5lf\n", L);
    return 0;
}