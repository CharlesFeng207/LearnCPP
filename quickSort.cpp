#include <iostream>
#include <time.h>
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

void Qsort(vector<int> &arr, int low, int high)
{
    if (high <= low)
        return;
        
    int i = low;
    int j = high + 1;
    int key = arr[low];
    while (true)
    {
        /*从左向右找比key大的值*/
        while (arr[++i] < key)
        {
            if (i == high)
            {
                break;
            }
        }
        /*从右向左找比key小的值*/
        while (arr[--j] > key)
        {
            if (j == low)
            {
                break;
            }
        }
        if (i >= j)
            break;
        /*交换i,j对应的值*/
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    /*中枢值与j对应值交换*/
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    Qsort(arr, low, j - 1);
    Qsort(arr, j + 1, high);
}
void quickSort(vector<int> &a)
{
}

void test(vector<int> &a)
{
    int start = clock();
    Qsort(a, 0, a.size() - 1);
    cout << clock() - start << endl;
}

int main()
{
    vector<int> v;
    for (int i = 10000; i >= 0; i--)
        v.push_back(i);

    vector<int> v2;
    for (int i = 10000; i >= 0; i--)
        v2.push_back(rand());

    test(v);
    test(v2);

    cout << v[0];
    // printVector<int>(v);

    getchar();
}