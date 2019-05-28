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

    vector<float> v2;
    v2.push_back(1.2);
    v2.push_back(2.5);
    printVector<float>(v2);

    getchar();
}
