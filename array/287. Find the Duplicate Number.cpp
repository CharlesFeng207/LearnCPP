// https://leetcode.com/problems/find-the-duplicate-number/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <class T>
void printVector(vector<T> &vector)
{
    cout << "[";

    int size = vector.size();
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            cout << vector[i] << ", ";
        }
        else
        {
            cout << vector[i] << "]" << endl;
        }
    }
}

int findDuplicate(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    int sum = 0;
    int max_value = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        max_value = max(max_value, nums[i]);
    }

    int sum2 = max_value + max_value * (max_value - 1) / 2;
    int result = (sum - sum2) / (nums.size() - max_value);
    return result;
}

int main()
{
    vector<int> a{1, 4, 4, 2, 4};
    // vector<int> a{1, 3, 4, 2, 2};
    auto c = clock();

    auto t = findDuplicate(a);
    cout << clock() - c << " ms" << endl;

    cout << t << endl;

    getchar();

    return 0;
}