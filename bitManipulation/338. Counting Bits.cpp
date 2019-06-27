// https://leetcode.com/problems/counting-bits/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>
void printVector(vector<T> v)
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

vector<int> countBits(int num)
{
    static vector<int> dp(1, 0);

    while (dp.size() < num + 1)
    {
        int t = dp.size();
        dp.push_back((t & 1) + dp[t >> 1]);
    }

    return vector<int>(dp.begin(), dp.begin() + num + 1);
}

int main()
{
    printVector<int>(countBits(2));
    printVector<int>(countBits(5));
    printVector<int>(countBits(10));

    getchar();
    return 0;
}