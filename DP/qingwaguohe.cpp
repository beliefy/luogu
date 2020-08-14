#include <iostream>
using namespace std;
int h, k, ans = 0;
int main()
{
    cin >> h >> k;
    ans = k + 1;
    while (h--)ans <<= 1;
    cout << ans << endl;
    return 0;
}