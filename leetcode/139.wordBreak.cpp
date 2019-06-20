// https://leetcode.com/problems/house-robber/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// O(n)
bool wordBreak(string s, vector<string> &wordDict)
{
    vector<int> wordIndex(wordDict.size(), 0);

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        bool b = true;
        for (int j = 0; j < wordDict.size(); j++)
        {
            string &w = wordDict[j];
            int &wi = wordIndex[j];
            
            if(c == w[wi])
            {
                b = false;
                wi = (wi + 1) % w.size();
            }
        }

        if (b)
            return false;
    }

    bool result = all_of(wordIndex.begin(), wordIndex.end(), [](int &a) { return a == 0; });

    return result;
}

int main()
{
    vector<string> a1{"leet", "code"};
    cout << wordBreak("leetcode", a1) << endl;

    vector<string> a2{"apple", "pen"};
    cout << wordBreak("applepenapple", a2) << endl;


    vector<string> a3{"cats", "dog", "sand", "and", "cat"};
    cout << wordBreak("catsandog", a3) << endl;

    // vector<string> a4{"cats", "dog", "sand", "and", "cat"};
    // cout << wordBreak("catsandog", a3) << endl;

    getchar();
    return 0;
}