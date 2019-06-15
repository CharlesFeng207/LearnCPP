#include <deque>
#include <functional>
#include <iostream>
#include <stack>
#include <string>
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

template <class T, class Y>
vector<Y> select(vector<T> &v, function<Y(T &)> func)
{
    vector<Y> t;
    for (auto &i : v)
    {
        t.emplace_back(func(i));
    }

    return t;
}

template <class T>
vector<T> where(vector<T> &v, function<bool(T &)> func)
{
    vector<T> t;
    for (auto &i : v)
    {
        if (func(i))
        {
            t.emplace_back(i);
        }
    }

    return t;
}

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    // v1.erase(0);
    printVector<int>(v1);

    vector<float> v2{9.9, 10.0};
    v2.push_back(1.2);
    v2.push_back(2.5);
    printVector<float>(v2);

    vector<vector<int>> v3{{2}, {3}};
    v3.push_back(v1);
    v3.push_back(v1);
    v3.pop_back();

    deque<int> q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    cout << q.front() << endl;
    cout << q.front() << endl;

    q.pop_front();
    cout << q.front() << endl;

    stack<int> s;
    s.push(1);
    // printVector(v3);

    cout << "assign(v1.begin(), v1.end());" << endl;
    vector<int> v4;
    v4.assign(v1.begin(), v1.begin() + 2);
    vector<int> v5(v1.begin(), v1.end() - 1);
    printVector(v4);
    printVector(v5);

    cout << "vector<vector<int>>(10)" << endl;
    vector<int> v6(10, 6);
    printVector(v6);

    cout << "linq where" << endl;
    auto v7 = where<int>(v1, [](int &i) { return i > 3; });
    printVector(v7);

    cout << "linq select" << endl;
    auto v8 = select<int, string>(v7, [](int &i) { return to_string(i) + "x"; });
    printVector(v8);
    getchar();
}
