#include <cstdio>
#include <vector>
using namespace std;
vector<int> post, mid, level(100000, -1);
void pre(int root, int start, int end, int index)
{
    if (start > end)
        return;
    int i = start;
    while (i < end && mid[i] != post[root])
        i++;
    level[index] = post[root];
    pre(root - 1 - (end - i), start, i - 1, index * 2 );
    pre(root - 1, i + 1, end, index * 2 + 1);
}
int main(void)
{
    int n, cnt = 0;
    scanf("%d", &n);
    post.resize(n);
    mid.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &mid[i]);
    pre(n - 1, 0, n - 1, 1);
    for (int i = 1; i <=level.size(); i++)
    {
        if (level[i] != -1 && cnt != n-1 )
        {
            printf("%d ", level[i]);
            cnt++;
        }
        else if (level[i] != -1)
        {
            printf("%d", level[i]);
            break;
        }
    }
    return 0;
}