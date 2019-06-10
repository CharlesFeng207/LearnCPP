#include <iostream>
#include <string>

using namespace std;

int main()
{
    auto *ps = new string("Memory Management");
    cout << "size() " << ps->size() << endl;
    cout << "sizeof() " << sizeof(*ps) << endl;

    cout << "delete" << endl;

    delete ps;
    cout << "size() " << ps->size() << endl;
    cout << "sizeof() " << sizeof(*ps) << endl;

    string s = "123";

    for (int i = 0; i < s.length(); i++)
        cout << s[i] << endl;

    cout << "------------" << endl;

    cout << s.size() << endl;
    cout << s.length() << endl;

    if (s.find("32") == string::npos)
        cout << "not found" << endl;

    cout << s + "xx" << endl;

    int t = stoi(s);
    cout << t << endl;

    getchar();
}