#include <deque>
#include <iostream>
#include <stack>
#include <string>
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

    getchar();
}
