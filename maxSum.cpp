#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxSum(vector<vector<int>> &a, int rowIndex, int colIndex)
{
    static vector<vector<int>> cache(a.size(), vector<int>(a.size(), -1));

    if (cache[rowIndex][colIndex] != -1)
    {
        return cache[rowIndex][colIndex];
    }
    else
    {
        if (rowIndex == a.size() - 1)
        {
            return a[rowIndex][colIndex];
        }
        else
        {
            int left = a[rowIndex][colIndex] + maxSum(a, rowIndex + 1, colIndex);
            int right = a[rowIndex][colIndex] + maxSum(a, rowIndex + 1, colIndex + 1);
            int result = max(left, right);
            cache[rowIndex][colIndex] = result;
            return result;
        }
    }
}

int main()
{
    // Create numeric triangle
    int row = 30;

    vector<vector<int>> a;
    for (int i = 0; i < row; i++)
    {
        auto v = &a.emplace_back();
        for (int j = 0; j < row; j++)
        {
            v->push_back(j <= i ? rand() % 10 : 0);
        }
    }

    // Display
    for (auto &i : a)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << "maxSum:" << maxSum(a, 0, 0) << endl;
    getchar();
}