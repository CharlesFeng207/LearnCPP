// https://leetcode.com/problems/subsets/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>
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

void subset_inner(vector<int> &nums, int i, vector<int> &buffer, vector<vector<int>> &result)
{
    buffer.push_back(nums[i]);
    result.push_back(buffer);

    for (int j = i + 1; j < nums.size(); j++)
    {
        vector<int> buffer2 = buffer;
        subset_inner(nums, j, buffer2, result);
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    result.push_back({});
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> buffer;
        subset_inner(nums, i, buffer, result);
    }

    return result;
}

int main()
{
    // vector<int> a{1, 2, 3, 4};
    vector<int> a{1, 2, 3, 4};
    auto c = clock();

    auto t = subsets(a);
    cout << clock() - c << " ms" << endl;

    for (auto &v : t)
        printVector<int>(v);

    getchar();

    return 0;
}