// https://leetcode.com/problems/rotate-array/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
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

void rotate(vector<int> &nums, int k)
{
    
}

int main()
{
    vector<int> a{1, 2, 3, 4, 5, 6, 7};
    rotate(a, 3);
    printVector<int>(a);

    getchar();
    return 0;
}
