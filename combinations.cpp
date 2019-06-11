#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
void printVector(vector<T> vector)
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

template <typename T>
void combine_inner(T &data, int start, int n, int m,
                   int depth, T temp, vector<T> &result)
{
    if (depth == m - 1)
    {
        //最内层循环 将temp加入result
        for (int i = start; i < n - (m - depth - 1); ++i)
        {
            temp[depth] = data[i];
            result.emplace_back(temp);
        }
    }
    else
        for (int i = start; i < n - (m - depth - 1); ++i)
        {
            temp[depth] = data[i]; //每层输出一个元素
            combine_inner(data, i + 1, n, m, depth + 1, temp, result);
        }
}

//T可以调入vector<int>, string等，需要支持下标[]操作及size()函数
template <typename T>
vector<T> combine(T &data, int m)
{
    if (m <= 0)
        return {};

    int depth = 0;
    vector<T> result;
    T t(m);
    combine_inner(data, 0, data.size(), m, depth, t, result);
    
    return move(result);
}

int main()
{
    cout << "test_combination" << endl;

    auto v = new vector<int>{1, 3, 2, 1};

    auto result = combine<vector<int>>(*v, 2);
    for_each(result.begin(), result.end(), [](vector<int> &t) {
        printVector<int>(t);
    });

    delete v;
    getchar();
}