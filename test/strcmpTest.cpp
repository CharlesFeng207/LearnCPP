// #include <float.h>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    cout << strcmp("asd", "asd") << endl;
    cout << strcmp("asd2", "asd") << endl;
}

int strcmp(const char *s1, const char *s2)
{
    while (*s1++ == *s2++)
    {
        if (*s1 == '/0')
            break;
    }

    return (*s1 - *s2);
}