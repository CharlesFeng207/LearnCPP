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
void inner_permutations(T &v, int l, int r, vector<T> &result)
{
    int i;
    if (l == r)
        result.emplace_back(v);
    else
    {
        for (i = l; i <= r; i++)
        {
            swap(v[l], v[i]);

            inner_permutations(v, l + 1, r, result);

            swap(v[l], v[i]); //backtrack
        }
    }
}

/* 
This function takes three parameters:  
1. vector  
2. Starting index of the vector  
3. Ending index of the vector. */
template <typename T>
vector<T> permutations(T &v)
{
    auto result = vector<T>();
    inner_permutations(v, 0, v.size()-1, result);
    return result;
}

int main()
{
    cout << "next_permutation (must perform in a sorted vector)" << endl;

    auto vv = new vector<int>{1, 2, 3};
    auto v = new vector<int>(*vv);

    do
    {
        printVector<int>(*v);
    } while (next_permutation(v->begin(), v->end()));

    cout << "recursive permutation vector<int>" << endl;

    auto v2 = vector<int>(*vv);

    auto result =
        permutations<vector<int>>(v2);

    for_each(result.begin(), result.end(), [](vector<int> &t) {
        printVector<int>(t);
    });

    cout << "recursive permutation string" << endl;

    char ca[] = "ABC";
    string str = ca;

   auto result2 = permutations<string>(str);
   for_each(result2.begin(), result2.end(), [](string &t) {
       cout << t << endl;
   });

   delete v;
   delete vv;

   getchar();
}