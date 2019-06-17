#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string to_manache_string(string &s, string c)
{
    string result = c;

    for (auto &sc : s)
        result += sc + c;

    return result;
}

string longestPalindrome(string s)
{
    if (s.size() == 0)
        return 0;

    auto manacheStr = to_manache_string(s, "#");
    vector<int> radius(s.size(), 0);
    
    int R, C, p1;

    for (int i = 0; i < s.size(); i++)
    {
    }

    return manacheStr;
}

int main()
{
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome("xaaababaaahs") << endl;
    getchar();
    return 0;
}