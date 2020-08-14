#include <bits/stdc++.h>

using namespace std;
const int N = 100;
int nums[N];
int n;

int binary_search(int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] == target)
        {
            // 直接返回
            return mid;
        }
    }
    // 直接返回
    return -1;
}

// int left_bound(int target)
// {
//     int left = 0, right = n - 1;
//     while (left <= right)
//     {
//         int mid = left + (right - left) / 2;
//         if (nums[mid] < target)
//         {
//             left = mid + 1;
//         }
//         else if (nums[mid] >= target)
//         {
//             right = mid - 1;
//         }
//         else if (nums[mid] == target)
//         {
//             // 别返回，锁定左侧边界
//             right = mid - 1;
//         }
//     }
//     // 最后要检查 left 越界的情况
//     if (left >= n || nums[left] != target)
//         return -1;
//     return left;
// }

int left_bound(int target)
{
    if (n == 0)
        return -1;
    int left = 0, right = n;

    while (left < right)
    { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int right_bound(int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] == target)
        {
            // 别返回，锁定右侧边界
            left = mid + 1;
        }
    }
    // 最后要检查 right 越界的情况
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    int x;
    cin >> x;
    cout << binary_search(x) << endl;
    return 0;
}
