// https://leetcode.com/problems/maximum-product-subarray/

#include <algorithm>
#include <iostream>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

// O(n)
int maxProduct_dp(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        dp[i] = dp[i - 1];
        int t = 1;
        for (int j = i; j >= 0; j--)
        {
            t *= nums[j];
            dp[i] = max(dp[i], t);
        }
    }

    return dp.back();
}

// O(n)
int maxProduct_fast(vector<int> &nums)
{
    int frontProduct = 1;
    int backProduct = 1;
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        frontProduct *= nums[i];
        backProduct *= nums[nums.size() - i - 1];
        ans = max(ans, max(frontProduct, backProduct));
        frontProduct = frontProduct == 0 ? 1 : frontProduct;
        backProduct = backProduct == 0 ? 1 : backProduct;
    }
    return ans;
}

int main()
{
    vector<int> a{2, 3, -2, 4};
    cout << maxProduct_fast(a) << endl;
    cout << maxProduct_dp(a) << endl;

    cout << endl;
    vector<int> a2{-2, 0, -1};
    cout << maxProduct_fast(a2) << endl;
    cout << maxProduct_dp(a2) << endl;

    cout << endl;
    vector<int> a3{-2};
    cout << maxProduct_fast(a3) << endl;
    cout << maxProduct_dp(a3) << endl;

    cout << endl;
    vector<int> a4{-5, 2, 4, 1, -2, 2, -6, 3, -1, -1, -1, -2, -3, 5, 1, -3, -4, 2, -4, 6, -1, 5, -6, -1, -1, -1, -1};
    cout << maxProduct_fast(a4) << endl;
    cout << maxProduct_dp(a4) << endl;

    getchar();

    return 0;
}