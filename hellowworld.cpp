// #include <float.h>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

int main()
{
    float ff = 1.2;
    int a = 1;

    cout << string("Hello") + "World!" << a << " " << ff << endl;

    while (true)
    {
        static int i = 0;
        system("cls");
        cout << i++ << endl;
        sleep(0.5f);
    }

    getchar();
}