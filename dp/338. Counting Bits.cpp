// https://leetcode.com/problems/counting-bits/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> countBits(int num)
{
    int c; // c 用来保存结果

    for (c = 0; num; num >>= 1)
    {
        c += num & 1;
    }
}

int main()
{
    cout << countBits(2) << endl;
    getchar();
    return 0;
}