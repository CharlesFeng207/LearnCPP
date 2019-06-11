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

/* 
This function takes three parameters:  
1. String  
2. Starting index of the string  
3. Ending index of the string. */
void permute(char *a, int l, int r)
{
    int i;
    if (l == r)
        cout << a << endl;
    else
    {
        for (i = l; i <= r; i++)
        {
            iter_swap((a + l), (a + i));
            permute(a, l + 1, r);
            iter_swap((a + l), (a + i)); //backtrack
        }
    }
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

    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n - 1);

    delete v;
    delete vv;

    getchar();
}