#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<string> s;
    s.insert("asd");
    s.insert("asd1");
    s.insert("asd");
    s.insert("asd2");

    for (set<string>::iterator i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " " << endl;
    }

    cout << endl;

    set<string>::iterator iter = s.find("asd");
    if (iter != s.end())
    {
        cout << "666 " << *iter << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    getchar();
}