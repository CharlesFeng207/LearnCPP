#include <iostream>
#include <string>
#include <vector>

using namespace std;

string join(const vector<string> &v, string c)
{
    string s;

    for (auto p = v.begin();
         p != v.end(); ++p)
    {
        s += *p;
        if (p != v.end() - 1)
            s += c;
    }

    return s;
}

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

    vector<string> v{"Hello, ", " Cruel ", "World!"};

    string st;
    for (const auto &piece : v)
        st += piece;

    cout << st << endl;

    cout << join(v, "^") << endl;

    getchar();
}