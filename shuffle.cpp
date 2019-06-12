#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void shuffle(int *a, int len)
{
    if (len <= 0)
        return;

    for (int i = 0; i < len; i++)
    {
        int r = i + rand() % (len - i);
        swap(a[i], a[r]);
    }
}

int main()
{
    int len = 7;
    int a[] = {1, 2, 3, 4, 5, 6, 7};

    shuffle(a, len);

    for (int i = 0; i < len; i++)
    {
        cout << a[i] << endl;
    }

    getchar();
}