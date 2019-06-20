// https://leetcode.com/problems/coin-change/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

template <class T>
void printVector(vector<T> &v)
{
    cout << "[";

    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            cout << v[i] << ", ";
        }
        else
        {
            cout << v[i] << "]" << endl;
        }
    }
}

int coinChange_dp(vector<int> &coins, int amount)
{
    if (amount <= 0)
        return 0;

    vector<int> dp(amount + 1, -1);

    int coinCount = 0;
    for (auto &c : coins)
    {
        if (c <= amount)
        {
            dp[c] = 1;
            coinCount++;
        }
    }

    if (coinCount == 0)
        return -1;

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        int t = -1;

        for (int j = 0; j < i; j++)
        {
            auto &a = dp[j];
            auto &b = dp[i - j];

            if (a == -1 || b == -1)
                continue;

            int len = a + b;

            if (t == -1)
            {
                t = len;
            }
            else
            {
                t = min(t, len);
            }
        }

        dp[i] = t;
    }

    return dp[amount];
}

void test_case(vector<int> &coins, int amount)
{
    int t = clock();
    printVector<int>(coins);
    cout << "amount: " << amount << endl;
    cout << "dp: " << coinChange_dp(coins, amount) << " cost " << clock() - t << "ms" << endl;
    cout << "end" << endl;
    cout << endl;
}

int main()
{
    vector<int> a1{1, 5, 2};
    test_case(a1, 11);

    vector<int> a2{2};
    test_case(a2, 1);
    test_case(a2, 3);

    vector<int> a3{1, 2147483647};
    test_case(a3, 2);

    vector<int> a4{3, 7, 405, 436};
    test_case(a4, 8839);

    vector<int> a5{261, 411, 27, 78, 61};
    test_case(a5, 5456);

    vector<int> a6{436, 83, 210, 75, 286};
    test_case(a6, 3165);

    getchar();

    return 0;
}