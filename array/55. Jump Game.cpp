// https://leetcode.com/problems/jump-game/

#include <algorithm>
#include <iostream>
#include <list>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums)
{
    if (nums.size() < 2)
        return true;

    unordered_set iset{0};

    for (int i = 0; i < nums.size(); i++)
    {
        if (iset.find(i) != iset.end())
        {
            for (int j = nums[i]; j > 0 && i + j < nums.size(); j--)
            {
                if (i + j == nums.size() - 1)
                    return true;

                iset.insert(i + j);
            }
        }
    }

    return false;
}

int main()
{

    vector<int> a{2, 0};
    // vector<int> a{2, 3, 1, 1, 4};

    cout << canJump(a);

    getchar();

    return 0;
}