#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int maxSubArray_DP(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    if (nums.size() == 1)
        return nums[0];

    vector<int> P(nums.size(), 0);

    int maxSum = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0)
        {
            P[0] = nums[0];
        }
        else
        {
            P[i] = nums[i] + max(P[i - 1], 0);
        }

        maxSum = max(maxSum, P[i]);
    }

    return maxSum;
}

int maxSubArray_Fast(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    int t, maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (t < 0)
        {
            t = nums[i];
        }
        else
        {
            t += nums[i];
        }

        maxSum = max(t, maxSum);
    }

    return maxSum;
}

int main()
{
    vector<int> a{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << maxSubArray_DP(a) << endl;
    cout << maxSubArray_Fast(a) << endl;

    getchar();
    return 0;
}