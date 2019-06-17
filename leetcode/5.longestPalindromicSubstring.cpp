#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string to_manache_string(string &s, char c)
{
    string result(1, c);

    for (auto &sc : s)
        result += sc + string(1, c);

    return result;
}

string longestPalindrome(string s)
{
    if (s.size() == 0)
        return "";

    auto addChar = '#';
    auto str = to_manache_string(s, addChar);
    int size = str.size();

    vector<int> radius(size, 0);

    int maxLen = 0;
    int maxLenIndex = 0;

    int R = -1;
    int C = 0;

    for (int p1 = 0; p1 < size; p1++)
    {
        int p2 = max(0, 2 * C - p1); // p2 = C - (p1 - C)
        int C_left = max(0, C - radius[C]);
        int p2_left = max(0, p2 - radius[p2]);

        if (p1 > R || p2_left == C_left)
        {
            int i = 0;
            while (p1 + i < size && p1 - i >= 0 && str[p1 + i] == str[p1 - i])
            {
                radius[p1] = ++i;
            }

            C = p1;
        }
        else
        {
            if (p2_left > C_left)
            {
                radius[p1] = radius[p2];
            }
            else if (p2_left < C_left)
            {
                radius[p1] = C_left - p2_left + 1;
            }
        }

        if (radius[p1] > maxLen)
        {
            maxLen = radius[p1];
            maxLenIndex = p1;
        }
    }

    string result = "";
    for (int i = -maxLen + 1; i < maxLen; i++)
    {
        if (str[maxLenIndex + i] != addChar)
            result += str[maxLenIndex + i];
    }

    return result;
}

int main()
{
    cout << longestPalindrome("") << endl;
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome("xaaababaaahs") << endl;

    getchar();
    return 0;
}