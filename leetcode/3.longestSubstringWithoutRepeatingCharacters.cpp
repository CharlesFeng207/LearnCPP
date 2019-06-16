#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.size() <= 1)
        return s.size();

    unordered_map<char, int> map; // Char -> index

    int curLen = 0;
    int maxLen = 0;
    int start = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (map.find(s[i]) != map.end() && map[s[i]] >= start)
        {
            start = map[s[i]] + 1;
            curLen = i - start + 1;
        }
        else
        {
            curLen++;
        }

        map[s[i]] = i;
        maxLen = max(maxLen, curLen);
    }

    return maxLen;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    cout << lengthOfLongestSubstring("bbbbb") << endl;
    cout << lengthOfLongestSubstring("dvdf") << endl;
    getchar();
    return 0;
}